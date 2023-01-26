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
	
	/* fill the render table */
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

void CTablesSystem::InitializeRageBot()
{
	/* Initialize new table for ragebot*/
	auto tRagebot = g_EmulatorEngine.m_LuaState.create_named_table("ragebot");

	/* fill the ragebot table */
	tRagebot["ignore_player"] = Ragebot::IgnorePlayer;
	tRagebot["override_wall_penetration"] = Ragebot::OverrideWallPenetration;
	tRagebot["override_desync_correction"] = Ragebot::OverrideDesyncCorrection;
	tRagebot["override_hitscan"] = Ragebot::OverrideHitScan;
	tRagebot["override_skip_unsafe_points"] = Ragebot::OverrideSkipUnsafePoints;
	tRagebot["override_min_damage"] = Ragebot::OverrideMinDamage;
	tRagebot["override_safe_point"] = Ragebot::OverrideSafePoint;
	tRagebot["override_max_misses"] = Ragebot::OverrideMaxMisses;
	tRagebot["override_head_scale"] = Ragebot::OverrideHeadScale;
	tRagebot["override_body_scale"] = Ragebot::OverrideBodyScale;
	
}

void CTablesSystem::InitializeSourceUtils()
{
	/* Initialize new table for se*/
	auto tSourceUtils = g_EmulatorEngine.m_LuaState.create_named_table("se");
	
	tSourceUtils["world_to_screen"] = SourceUtils::WorldToScreen;
	tSourceUtils["set_clantag"] = SourceUtils::SetClanTag;
	tSourceUtils["set_name"] = SourceUtils::SetName;
	tSourceUtils["get_convar"] = SourceUtils::GetConVar;
	tSourceUtils["get_netvar"] = SourceUtils::GetNetVar;
	tSourceUtils["get_latency"] = SourceUtils::GetLatency;
	tSourceUtils["create_interface"] = SourceUtils::CreateInterface;

}

void CTablesSystem::InitializeEngine()
{
	auto tEngine = g_EmulatorEngine.m_LuaState.create_named_table("engine");
	
	tEngine["get_screen_size"] = Engine::GetScreenSize;
	tEngine["is_connected"] = Engine::IsConnected;
	tEngine["is_in_game"] = Engine::IsInGame;
	tEngine["get_local_player"] = Engine::GetLocalPlayer;
	tEngine["get_player_info"] = Engine::GetPlayerInfo;
	tEngine["get_level_name_short"] = Engine::GetLevelNameShort;
	tEngine["get_player_for_user_id"] = Engine::GetPlayerForUserID;
	tEngine["set_view_angles"] = Engine::SetViewAngles;
	tEngine["get_view_angles"] = Engine::GetViewAngles;
	tEngine["execute_client_cmd"] = Engine::ExecuteClientCmd;


}
