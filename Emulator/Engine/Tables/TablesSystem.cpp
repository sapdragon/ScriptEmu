#include "../EmulatorEngine.hpp"

#include "CheatTables.hpp"

void CTablesSystem::InitializeClient()
{
	/* Initialize new table for client*/
	auto tClient = g_EmulatorEngine.m_LuaState.create_table();
	
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
	
	/* Push client table to state */
	g_EmulatorEngine.m_LuaState["client"] = tClient;

}
