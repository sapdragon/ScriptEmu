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

void CTablesSystem::InitializeTrace()
{
	/* Initialize new table for trace*/
	auto tTrace = g_EmulatorEngine.m_LuaState.create_named_table("trace");

	tTrace["line"] = Trace::TraceLine;
	tTrace["hull"] = Trace::TraceHull;
}

void CTablesSystem::InitializeGlobalVars()
{
	/* Initialize new table for globalvars*/
	auto tGlobalVars = g_EmulatorEngine.m_LuaState.create_named_table("globalvars");

	tGlobalVars["get_real_time"] = GlobalVars::GetRealTime;
	tGlobalVars["get_frame_count"] = GlobalVars::GetFrameCount;
	tGlobalVars["get_absolute_frametime"] = GlobalVars::GetAbsoluteFrameTime;
	tGlobalVars["get_current_time"] = GlobalVars::GetCurrentTime;
	tGlobalVars["get_frame_time"] = GlobalVars::GetFrameTime;
	tGlobalVars["get_max_clients"] = GlobalVars::GetMaxClients;
	tGlobalVars["get_tick_count"] = GlobalVars::GetTickCount;
	tGlobalVars["get_interval_per_tick"] = GlobalVars::GetTickInterval;
}

void CTablesSystem::InitializeClientState()
{
	/* Initialize new table for clientstate */
	auto tClientstate = g_EmulatorEngine.m_LuaState.create_named_table("clientstate");
	
	tClientstate["get_choked_commands"] = ClientState::GetChokedCommands;
	tClientstate["force_full_update"] = ClientState::ForceFullUpdate;
}

void CTablesSystem::IntitializeEntityList()
{
	auto tEntityList = g_EmulatorEngine.m_LuaState.create_named_table("entitylist");

	tEntityList["get_highest_entity_index"] = Entitylist::GetHighestEntityIndex;
	tEntityList["get_local_player"] = Entitylist::GetLocalPlayer;
	tEntityList["get_entity_by_index"] = Entitylist::GetEntityByIndex;
	tEntityList["get_entity_from_handle"] = Entitylist::GetEntityFromHandle;
	tEntityList["get_players"] = Entitylist::GetPlayers;
	tEntityList["get_entities_by_class_name"] = Entitylist::GetEntitiesByClassName;
	tEntityList["get_entities_by_class_id"] = Entitylist::GetEntitiesByClassId;
}
