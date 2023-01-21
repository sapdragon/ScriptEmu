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

void CTypesSystem::InitializeGame()
{
}
