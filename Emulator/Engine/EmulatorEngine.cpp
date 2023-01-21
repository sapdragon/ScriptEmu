#include "EmulatorEngine.hpp"

void CEmulatorEngine::InitializeEngine()
{
	m_LuaState = sol::state();

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
	
}

void CEmulatorEngine::EmulateScript(const std::string& sData)
{
	sol::environment Environment(m_LuaState, sol::create, m_LuaState.globals());

	bool bErrorInLoad = false;

	m_sCallBackName = "Main";

	m_LuaState.script(sData, Environment, [&bErrorInLoad, &Environment](lua_State*, sol::protected_function_result Result)
		{
			if (!Result.valid())
			{
				sol::error Error = Result;

				printf(Error.what());

				bErrorInLoad = true;
				return Result;
			}
		});

		
	if(bErrorInLoad)
		return;

	auto aFunctions = g_CallBacksSystem.GetFunctions();

	for (auto& pFunction : aFunctions)
	{
		m_sCallBackName = pFunction.first;

		auto Function = pFunction.second;

		if (Function.valid())
		{
			sol::protected_function_result Result = Function();

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
	m_aTraceData[m_sCallBackName].push_back(sText);
}

void CEmulatorEngine::InitializeTypes()
{
	/* Initialize math types*/
	g_TypesSystem.InitializeMath();

	/* Initialize source engine types */
	g_TypesSystem.InitializeGame();
}

void CEmulatorEngine::InitializeTables()
{
	/* Initialize tables for client */
	g_TablesSystem.InitializeClient();
}
