#include "../EmulatorEngine.hpp"

void CTypesSystem::InitializeMath()
{
	/* Get current sol state */
	auto& pState = g_EmulatorEngine.m_LuaState;
	
	/* Setup Vector in 3D ( ref: https://api.nixware.cc/types/vec3_t/ ) */
	pState.new_usertype<Vector>(("vec3_t"),
		sol::constructors <Vector(), Vector(float, float, float), Vector(int, int, int)>(),
		"x", &Vector::m_flX,
		"y", &Vector::m_flY,
		"z", &Vector::m_flZ,
		sol::meta_function::addition, sol::overload(sol::resolve < Vector(float)  const>(&Vector::operator+), sol::resolve < Vector(const Vector&) const>(&Vector::operator+)),
		sol::meta_function::subtraction, sol::overload(sol::resolve < Vector(float) const >(&Vector::operator-), sol::resolve < Vector(const Vector&) const >(&Vector::operator-)),
		sol::meta_function::multiplication, sol::overload(sol::resolve < Vector(float) const >(&Vector::operator*), sol::resolve < Vector(const Vector&) const >(&Vector::operator*)),
		sol::meta_function::division, sol::overload(sol::resolve < Vector(float) const >(&Vector::operator/), sol::resolve < Vector(const Vector&) const >(&Vector::operator/)),
		"length", &Vector::Length,
		"dist_to", &Vector::DistTo
		);

	/* Setup Vector in 2D ( ref: https://api.nixware.cc/types/vec2_t/ ) */
	pState.new_usertype <Vector2>(("vec2_t"),
		sol::constructors <Vector2(), Vector2(float, float), Vector2(int, int)>(),
		"x", &Vector2::m_flX,
		"y", &Vector2::m_flY,
		sol::meta_function::addition, sol::overload(sol::resolve < Vector2(float)  const>(&Vector2::operator+), sol::resolve < Vector2(const Vector2&) const>(&Vector2::operator+)),
		sol::meta_function::subtraction, sol::overload(sol::resolve < Vector2(float) const >(&Vector2::operator-), sol::resolve < Vector2(const Vector2&) const >(&Vector2::operator-)),
		sol::meta_function::multiplication, sol::overload(sol::resolve < Vector2(float) const >(&Vector2::operator*), sol::resolve < Vector2(const Vector2&) const >(&Vector2::operator*)),
		sol::meta_function::division, sol::overload(sol::resolve < Vector2(float) const >(&Vector2::operator/), sol::resolve < Vector2(const Vector2&) const >(&Vector2::operator/)),
		"length", &Vector2::Length
		);

	/* Setup Vector in 4D ( ref: https://api.nixware.cc/types/vec4_t/ ) */
	pState.new_usertype < Vector4>("vec4_t",
		sol::constructors <Vector4(), Vector4(float, float, float, float), Vector4(int, int, int, int)>(),
		"x", &Vector4::m_flX,
		"y", &Vector4::m_flY,
		"z", &Vector4::m_flZ,
		"w", &Vector4::m_flW
		);

	/* Setup Angle ( ref: https://api.nixware.cc/types/angle_t/ ) */
	pState.new_usertype<Angle>(("angle_t"),
		sol::constructors <Angle(), Angle(float, float, float), Angle(int, int, int)>(),
		"pitch", &Angle::m_flPitch,
		"yaw", &Angle::m_flYaw,
		"roll", &Angle::m_flRoll,
		sol::meta_function::addition, sol::overload(sol::resolve < Angle(float)  const>(&Angle::operator+), sol::resolve < Angle(const Angle&) const>(&Angle::operator+)),
		sol::meta_function::subtraction, sol::overload(sol::resolve < Angle(float) const >(&Angle::operator-), sol::resolve < Angle(const Angle&) const >(&Angle::operator-)),
		sol::meta_function::multiplication, sol::overload(sol::resolve < Angle(float) const >(&Angle::operator*), sol::resolve < Angle(const Angle&) const >(&Angle::operator*)),
		sol::meta_function::division, sol::overload(sol::resolve < Angle(float) const >(&Angle::operator/), sol::resolve < Angle(const Angle&) const >(&Angle::operator/))
		);
}

void CTypesSystem::InitializeRender()
{
	/* Get current sol state */
	auto& pState = g_EmulatorEngine.m_LuaState;

	pState.new_usertype<Color_t>(("color_t"),
		sol::constructors <Color_t(float, float, float), Color_t(float, float, float, float)>(),
		"r", &Color_t::r,
		"g", &Color_t::g,
		"b", &Color_t::b,
		"a", &Color_t::a
		);
}

void CTypesSystem::InitializeGame()
{
	/* Get current sol state */
	auto& pState = g_EmulatorEngine.m_LuaState;

	/* Set player info ( ref: https://api.nixware.cc/sourceengine/types/player_info_t/ ) */
	pState.new_usertype < PlayerInfo_t >(("player_info_t"),
		sol::meta_function::index, &PlayerInfo_t::Get,
		sol::meta_function::new_index, &PlayerInfo_t::Set
		);

	/* Set Trace ( ref: https://api.nixware.cc/sourceengine/types/trace_t/ ) */
	pState.new_usertype < Trace_t >(("trace_t"),
		sol::meta_function::index, &Trace_t::Get,
		sol::meta_function::new_index, &Trace_t::Set
		);

	pState.new_usertype < ShotInfo_t >(("shot_info_t"),
		sol::meta_function::index, &ShotInfo_t::Get,
		sol::meta_function::new_index, &ShotInfo_t::Set
		);

	pState.new_usertype < ViewSetup_t >(("view_setup_t"),
		sol::meta_function::index, &ViewSetup_t::Get,
		sol::meta_function::new_index, &ViewSetup_t::Set
		);
	pState.new_usertype < Entity_t >(("entity_t"),
		"is_dormant", &Entity_t::IsDormant,
		"is_alive", &Entity_t::IsAlive,
		"get_bbox", &Entity_t::GetBBOX,
		"get_player_hitbox_pos", &Entity_t::GetPlayerHitboxPos,
		"get_index", &Entity_t::GetIndex,
		"get_prop_bool", &Entity_t::GetPropBool,
		"get_prop_int", &Entity_t::GetPropInt,
		"get_prop_float", &Entity_t::GetPropFloat,
		"get_prop_short", &Entity_t::GetPropShort,
		"get_prop_double", &Entity_t::GetPropDouble,
		"get_prop_vector", &Entity_t::GetPropVector,
		"get_prop_angle", &Entity_t::GetPropAngle,
		"set_prop_bool", &Entity_t::SetPropBool,
		"set_prop_int", &Entity_t::SetPropInt,
		"set_prop_float", &Entity_t::SetPropFloat,
		"set_prop_short", &Entity_t::SetPropShort,
		"set_prop_double", &Entity_t::SetPropDouble,
		"set_prop_vector", &Entity_t::SetPropVector,
		"set_prop_angle", &Entity_t::SetPropAngle
		);

	pState.new_usertype < Convar_t >(("convar_t"),
		"get_int", &Convar_t::GetInt,
		"get_float", &Convar_t::GetFloat,
		"get_string", &Convar_t::GetString,
		"set_int", &Convar_t::SetInt,
		"set_float", &Convar_t::SetFloat,
		"set_string", &Convar_t::SetString
		);

	pState.new_usertype < UserCmd_t >(("usercmd_t"),
		sol::meta_function::index, &UserCmd_t::Get,
		sol::meta_function::new_index, &UserCmd_t::Set
		);

	pState.new_usertype < GameEvent_t >(("game_event_t"),
		"get_name", &GameEvent_t::GetName,
		"get_bool", &GameEvent_t::GetBool,
		"get_int", &GameEvent_t::GetInt,
		"get_float", &GameEvent_t::GetFloat,
		"get_string", &GameEvent_t::GetString,
		"set_bool", &GameEvent_t::SetBool,
		"set_int", &GameEvent_t::SetInt,
		"set_float", &GameEvent_t::SetFloat,
		"set_string", &GameEvent_t::SetString
		);
}
