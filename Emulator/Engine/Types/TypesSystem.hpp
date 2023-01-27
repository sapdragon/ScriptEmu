#pragma once
#include <any>
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
	std::string m_sName;

	int GetInt(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::GetInt(" + sConvarName + ")");
		return 0;
	}

	float GetFloat(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::GetFloat ( " + sConvarName + " )");
		return 0.0f;
	}

	std::string GetString(std::string sConvarName)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::GetString ( " + sConvarName + " )");
		return "collectordev gay";
	}

	void SetInt(std::string sConvarName, int iValue)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::SetInt ( " + sConvarName + "," + std::to_string(iValue) + ")");
	}

	void SetFloat(std::string sConvarName, float flValue)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::SetFloat ( " + sConvarName + "," + std::to_string(flValue) + ")");

	}

	void SetString(std::string sConvarName, std::string sValue)
	{
		g_EmulatorEngine.WriteTrace(m_sName + "::SetString ( " + sConvarName + "," + sValue + ")");
	}
};

/* Color type ( ref: https://api.nixware.cc/types/color_t/ )  */
struct Color_t
{
	float r, g, b, a;

	Color_t(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color_t(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 1.f;
	}

	Color_t()
	{
		this->r = 0.f;
		this->g = 0.f;
		this->b = 0.f;
		this->a = 0.f;
	}



};



struct PlayerInfo_t
{
	void Set(sol::stack_object Key, sol::stack_object Value, sol::this_state)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			long iHashKey = FNV1A(sKey.c_str());

			if( FNV1A("steam_id64") == iHashKey || FNV1A("name") == iHashKey)
				g_EmulatorEngine.WriteTrace("PlayerInfo." + sKey + "= " + Value.as<std::string>() );
			else
				g_EmulatorEngine.WriteTrace("PlayerInfo." + sKey + "= " + std::to_string(Value.as<int>()) );

		}
	}

	sol::object Get(sol::stack_object Key, sol::this_state L)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;



			g_EmulatorEngine.WriteTrace("PlayerInfo.Get("  + sKey + ")");

			long iHashKey = FNV1A(sKey.c_str());


			if (FNV1A("steam_id64") == iHashKey || FNV1A("name") == iHashKey)
				return sol::make_object(L, std::string("black") );
			else
				return sol::make_object(L, 0);

		}
	}
};

struct Trace_t
{
	void Set(sol::stack_object Key, sol::stack_object Value, sol::this_state)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			long iHashKey = FNV1A(sKey.c_str());


			
			if (iHashKey == FNV1A("startpos") || iHashKey == FNV1A("endpos") || iHashKey == FNV1A("normal"))
			{
				Vector vecValue = Value.as<Vector>();
				g_EmulatorEngine.WriteTrace("Trace." + sKey + " = Vector(" + std::to_string(vecValue.m_flX) + "," + std::to_string(vecValue.m_flY) + "," + std::to_string(vecValue.m_flZ) + ")");
			}
			else
				g_EmulatorEngine.WriteTrace("Trace." + sKey + " = " + std::to_string(Value.as<int>()));
		}
	}

	sol::object Get(sol::stack_object Key, sol::this_state L)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			g_EmulatorEngine.WriteTrace("Trace.Get(" + sKey + ")");

			long iHashKey = FNV1A(sKey.c_str());


			if( iHashKey == FNV1A("startpos"))
				return sol::make_object(L, Vector(0, 6, 9));
			else if (iHashKey == FNV1A("endpos"))
				return sol::make_object(L, Vector(90, 180, 90));
			else if (iHashKey == FNV1A("normal"))
				return sol::make_object(L, Vector(1, 0, 1));
			else if (iHashKey == FNV1A("dist"))
				return sol::make_object(L, 10);
			else if (iHashKey == FNV1A("fraction"))
				return sol::make_object(L, 0.8f);
			else if (iHashKey == FNV1A("contents"))
				return sol::make_object(L, 0);
			else if (iHashKey == FNV1A("disp_flags"))
				return sol::make_object(L, 0);
			else if (iHashKey == FNV1A("allsolid"))
				return sol::make_object(L, false);
			else if (iHashKey == FNV1A("startsolid"))
				return sol::make_object(L, false);
			else if (iHashKey == FNV1A("hit_entity_index"))
				return sol::make_object(L, 1);
			else if (iHashKey == FNV1A("hitgroup"))
				return sol::make_object(L, 5);
			else if (iHashKey == FNV1A("hitgroup"))
				return sol::make_object(L, 6);
		}
	}
};

struct Rect_t
{
	float m_flLeft, m_flTop, m_flRight, m_flBottom;

	Rect_t(float flLeft, float flTop, float flRight, float flBottom)
	{
		m_flLeft = flLeft;
		m_flTop = flTop;
		m_flRight = flRight;
		m_flBottom = flBottom;
	}
};

struct Entity_t
{
	bool IsDormant()
	{
		g_EmulatorEngine.WriteTrace("Entity.IsDormant()");
		return false;
	}

	bool IsAlive()
	{
		g_EmulatorEngine.WriteTrace("Entity.IsAlive()");
		return true;
	}

	Rect_t GetBBOX()
	{
		g_EmulatorEngine.WriteTrace("Entity.GetBBOX()");
		return Rect_t(0, 50, 100, 200);
	}

	Vector GetPlayerHitboxPos(int iHitbox)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPlayerHitboxPos(" + std::to_string(iHitbox) + ")");
		return Vector(0, 50, 100);
	}

	int GetIndex()
	{
		return 2;
	}

	bool GetPropBool(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropBool(" + std::to_string(iOffset) + ")");
		return true;
	}

	int GetPropInt(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropInt(" + std::to_string(iOffset) + ")");
		return 1;
	}

	float GetPropFloat(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropFloat(" + std::to_string(iOffset) + ")");
		return 1.0f;
	}

	short GetPropShort(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropInt(" + std::to_string(iOffset) + ")");
		return 1;
	}
	
	double GetPropDouble(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropFloat(" + std::to_string(iOffset) + ")");
		return 1.0f;
	}

	Vector GetPropVector(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropVector(" + std::to_string(iOffset) + ")");
		return Vector(0, 50, 100);
	}

	Angle GetPropAngle(int iOffset)
	{
		g_EmulatorEngine.WriteTrace("Entity.GetPropAngle(" + std::to_string(iOffset) + ")");
		return Angle(0, 50, 100);
	}

	void SetPropBool(int iOffset, bool bValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropBool(" + std::to_string(iOffset) + ", " + std::to_string(bValue) + ")");
	}

	void SetPropInt(int iOffset, int iValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropInt(" + std::to_string(iOffset) + ", " + std::to_string(iValue) + ")");
	}

	void SetPropFloat(int iOffset, float flValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropFloat(" + std::to_string(iOffset) + ", " + std::to_string(flValue) + ")");
	}

	void SetPropShort(int iOffset, short iValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropInt(" + std::to_string(iOffset) + ", " + std::to_string(iValue) + ")");
	}

	void SetPropDouble(int iOffset, double flValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropFloat(" + std::to_string(iOffset) + ", " + std::to_string(flValue) + ")");
	}

	void SetPropVector(int iOffset, Vector vecValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropVector(" + std::to_string(iOffset) + ", " + std::to_string(vecValue.m_flX) + ", " + std::to_string(vecValue.m_flY) + ", " + std::to_string(vecValue.m_flZ) + ")");
	}

	void SetPropAngle(int iOffset, Angle angValue)
	{
		g_EmulatorEngine.WriteTrace("Entity.SetPropAngle(" + std::to_string(iOffset) + ", " + std::to_string(angValue.m_flPitch) + ", " + std::to_string(angValue.m_flYaw) + ", " + std::to_string(angValue.m_flRoll) + ")");
	}
};

struct UserCmd_t
{
	void Set(sol::stack_object Key, sol::stack_object Value, sol::this_state)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			long iHashKey = FNV1A(sKey.c_str());

			if (FNV1A("angle_t") == iHashKey)
			{
				Angle angValue = Value.as<Angle>();
				g_EmulatorEngine.WriteTrace("UserCmd." + sKey + " = " + std::to_string(angValue.m_flPitch) + ", " + std::to_string(angValue.m_flYaw) + ", " + std::to_string(angValue.m_flRoll));
			}
			else
				g_EmulatorEngine.WriteTrace("UserCmd." + sKey + " = " + std::to_string(Value.as<float>()));

		}
	}

	sol::object Get(sol::stack_object Key, sol::this_state L)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;



			g_EmulatorEngine.WriteTrace("PlayerInfo.Get(" + sKey + ")");

			long iHashKey = FNV1A(sKey.c_str());


			if (FNV1A("send_packet") == iHashKey)
				return sol::make_object(L, 1);
			else if (FNV1A("command_number") == iHashKey)
				return sol::make_object(L, 12);
			else if (FNV1A("tick_count") == iHashKey)
				return sol::make_object(L, 0x1337);
			else if (FNV1A("viewangles") == iHashKey)
				return sol::make_object(L, Angle(90,180,90));
			else if (FNV1A("forwardmove") == iHashKey)
				return sol::make_object(L, 1);
			else if (FNV1A("sidemove") == iHashKey)
				return sol::make_object(L, 2);
			else if (FNV1A("upmove") == iHashKey)
				return sol::make_object(L, 3);
			else if (FNV1A("buttons") == iHashKey)
				return sol::make_object(L, 1);
			else if (FNV1A("random_seed") == iHashKey)
				return sol::make_object(L, 5);
			else if (FNV1A("mousedx") == iHashKey)
				return sol::make_object(L, 5);
			else if (FNV1A("mousedy") == iHashKey)
				return sol::make_object(L, 6);
		}
	}
};

struct ShotInfo_t
{
	void Set(sol::stack_object Key, sol::stack_object Value, sol::this_state)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			long iHashKey = FNV1A(sKey.c_str());

			if (FNV1A("aim_point") == iHashKey)
			{
				Vector vecValue = Value.as<Vector>();
				g_EmulatorEngine.WriteTrace("ShotInfo." + sKey + " = " + std::to_string(vecValue.m_flX) + ", " + std::to_string(vecValue.m_flY) + ", " + std::to_string(vecValue.m_flZ));
			}
			else if (FNV1A("result") == iHashKey)
				g_EmulatorEngine.WriteTrace("ShotInfo." + sKey + " = " + Value.as<std::string>());
			else
				g_EmulatorEngine.WriteTrace("ShotInfo." + sKey + " = " + std::to_string(Value.as<float>()));

		}
	}

	sol::object Get(sol::stack_object Key, sol::this_state L)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;



			g_EmulatorEngine.WriteTrace("ShotInfo.Get(" + sKey + ")");

			long iHashKey = FNV1A(sKey.c_str());


			if (FNV1A("manual") == iHashKey)
				return sol::make_object(L, 0);
			else if (FNV1A("target_index") == iHashKey)
				return sol::make_object(L, Entity_t{});
			else if (FNV1A("backtrack") == iHashKey)
				return sol::make_object(L, 6);
			else if (FNV1A("hitchance") == iHashKey)
				return sol::make_object(L, 80);
			else if (FNV1A("hitbox") == iHashKey)
				return sol::make_object(L, 6);
			else if (FNV1A("server_hitgroup") == iHashKey)
				return sol::make_object(L, 6);
			else if (FNV1A("result") == iHashKey)
				return sol::make_object(L, "linius lox");
			else if (FNV1A("client_damage") == iHashKey)
				return sol::make_object(L, 150);
			else if (FNV1A("server_damage") == iHashKey)
				return sol::make_object(L, 1);
			else if (FNV1A("tick") == iHashKey)
				return sol::make_object(L, 9);
			else if (FNV1A("safe_point") == iHashKey)
				return sol::make_object(L, 1);
			else if (FNV1A("aim_point") == iHashKey)
				return sol::make_object(L, Vector(1, 2, 3));
		}
	}
};

struct ViewSetup_t
{
	void Set(sol::stack_object Key, sol::stack_object Value, sol::this_state)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			long iHashKey = FNV1A(sKey.c_str());

			if (FNV1A("camera_pos") == iHashKey)
			{
				Vector vecValue = Value.as<Vector>();
				g_EmulatorEngine.WriteTrace("ViewSetup_t." + sKey + " = " + std::to_string(vecValue.m_flX) + ", " + std::to_string(vecValue.m_flY) + ", " + std::to_string(vecValue.m_flZ));
			}
			else
				g_EmulatorEngine.WriteTrace("ViewSetup_t." + sKey + " = " + std::to_string(Value.as<float>()));

		}
	}

	sol::object Get(sol::stack_object Key, sol::this_state L)
	{
		auto pStringKey = Key.as<sol::optional<std::string>>();

		if (pStringKey)
		{
			const std::string& sKey = *pStringKey;

			g_EmulatorEngine.WriteTrace("ViewSetup_t.Get(" + sKey + ")");

			long iHashKey = FNV1A(sKey.c_str());

			if (FNV1A("camera_pos") == iHashKey)
				return sol::make_object(L, Vector(90,180,90 ) );
			else
				return sol::make_object(L, 90);
		}
	}
};

class CTypesSystem
{
public:
	/* Initializes the math types */
	void InitializeMath();
	
	/* Initialize render types*/
	void InitializeRender();

	/* Initializes the source engine types */
	void InitializeGame();
};

inline CTypesSystem g_TypesSystem;