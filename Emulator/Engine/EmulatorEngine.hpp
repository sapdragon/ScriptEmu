#pragma once
/* LuaEngine is the main system in this emulator, it runs the execution of script in the lua environment, and fills it all in the file. */

/* Libs */
#include <sol.hpp>
#include <FNV1A.hpp>

/* Math */
#include "../Math/Math.hpp"

#include "Tables/TablesSystem.hpp"

class CEmulatorEngine
{
public:
	/* Initializes the engine, and tables for the lua api */
	void InitializeEngine();

	/* Starts the emulation process of the script */
	void EmulateScript(const std::string& sData);
	
	/* Clears information about the past emulation. */
	void ClearData();
	
	/* Write trace text */
	void WriteTrace(const std::string& sText);

	/* Getting trace data */
	std::unordered_map <std::string, std::vector < std::string > > GetTraceData();
private:
	/* Initializes all game types, is a subfunction of InitializeEngine */
	void InitializeTypes();
	/* Initializes all api tables, is a subfunction of InitializeEngine */
	void InitializeTables();

public:
	/* State of the lua engine */
	sol::state m_LuaState;

private:
	/* Tracing result. The first line is the name of the callback, the second vector is the set of lines */
	std::unordered_map <std::string, std::vector < std::string > > m_aTraceData;

	/* Current execute callback name */
	std::string m_sCallBackName;

};

inline CEmulatorEngine g_EmulatorEngine;

/* Emulator parts */
#include "Callbacks/CallbacksSystem.hpp"
#include "Types/TypesSystem.hpp"
