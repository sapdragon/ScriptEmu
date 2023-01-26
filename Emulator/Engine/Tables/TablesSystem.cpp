#include "../EmulatorEngine.hpp"

#include "CheatTables.hpp"

void CTablesSystem::InitializeClient()
{
	/* Initialize new table for client*/
	auto tClient = g_EmulatorEngine.m_LuaState.create_named_table("client");
	

	/* Fill table */
	tClient["load_script"] = Client::LoadScript;
	tClient["unload_script"] = Client::UnloadScript;
	tClient["get_script_name"] = Client::GetScriptName;
	tClient["register_callback"] = Client::RegisterCallBack;
	tClient["get_username"] = Client::GetUsername;
	tClient["notify"] = Client::Notify;
	tClient["get_timestamp"] = Client::GetTimeStamp;
	tClient["get_system_time"] = Client::GetSystemTime;
	tClient["find_pattern"] = Client::FindPattern;
	
}

void CTablesSystem::InitializeRender()
{
	/* Initialize new table for render*/
	auto tRender = g_EmulatorEngine.m_LuaState.create_named_table("renderer");
	
	tRender["setup_font"] = Render::SetupFont;
	tRender["setup_texture"] = Render::SetupTexture;
	tRender["text"] = Render::RenderText;
	tRender["texture"] = Render::RenderTexture;
	tRender["get_text_size"] = Render::GetTextSize;
	tRender["get_cursor_pos"] = Render::GetCursorPos;
	tRender["line"] = Render::RenderLine;
	tRender["rect"] = Render::RenderRect;
	tRender["rect_filled"] = Render::RenderRectFilled;
	tRender["rect_filled_fade"] = Render::RenderRectFilledFade;
	tRender["circle_fade"] = Render::RenderCircleFade;
	tRender["circle"] = Render::RenderCircle;
	tRender["filled_polygon"] = Render::FilledPolygon;
}
