#pragma once

#include "../../Libraries/ImGUI/imgui.h"
#include "../../Libraries/ImGUI/imgui_internal.h"

#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <string>
#include <vector>

class CEmuGUI {
public:
	void Render();

private:
	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void ResetDevice();

	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	WNDCLASSEX wc;
	HWND hwnd;

	LPDIRECT3D9 g_pD3D = NULL;
	LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
	D3DPRESENT_PARAMETERS g_d3dpp = {};
};

inline auto g_EmuGui = new CEmuGUI();