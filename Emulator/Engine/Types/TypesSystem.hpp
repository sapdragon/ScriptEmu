#pragma once
struct GameEvent_t
{
	std::string GetName()
	{
		g_EmulatorEngine.WriteTrace("GameEvent::GetName");
		return "GameEvent";
	}

	bool GetBool(std::string sKeyName, bool bDefault = false)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::GetBool ( " + sKeyName + " )");
		return true;
	}

	int GetInt(std::string sKeyName, int iDefault = 0 )
	{
		g_EmulatorEngine.WriteTrace("GameEvent::GetInt ( " + sKeyName + " )");
		return 0;
	}

	float GetFloat(std::string sKeyName, float flDefault = 0.0f)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::GetFloat ( " + sKeyName + " )");
		return 0.0f;
	}

	std::string GetString(std::string sKeyName, std::string sDefault = "")
	{
		g_EmulatorEngine.WriteTrace("GameEvent::GetString ( " + sKeyName + " )");
		return "collectordev gay";
	}
	
	void SetBool(std::string sKeyName, bool bValue)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::SetBool ( " + sKeyName + "," + std::to_string(bValue) + ")");
	}
	
	void SetInt(std::string sKeyName, int iValue)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::SetInt ( " + sKeyName + "," + std::to_string(iValue) + ")");
	}

	void SetFloat(std::string sKeyName, float flValue)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::SetFloat ( " + sKeyName + "," + std::to_string(flValue) + ")");
	}

	void SetString(std::string sKeyName, const char* szValue)
	{
		g_EmulatorEngine.WriteTrace("GameEvent::SetString ( " + sKeyName + "," + szValue + ")");
	}

};

struct Convar_t
{
	int GetInt(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace("Convar::GetInt ( " + sConvarName + " )");
		return 0;
	}

	float GetFloat(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace("Convar::GetFloat ( " + sConvarName + " )");
		return 0.0f;
	}

	std::string GetString(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace("Convar::GetString ( " + sConvarName + " )");
		return "collectordev gay";
	}

	void SetInt(std::string sConvarName, int iValue)
	{
		g_EmulatorEngine.WriteTrace("Convar::SetInt ( " + sConvarName + "," + std::to_string(iValue) + ")");
	}

	void SetFloat(std::string sConvarName, float flValue)
	{
		g_EmulatorEngine.WriteTrace("Convar::SetFloat ( " + sConvarName + "," + std::to_string(flValue) + ")");

	}

	void SetString(std::string sConvarName, std::string sValue)
	{
		g_EmulatorEngine.WriteTrace("Convar::SetString ( " + sConvarName + "," + sValue + ")");
	}
};

class CTypesSystem
{
public:
	/* Initializes the math types */
	void InitializeMath();
	
	/* Initializes the source engine types */
	void InitializeGame();
};

inline CTypesSystem g_TypesSystem;