#pragma once

/* Global function table ( ref: https://www.lua.org/pil ) */
namespace Globals
{
	inline std::string ToString(sol::object arg);
	inline std::string ToString(sol::stack_proxy arg) { return ToString(arg.as<sol::object>()); }
	inline std::vector<std::string> ToString(sol::variadic_args sArgs);

	inline std::string ToString(sol::object arg)
	{
		auto type = arg.get_type();

		if (type == sol::type::string)
			return "\"" + arg.as<std::string>() + "\"";
		else if (type == sol::type::number)
			return arg.as<std::string>();
		else if (type == sol::type::boolean)
			return std::to_string(arg.as<double>());
		else if (type == sol::type::userdata || type == sol::type::lightuserdata)
			return "userdata";
		else if (type == sol::type::table)
			return "table";
		else if (type == sol::type::function)
			return "fn";
		else
			return "nil";
	}

	inline std::vector<std::string> ToString(sol::variadic_args sArgs) 
	{
		std::vector<std::string> returnVector;

		for (auto arg : sArgs) {
			returnVector.push_back(ToString(arg));
		}

		return returnVector;
	}

	inline void Print(sol::variadic_args sText)
	{
		auto returnVector = ToString(sText);
		std::string sArgValue = "";

		for (auto arg : returnVector) {
			if (sArgValue == "")
				sArgValue = arg;
			else
				sArgValue += ", " + arg;
		}

		g_EmulatorEngine.WriteTrace("print ( " + sArgValue + " )");
	}

	inline void Require(sol::object sScriptName)
	{
		g_EmulatorEngine.WriteTrace("require ( " + ToString(sScriptName) + " )");
	}
}

/* Client table ( ref: https://api.nixware.cc/client/ ) */
namespace Client
{
	inline void LoadScript(sol::object sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::LoadScript ( " + Globals::ToString(sScriptName) + " )");
	}

	inline void UnloadScript(sol::object sScriptName)
	{
		g_EmulatorEngine.WriteTrace("Client::UnloadScript ( " + Globals::ToString(sScriptName) + " )");
	}

	inline std::string GetScriptName()
	{
		g_EmulatorEngine.WriteTrace("Client::GetScriptName");

		return "scriptemu.lua";
	}

	inline void RegisterCallBack(sol::object sName, sol::function fCallback)
	{
		g_EmulatorEngine.WriteTrace("Client::RegisterCallBack ( " + Globals::ToString(sName) + ", fn )");
		return g_CallBacksSystem.RegisterCallBack(sName.as<std::string>(), fCallback);
	}

	inline std::string GetUsername()
	{
		g_EmulatorEngine.WriteTrace("Client::GetUsername");

		return "sapdragon";
	}

	inline void Notify(sol::object sMessage)
	{
		g_EmulatorEngine.WriteTrace("Client::Notify ( " + Globals::ToString(sMessage) + " )");
	}
	
	inline int GetTimeStamp()
	{
		g_EmulatorEngine.WriteTrace("Client::GetTimeStamp");

		return 0xDEADFEED;
	}

	inline std::tuple<int, int, int> GetSystemTime()
	{
		g_EmulatorEngine.WriteTrace("Client::GetSystemTime");

		return std::make_tuple(0, 1, 2);
	}

	inline int FindPattern(sol::object sModule, sol::object sPattern)
	{
		g_EmulatorEngine.WriteTrace("Client::FindPattern ( " + Globals::ToString(sModule) + ", " + Globals::ToString(sPattern) + " )");

		return 0xC001C0DE;
	}	
}

/* Render table ( ref: https://api.nixware.cc/renderer/ ) */
namespace Render
{
	struct Font_t
	{
		/* Path to font */
		std::string m_sPath;
		/* Font size */
		int m_iSize;
		/* Font flags */
		int m_iFlags;
	};
	
	struct Texture_t
	{
		/* Path to texture file */
		std::string m_sPath;
	};

	inline Font_t SetupFont(sol::object sPath, int iSize, int iFlags)
	{
		g_EmulatorEngine.WriteTrace("Render::SetupFont ( " + Globals::ToString(sPath) + ", " + std::to_string(iSize) + ", " + std::to_string(iFlags) + " )");

		return Font_t{ sPath.as<std::string>(), iSize, iFlags};
	}

	inline Texture_t SetupTexture(sol::object sPath)
	{
		g_EmulatorEngine.WriteTrace("Render::SetupTexture ( " + Globals::ToString(sPath) + " )");

		return Texture_t{ sPath.as<std::string>() };
	}
	
	inline void RenderText(sol::object sText, Font_t Font, Vector2 vecPosition, int iSize, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderText ( " + Globals::ToString(sText) + ", " + Font.m_sPath + ", " + std::to_string(Font.m_iSize) + ", " + std::to_string(Font.m_iFlags) + ", Vector2(" + std::to_string(vecPosition.m_flX) + ", " + std::to_string(vecPosition.m_flY) + "), " + std::to_string(iSize) + ", Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}

	/* texture(tex, from, to, color)*/
	inline void RenderTexture(Texture_t Texture, Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderTexture ( " + Texture.m_sPath + ", Vector2(" + std::to_string(vecFrom.m_flX) + ", " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + ", " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}
	
	inline Vector2 GetTextSize(Font_t Font, int iSize, sol::object sText)
	{
		g_EmulatorEngine.WriteTrace("Render::GetTextSize ( " + Font.m_sPath + ", " + std::to_string(Font.m_iSize) + ", " + std::to_string(Font.m_iFlags) + ", " + std::to_string(iSize) + ", " + Globals::ToString(sText) + " )");

		return Vector2(49, 50);
	}
	
	inline Vector2 GetCursorPos()
	{
		g_EmulatorEngine.WriteTrace("Render::GetCursorPos()");

		return Vector2(51, 52);
	}

	inline void RenderLine(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderLine ( Vector2(" + std::to_string(vecFrom.m_flX) + ", " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + ", " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}

	inline void RenderRect(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRect ( Vector2(" + std::to_string(vecFrom.m_flX) + ", " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + ", " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}

	inline void RenderRectFilled(Vector2 vecFrom, Vector2 vecTo, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRectFilled ( Vector2(" + std::to_string(vecFrom.m_flX) + ", " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + ", " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}

	inline void RenderRectFilledFade(Vector2 vecFrom, Vector2 vecTo, Color_t ColorUpperLeft, Color_t ColorUpperRight, Color_t ColorBottomRight, Color_t ColorBottomLeft)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderRectFilledFade ( Vector2(" + std::to_string(vecFrom.m_flX) + ", " + std::to_string(vecFrom.m_flY) + "), Vector2(" + std::to_string(vecTo.m_flX) + ", " + std::to_string(vecTo.m_flY) + "), Color(" + std::to_string(ColorUpperLeft.r) + ", " + std::to_string(ColorUpperLeft.g) + ", " + std::to_string(ColorUpperLeft.b) + ", " + std::to_string(ColorUpperLeft.a) + "), Color(" + std::to_string(ColorUpperRight.r) + ", " + std::to_string(ColorUpperRight.g) + ", " + std::to_string(ColorUpperRight.b) + ", " + std::to_string(ColorUpperRight.a) + "), Color(" + std::to_string(ColorBottomRight.r) + ", " + std::to_string(ColorBottomRight.g) + ", " + std::to_string(ColorBottomRight.b) + ", " + std::to_string(ColorBottomRight.a) + "), Color(" + std::to_string(ColorBottomLeft.r) + ", " + std::to_string(ColorBottomLeft.g) + ", " + std::to_string(ColorBottomLeft.b) + ", " + std::to_string(ColorBottomLeft.a) + ") )");
	}

	inline void RenderCircleFade(Vector2 vecPos, int iRadius, Color_t ColorIn, Color_t ColorOut)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderCircleFade ( Vector2(" + std::to_string(vecPos.m_flX) + ", " + std::to_string(vecPos.m_flY) + "), " + std::to_string(iRadius) + ", Color(" + std::to_string(ColorIn.r) + ", " + std::to_string(ColorIn.g) + ", " + std::to_string(ColorIn.b) + ", " + std::to_string(ColorIn.a) + "), Color(" + std::to_string(ColorOut.r) + ", " + std::to_string(ColorOut.g) + ", " + std::to_string(ColorOut.b) + ", " + std::to_string(ColorOut.a) + ") )");
	}

	inline void RenderCircle(Vector2 vecPos, int iRadius, int iSegments, bool bFilled, Color_t Color)
	{
		g_EmulatorEngine.WriteTrace("Render::RenderCircle ( Vector2(" + std::to_string(vecPos.m_flX) + ", " + std::to_string(vecPos.m_flY) + "), " + std::to_string(iRadius) + ", " + std::to_string(iSegments) + ", " + std::to_string(bFilled) + ", Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}

	inline void FilledPolygon(std::vector < Vector2 > aPoints, Color_t Color)
	{
		std::string sPoints = "{ ";
		for (auto& Point : aPoints)
			sPoints += "Vector2(" + std::to_string(Point.m_flX) + ", " + std::to_string(Point.m_flY) + "), ";
		
		sPoints += "}";

		g_EmulatorEngine.WriteTrace("Render::FilledPolygon ( " + sPoints + "Color(" + std::to_string(Color.r) + ", " + std::to_string(Color.g) + ", " + std::to_string(Color.b) + ", " + std::to_string(Color.a) + ") )");
	}
}

namespace Ragebot
{
	inline void IgnorePlayer(int iEntityIndex)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::IgnorePlayer ( " + std::to_string(iEntityIndex) + " )");
	}
	
	inline void OverrideWallPenetration(int iEntityIndex, bool bPenetrate)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideWallPenetration ( " + std::to_string(iEntityIndex) + ", " + std::to_string(bPenetrate) + " )");
	}

	inline void OverrideDesyncCorrection(int iEntityIndex, bool bCorrect)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideDesyncCorrection ( " + std::to_string(iEntityIndex) + ", " + std::to_string(bCorrect) + " )");
	}

	inline void OverrideHitScan(int iEntityIndex, int iHitbox, bool bScan)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideHitScan ( " + std::to_string(iEntityIndex) + ", " + std::to_string(iHitbox) + ", " + std::to_string(bScan) + " )");
	}
	
	inline void OverrideSkipUnsafePoints(int iEntityIndex, int iHitbox, bool bSkip)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideSkipUnsafePoints ( " + std::to_string(iEntityIndex) + ", " + std::to_string(iHitbox) + ", " + std::to_string(bSkip) + " )");
	}

	inline void OverrideMinDamage(int iEntityIndex, float flDamage)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideMinDamage ( " + std::to_string(iEntityIndex) + ", " + std::to_string(flDamage) + " )");
	}
	
	inline void OverrideSafePoint(int iEntityIndex, int iMode)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideSafePoint ( " + std::to_string(iEntityIndex) + ", " + std::to_string(iMode) + " )");
	}

	inline void OverrideMaxMisses(int iEntityIndex, int iMisses)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideMaxMisses ( " + std::to_string(iEntityIndex) + ", " + std::to_string(iMisses) + " )");
	}

	inline void OverrideHeadScale(int iEntityIndex, float flScale)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideHeadScale ( " + std::to_string(iEntityIndex) + ", " + std::to_string(flScale) + " )");
	}

	inline void OverrideBodyScale(int iEntityIndex, float flScale)
	{
		g_EmulatorEngine.WriteTrace("Ragebot::OverrideBodyScale ( " + std::to_string(iEntityIndex) + ", " + std::to_string(flScale) + " )");
	}
}

namespace SourceUtils
{
	inline Vector2 WorldToScreen(Vector vecWorld)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::WorldToScreen ( Vector3(" + std::to_string(vecWorld.m_flX) + ", " + std::to_string(vecWorld.m_flY) + ", " + std::to_string(vecWorld.m_flZ) + ") )");
		return Vector2(200, 250);
	}

	inline void SetClanTag(sol::object sTag)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::SetClanTag ( " + Globals::ToString(sTag) + " )");
	}

	inline void SetName(sol::object sName)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::SetName ( " + Globals::ToString(sName) + " )");
	}

	inline Convar_t GetConVar(sol::object sName)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::GetConVar ( " + Globals::ToString(sName) + " )");
		return Convar_t{ sName.as<std::string>() };
	}

	inline int GetNetVar(sol::object sTable, sol::object sProp)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::GetNetVar ( " + Globals::ToString(sTable) + ", " + Globals::ToString(sProp) + " )");
		return 0x1337;
	}

	inline int GetLatency()
	{
		return 69;
	}

	inline int CreateInterface(sol::object sModule, sol::object sInterface)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::CreateInterface ( " + Globals::ToString(sModule) + ", " + Globals::ToString(sInterface) + " )");
		return 0x1337;
	}

	inline void RegisterEvent(sol::object sEvent)
	{
		g_EmulatorEngine.WriteTrace("SourceUtils::RegisterEvent ( " + Globals::ToString(sEvent) + " )");
	}
}

namespace Engine
{
	inline Vector2 GetScreenSize()
	{
		g_EmulatorEngine.WriteTrace("Engine::GetScreenSize()");
		return Vector2(1920, 1080);
	}

	inline bool IsConnected()
	{
		g_EmulatorEngine.WriteTrace("Engine::IsConnected()");
		return true;
	}

	inline bool IsInGame()
	{
		g_EmulatorEngine.WriteTrace("Engine::IsInGame()");
		return true;
	}

	inline int GetLocalPlayer()
	{
		g_EmulatorEngine.WriteTrace("Engine::GetLocalPlayer()");
		return 1;
	}

	inline PlayerInfo_t GetPlayerInfo(int iPlayerIndex)
	{
		g_EmulatorEngine.WriteTrace("Engine::GetPlayerInfo ( " + std::to_string(iPlayerIndex) + " )");
		return PlayerInfo_t{ };
	}

	inline std::string GetLevelNameShort(int iPlayerIndex)
	{
		g_EmulatorEngine.WriteTrace("Engine::GetLevelNameShort ( " + std::to_string(iPlayerIndex) + " )");
		return "de_dust2";
	}

	inline int GetPlayerForUserID(int iUserID)
	{
		g_EmulatorEngine.WriteTrace("Engine::GetPlayerForUserID ( " + std::to_string(iUserID) + " )");
		return 1;
	}
	
	inline void SetViewAngles(Angle angViewAngles)
	{
		g_EmulatorEngine.WriteTrace("Engine::SetViewAngles ( Angle(" + std::to_string(angViewAngles.m_flPitch) + ", " + std::to_string(angViewAngles.m_flYaw) + ", " + std::to_string(angViewAngles.m_flRoll) + ") )");
	}
	
	inline Angle GetViewAngles()
	{
		g_EmulatorEngine.WriteTrace("Engine::GetViewAngles()");
		return Angle{ 90, 180, 90 };
	}
	
	inline void ExecuteClientCmd(sol::object sCommand)
	{
		g_EmulatorEngine.WriteTrace("Engine::ExecuteClientCmd ( " + Globals::ToString(sCommand) + " )");
	}
}

namespace Trace
{
	inline Trace_t TraceLine(int iSkipEntityIndex, int iMask, Vector vecStart, Vector vecEnd)
	{
		g_EmulatorEngine.WriteTrace("Trace::TraceLine ( " + std::to_string(iSkipEntityIndex) + ", " + std::to_string(iMask) + ", Vector3(" + std::to_string(vecStart.m_flX) + ", " + std::to_string(vecStart.m_flY) + ", " + std::to_string(vecStart.m_flZ) + "), Vector3(" + std::to_string(vecEnd.m_flX) + ", " + std::to_string(vecEnd.m_flY) + ", " + std::to_string(vecEnd.m_flZ) + ") )");
		return Trace_t{ };
	}

	inline Trace_t TraceHull(int iMask, Vector vecStart, Vector vecEnd, Vector vecMins, Vector vecMaxs, int iTraceType, sol::function fnFilter)
	{
		fnFilter(2, 0xDEADBEEF);
		
		g_EmulatorEngine.WriteTrace("Trace::TraceHull ( " + std::to_string(iMask) + ", Vector3(" + std::to_string(vecStart.m_flX) + ", " + std::to_string(vecStart.m_flY) + ", " + std::to_string(vecStart.m_flZ) + "), Vector3(" + std::to_string(vecEnd.m_flX) + ", " + std::to_string(vecEnd.m_flY) + ", " + std::to_string(vecEnd.m_flZ) + "), Vector3(" + std::to_string(vecMins.m_flX) + ", " + std::to_string(vecMins.m_flY) + ", " + std::to_string(vecMins.m_flZ) + "), Vector3(" + std::to_string(vecMaxs.m_flX) + ", " + std::to_string(vecMaxs.m_flY) + ", " + std::to_string(vecMaxs.m_flZ) + "), " + std::to_string(iTraceType) + " )");
		return Trace_t{ };
	}
}

namespace GlobalVars
{
	int GetRealTime()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetRealTime()");
		return 0x1337;
	}

	int GetFrameCount()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetFrameCount()");
		return 0x1337;
	}

	int GetAbsoluteFrameTime()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetAbsoluteFrameCount()");
		return 0x1337;
	}

	int GetCurrentTime()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetCurrentTime()");
		return 0x1337;
	}

	int GetFrameTime()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetFrameTime()");
		return 0x1337;
	}

	int GetMaxClients()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetMaxClients()");
		return 32;
	}

	int GetTickCount()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetTickCount()");
		return 0x1337;
	}

	int GetTickInterval()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetTickInterval()");
		return 64;
	}

	float GetCurTime()
	{
		g_EmulatorEngine.WriteTrace("GlobalVars::GetCurTime()");
		return 20.1337f;
	}
}

namespace ClientState
{
	int GetChokedCommands()
	{
		g_EmulatorEngine.WriteTrace("ClientState::GetChokedCommands()");
		return 12;
	}

	void ForceFullUpdate()
	{
		g_EmulatorEngine.WriteTrace("ClientState::ForceFullUpdate()");
	}
}

namespace Entitylist
{
	inline int GetHighestEntityIndex()
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetHighestEntityIndex()");
		return 64;
	}

	Entity_t GetLocalPlayer()
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetLocalPlayer()");
		return Entity_t{ };
	}

	Entity_t GetEntityByIndex(int iIndex)
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetEntityByIndex ( " + std::to_string(iIndex) + " )");
		return Entity_t{ };
	}

	Entity_t GetEntityFromHandle(int iHandle)
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetEntityFromHandle ( " + std::to_string(iHandle) + " )");
		return Entity_t{ };
	}

	std::list < Entity_t > GetPlayers()
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetEntityList()");
		return std::list < Entity_t > {Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t() };
	}

	std::list < Entity_t > GetEntitiesByClassName(sol::object sClassName )
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetEntitiesByClassName ( " + Globals::ToString(sClassName) + " )");
		return std::list < Entity_t > {Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t() };
	}

	std::list < Entity_t > GetEntitiesByClassId(int iClassId)
	{
		g_EmulatorEngine.WriteTrace("Entitylist::GetEntitiesByClassId ( " + std::to_string(iClassId) + " )");
		return std::list < Entity_t > {Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t(), Entity_t() };
	}
}