#pragma once
#include <memory>

/*
 Vector2 is a class that represents a vector in 2d dimension, this class implements basic geometric operations, as well as arefmetic operations with it.
 @SapDragon 26.11.2022
*/

class Vector2
{
public:
	/* x and y dots */
	float m_flX, m_flY;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector2()
	{
		m_flX = m_flY = 0.f;
	}

	Vector2(float flX, float flY)
	{
		m_flX = flX;
		m_flY = flY;
	}

	/* Geometric Functions */
	float Length()
	{
		return (float)sqrt((this->m_flX * this->m_flX) + (this->m_flY * this->m_flY));
	}

	Vector2& operator=(const Vector2& vecOther)
	{
		this->m_flX = vecOther.m_flX;
		this->m_flY = vecOther.m_flY;
		return *this;
	}

	/* Logical operators */

	bool operator==(Vector2& vecOther)
	{
		return this->m_flX == vecOther.m_flX && this->m_flY == vecOther.m_flY;
	}

	bool operator!=(Vector2& vecOther)
	{
		return !(vecOther == *this);
	}

	/* Aphemetic overloads */


	Vector2 operator-() const
	{
		return Vector2(-m_flX, -m_flY);
	}

	/* With float */

	Vector2 operator-(float flValue) const
	{
		return Vector2(m_flX - flValue, m_flY - flValue);
	}

	Vector2 operator+(float flValue) const
	{
		return Vector2(m_flX + flValue, m_flY + flValue);
	}

	Vector2 operator*(float flValue) const
	{
		return Vector2(m_flX * flValue, m_flY * flValue);
	}

	Vector2 operator/(float flValue) const
	{
		return Vector2(m_flX / flValue, m_flY / flValue);
	}

	Vector2& operator-=(float flValue)
	{
		this->m_flX -= flValue;
		this->m_flY -= flValue;
		return *this;
	}

	Vector2& operator+=(float flValue)
	{
		this->m_flX += flValue;
		this->m_flY += flValue;
		return *this;
	}

	Vector2& operator*=(float flValue)
	{
		this->m_flX *= flValue;
		this->m_flY *= flValue;
		return *this;
	}

	Vector2& operator/=(float flValue)
	{
		this->m_flX /= flValue;
		this->m_flY /= flValue;
		return *this;
	}

	/* With vector */

	Vector2 operator-(const Vector2& vecOther) const
	{
		return Vector2(this->m_flX - vecOther.m_flX, this->m_flY - vecOther.m_flY);
	}

	Vector2 operator+(const Vector2& vecOther) const
	{
		return Vector2(this->m_flX + vecOther.m_flX, this->m_flY + vecOther.m_flY);
	}

	Vector2 operator*(const Vector2& vecOther) const
	{
		return Vector2(this->m_flX * vecOther.m_flX, this->m_flY * vecOther.m_flY);
	}

	Vector2 operator/(const Vector2& vecOther) const
	{
		return Vector2(this->m_flX / vecOther.m_flX, this->m_flY / vecOther.m_flY);
	}


	Vector2& operator-=(const Vector2& vecOther)
	{
		m_flX -= vecOther.m_flX;
		m_flY -= vecOther.m_flY;

		return *this;
	}

	Vector2& operator+=(const Vector2& vecOther)
	{
		m_flX += vecOther.m_flX;
		m_flY += vecOther.m_flY;

		return *this;
	}

	Vector2& operator*=(const Vector2& vecOther)
	{
		m_flX *= vecOther.m_flX;
		m_flY *= vecOther.m_flY;

		return *this;
	}

	Vector2& operator/=(const Vector2& vecOther)
	{
		m_flX /= vecOther.m_flX;
		m_flY /= vecOther.m_flY;

		return *this;
	}

};
