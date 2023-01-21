#pragma once


/* Client table ( ref: https://api.nixware.cc/client/ ) */

namespace Client
{
	inline void LoadScript(std::string sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::LoadScript ( " + sScriptName + " )");
	}

	inline void UnloadScript(std::string sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::UnloadScript ( " + sScriptName + " )");
	}

	inline std::string GetScriptName()
	{
		g_EmulatorEngine.WriteTrace("Client::GetScriptName");

		return "scriptemu.lua";
	}

	inline void RegisterCallBack(std::string sName, sol::function fCallback)
	{
		g_EmulatorEngine.WriteTrace("Client::RegisterCallBack ( " + sName + " )");
		return g_CallBacksSystem.RegisterCallBack(sName, fCallback);
	}

	inline std::string GetUsername()
	{
		g_EmulatorEngine.WriteTrace("Client::GetUsername");

		return "sapdragon";
	}

	inline void Notify(std::string sMessage)
	{
		g_EmulatorEngine.WriteTrace("Client::Notify ( " + sMessage + " )");
	}
	
	inline int GetTimeStamp()
	{
		g_EmulatorEngine.WriteTrace("Client::GetTimeStamp");

		return 0xDEADFEED;
	}

	inline std::tuple < int, int, int> GetSystemTime()
	{
		g_EmulatorEngine.WriteTrace("Client::GetSystemTime");

		return std::make_tuple(0, 1, 2);
	}

	inline int FindPattern(std::string sModule, std::string sPattern)
	{
		g_EmulatorEngine.WriteTrace("Client::FindPattern ( " + sModule + " , " + sPattern + " )");

		return 0xC001C0DE;
	}

	
	
	

}