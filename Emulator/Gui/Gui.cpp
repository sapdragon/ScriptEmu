#include "Gui.hpp"
#include "../../Emulator/Engine/EmulatorEngine.hpp"
#include "../Gui/GuiElements.hpp"
#include "../../Libraries/ImGUI/imgui_impl_dx9.h"
#include "../../Libraries/ImGUI/imgui_impl_win32.h"

#include "../../Includes/Fonts/faprolight.hpp"
#include "../../Includes/Fonts/roboto.hpp"
#include "../../Includes/Fonts/hashes.h"

void CEmuGUI::Render()
{
    wc = { sizeof(WNDCLASSEX), CS_CLASSDC, g_EmuGui->WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "ScriptEmu", NULL };
    RegisterClassExA(&wc);
    hwnd = ::CreateWindow(wc.lpszClassName, "ScriptEmu", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);

        return;
    }

    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    ImGui::CreateContext();

    SetupStyles();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    bool done = false;
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
    
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        
        ImGui::NewFrame();
        UI();
        ImGui::EndFrame();

        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(15,15,15, 0), 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
}

void CEmuGUI::UI()
{
    auto flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;

	ImGui::Begin("Menu", nullptr, flags);
    {
        ImGui::SetWindowPos(ImVec2(0, 0));
        ImGui::SetWindowSize(ImVec2(250, ImGui::GetIO().DisplaySize.y));

		auto draw = ImGui::GetWindowDrawList();
		auto pos = ImGui::GetWindowPos();
		auto size = ImGui::GetWindowSize();

		draw->AddRectFilled(pos, pos + size, IM_COL32(35, 35, 38, 255));
    }
	ImGui::End();

    ImGui::Begin("Trace Log", nullptr, flags);
    {
        ImGui::SetWindowPos(ImVec2(250, 0));
        ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x - 250, ImGui::GetIO().DisplaySize.y));

        auto draw = ImGui::GetWindowDrawList();
        auto pos = ImGui::GetWindowPos();
        auto size = ImGui::GetWindowSize();

        draw->AddRectFilled(pos, pos + size, IM_COL32(25, 25, 28, 255));
        draw->AddRectFilled(pos, pos + ImVec2(size.x, 25), IM_COL32(65, 65, 68, 255));
        
        draw->AddText(pos + ImVec2(10, 5), IM_COL32(255, 255, 255, 255), "Event");
        draw->AddText(pos + ImVec2(180, 5), IM_COL32(255, 255, 255, 255), "Call");

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
        ImGui::SetCursorPos({ 0, 25 });
        ImGui::BeginChild("Tracing Log", ImGui::GetWindowSize() - ImVec2(0, 25));
        auto iter = 1;
        for (auto& aEventMessages : g_EmulatorEngine.GetTraceData())
        {
            for (auto& sMessage : aEventMessages.second)
            {
                GuiElements::TraceLog(aEventMessages.first.c_str(), sMessage.c_str(), iter % 2 == 0);
				iter++;
            }
        }
		ImGui::EndChild();
		ImGui::PopStyleVar();
			
        draw->AddLine(pos + ImVec2(170, 25), pos + ImVec2(170, size.y), IM_COL32(45, 45, 48, 255));
    }
    ImGui::End();
}

void CEmuGUI::SetupStyles()
{
    static const ImWchar ranges[] = {
        0x0020, 0x00FF, 0x2000, 0x206F,
        0x3000, 0x30FF, 0x31F0, 0x31FF,
        0xFF00, 0xFFEF, 0x4e00, 0x9FAF, 0x0400,
        0x052F, 0x2DE0, 0x2DFF, 0xA640, 0xA69F, 0
    };

    ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(regular_compressed_data, regular_compressed_size, 16, nullptr, ranges);

    static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF(faprolight, sizeof faprolight, 18, &icons_config, icon_ranges);
    
	ImGuiStyle& style = ImGui::GetStyle();

    style.WindowBorderSize = 0;
	style.WindowPadding = ImVec2(0, 0);
}

bool CEmuGUI::CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CEmuGUI::CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void CEmuGUI::ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    g_pd3dDevice->Reset(&g_d3dpp);
    ImGui_ImplDX9_CreateDeviceObjects();
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI CEmuGUI::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    HDROP hDrop;
    POINT pt;
    int cnt;
    char fileName[512];

    switch (msg)
    {
    case WM_CREATE:
        DragAcceptFiles(hWnd, TRUE);
        break;
    case WM_DROPFILES:
        hDrop = (HDROP)wParam;
        DragQueryPoint(hDrop, &pt);
        cnt = DragQueryFile(hDrop, 0xFFFFFFFF, 0, 0);

        for (int i = 0; i < cnt; i++)
        {
            DragQueryFileA(hDrop, i, fileName, 512);
            if (std::filesystem::path(fileName).extension() == ".lua")
            {
                std::thread([fileName] {
                    g_EmulatorEngine.ClearData();
                    g_EmulatorEngine.EmulateScript(fileName); 
                }).detach();
            }
        }

        DragFinish(hDrop);
        break;
    case WM_SIZE:
        if (g_EmuGui->g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_EmuGui->g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_EmuGui->g_d3dpp.BackBufferHeight = HIWORD(lParam);
            g_EmuGui->ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }

    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

