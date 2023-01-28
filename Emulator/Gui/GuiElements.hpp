#pragma once

#include "../../Libraries/ImGUI/imgui.h"
#include "../../Libraries/ImGUI/imgui_internal.h"

namespace GuiElements 
{
    inline void TraceLog(const char* event, const char* message, bool colorize)
    {
        using namespace ImGui;

        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(message);

        ImVec2 pos = window->DC.CursorPos;

		const auto messageSize = CalcTextSize(message, NULL, true, ImGui::GetWindowSize().x - 180);
        const ImVec2 size = ImVec2(ImGui::GetWindowSize().x, 10 + messageSize.y);
        const ImRect bb(pos, pos + size);
        
        ItemSize(size, 0);
        ItemAdd(bb, id);

        bool hovered, held;
        ButtonBehavior(bb, id, &hovered, &held, NULL);
        
        window->DrawList->AddRectFilled(bb.Min, bb.Max, colorize ? IM_COL32(55, 55, 58, 255) : IM_COL32(45, 45, 48, 255));
        
        if (hovered) {
			window->DrawList->AddRectFilled(bb.Min, bb.Max, IM_COL32(75, 75, 78, 255));
        }

		window->DrawList->AddText(bb.Min + ImVec2{ 10, 4 }, IM_COL32(255, 255, 255, 255), event);
		window->DrawList->AddText(nullptr, 16, bb.Min + ImVec2{180, 4}, IM_COL32(255, 255, 255, 255), message, NULL, size.x - 180);
	}
}