#include "EmulatorEngine.hpp"

void CEmulatorEngine::InitializeEngine()
{
	/* Adding the standard libraries, note: I should also add FFI here, but so far I don't know how to trace it.*/
	m_LuaState.open_libraries(sol::lib::bit32, sol::lib::math, sol::lib::string, sol::lib::utf8);

	/* Remove all unnecessary trash. */
	m_LuaState[("collectgarbage")] = sol::nil;
	m_LuaState[("dofilsse")] = sol::nil;
	m_LuaState[("load")] = sol::nil;
	m_LuaState[("loadfile")] = sol::nil;
	m_LuaState[("pcall")] = sol::nil;
	m_LuaState[("print")] = sol::nil;
	m_LuaState[("xpcall")] = sol::nil;
	m_LuaState[("getmetatable")] = sol::nil;
	m_LuaState[("setmetatable")] = sol::nil;
	m_LuaState[("__nil_callback")] = []() {};

	/* Initialize lua types*/
	InitializeTypes();

	/* Initialize lua tables */
	InitializeTables();
}

void CEmulatorEngine::EmulateScript(const std::string& sPath)
{
	sol::environment Environment(m_LuaState, sol::create, m_LuaState.globals());

	bool bErrorInLoad = false;

	m_sCallBackName = "Main";

	m_LuaState.script_file(sPath, Environment, 
		[&bErrorInLoad, &Environment](lua_State*, sol::protected_function_result Result)
		{
			if (!Result.valid())
			{
				sol::error Error = Result;

				printf(Error.what());

				bErrorInLoad = true;
				return Result;
			}
		}
	);

		
	if(bErrorInLoad)
		return;

	auto aFunctions = g_CallBacksSystem.GetFunctions();

	for (auto& pFunction : aFunctions)
	{
		m_sCallBackName = pFunction.first;

		auto Function = pFunction.second;

		if (Function.valid())
		{
			sol::protected_function_result Result;
			long lEventName = FNV1A(m_sCallBackName.c_str());

			if (lEventName == FNV1A("create_move"))
				Result = Function(UserCmd_t{});
			else if (lEventName == FNV1A("frame_stage_notify"))
				Result = Function(4);
			else if (lEventName == FNV1A("fire_game_event"))
				Result = Function(GameEvent_t{});
			else if (lEventName == FNV1A("shot_fired"))
				Result = Function(ShotInfo_t{});
			else if (lEventName == FNV1A("override_view"))
				Result = Function(ViewSetup_t{});
			else
				Result = Function();


			if (!Result.valid())
			{
				sol::error Error = Result;

				printf(Error.what());
			}
		}
	}
}

void CEmulatorEngine::ClearData()
{
	/* Clear trace data */
	m_aTraceData.clear();

	/* Clear callbacks */
	g_CallBacksSystem.ClearCallbacks();
}

void CEmulatorEngine::WriteTrace(const std::string& sText)
{
	std::string sNewText = sText;

	// if sText contains 000000 replace it all with 0
	if (sText.find("000000") != std::string::npos)
	{
		std::string sReplace = "000000";
		std::string sReplaceWith = "0";

		size_t pos = 0;
		while ((pos = sNewText.find(sReplace, pos)) != std::string::npos)
		{
			sNewText.replace(pos, sReplace.length(), sReplaceWith);
			pos += sReplaceWith.length();
		}
	}

	// if sNewText contains " , " replace it all with ", "
	if (sNewText.find(" , ") != std::string::npos)
	{
		std::string sReplace = " , ";
		std::string sReplaceWith = ", ";

		size_t pos = 0;
		while ((pos = sNewText.find(sReplace, pos)) != std::string::npos)
		{
			sNewText.replace(pos, sReplace.length(), sReplaceWith);
			pos += sReplaceWith.length();
		}
	}

	m_aTraceData[m_sCallBackName].push_back(sNewText);
}

std::unordered_map<std::string, std::vector<std::string>> CEmulatorEngine::GetTraceData()
{
	return m_aTraceData;
}

void CEmulatorEngine::InitializeTypes()
{
	/* Initialize math types */
	g_TypesSystem.InitializeMath();

	/* Initialize render types */
	g_TypesSystem.InitializeRender();

	/* Initialize source engine types */
	g_TypesSystem.InitializeGame();
	
}

void CEmulatorEngine::InitializeTables()
{
	/* Initialize tables for client */
	g_TablesSystem.InitializeClient();

	/* Initialize tables for render */
	g_TablesSystem.InitializeRender();

	/* Initialize ragebot table */
	g_TablesSystem.InitializeRageBot();

	/* Initialize tables for source utils */
	g_TablesSystem.InitializeSourceUtils();
	
	/* Initialize engine table */
	g_TablesSystem.InitializeEngine();

	/* Initialize trace table */
	g_TablesSystem.InitializeTrace();
	
	/* Initialize globals vars table */
	g_TablesSystem.InitializeGlobalVars();
	
	/* initilalize clientstate table*/
	g_TablesSystem.InitializeClientState();

	/* Initialize entitylist table */
	g_TablesSystem.IntitializeEntityList();
}
