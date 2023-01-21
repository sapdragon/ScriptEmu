#pragma once
/* The callback system is needed to call the necessary callbacks to simulate the entire script. */
#include "../EmulatorEngine.hpp"
class CCallbacksSystem
{
public:
	/* Enters the current function in the container */
	void RegisterCallBack(std::string sName, sol::function fCallback);

	/* Clears the callbacks for the next emulation */
	void ClearCallbacks();

	/* Get function from event*/
	sol::function GetFunction(std::string sName);

	/* Get all functions */
	std::unordered_map < std::string, sol::function > GetFunctions();
private:
	/* string - name of callback */
	std::unordered_map < std::string, sol::function > m_aCallbacks;
};

inline CCallbacksSystem g_CallBacksSystem;