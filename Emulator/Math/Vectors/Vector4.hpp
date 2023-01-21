#pragma once
#include <memory>
/*
Vector4 is a class that represents a vector in 4D dimension, this class implements basic geometric operations, as well as arefmetic operations with it.
@SapDragon 26.11.2022
*/

class Vector4
{
public:
	/*  basic dots */
	float m_flX, m_flY, m_flZ, m_flW;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector4()
	{
		m_flX = 0.f;
		m_flY = 0.f;
		m_flZ = 0.f;
		m_flW = 0.f;
	}

	Vector4(Vector4& vecOther)
	{
		this->m_flX = vecOther.m_flX;
		this->m_flY = vecOther.m_flY;
		this->m_flZ = vecOther.m_flZ;
		this->m_flW = vecOther.m_flW;
	}

	Vector4(float flX, float flY, float flZ, float flW)
	{
		this->m_flX = flX;
		this->m_flY = flY;
		this->m_flZ = flZ;
		this->m_flW = flW;
	}


	/* Clear vector */
	void Clear()
	{
		m_flX = m_flY = m_flZ = m_flW = 0.f;
	}

	/* Logical operators */
	bool operator==(Vector4& vecOther)
	{
		return (this->m_flX == vecOther.m_flX) && (this->m_flY == vecOther.m_flY) && (this->m_flZ == vecOther.m_flZ);
	}

	bool operator!=(Vector4& vecOther)
	{
		return !(vecOther == *this);
	}

	/* Aphemetic overloads */

	Vector4 operator-()
	{
		return Vector4(-m_flX, -m_flY, -m_flZ, -m_flW);
	}

	/* With float */
	Vector4 operator+(float flValue)
	{
		return Vector4(m_flX + flValue, m_flY + flValue, m_flZ + flValue, m_flW + flValue);
	}

	Vector4 operator-(float flValue)
	{
		return Vector4(m_flX - flValue, m_flY - flValue, m_flZ - flValue, m_flW - flValue);
	}


	Vector4 operator*(float flValue)
	{
		return Vector4(m_flX * flValue, m_flY * flValue, m_flZ * flValue, m_flW * flValue);
	}

	Vector4 operator/(float flValue)
	{
		return Vector4(m_flX / flValue, m_flY / flValue, m_flZ / flValue, m_flW / flValue);
	}

	Vector4& operator+=(float flValue)
	{
		this->m_flX += flValue;
		this->m_flY += flValue;
		this->m_flZ += flValue;
		this->m_flW += flValue;

		return *this;
	}

	Vector4& operator-=(float flValue)
	{
		this->m_flX -= flValue;
		this->m_flY -= flValue;
		this->m_flZ -= flValue;
		this->m_flW -= flValue;

		return *this;
	}

	Vector4& operator*=(float flValue)
	{
		this->m_flX *= flValue;
		this->m_flY *= flValue;
		this->m_flZ *= flValue;
		this->m_flW -= flValue;

		return *this;
	}

	Vector4& operator/=(float flValue)
	{
		this->m_flX /= flValue;
		this->m_flY /= flValue;
		this->m_flZ /= flValue;
		this->m_flW -= flValue;

		return *this;
	}

	/* With Vector4 */


	Vector4 operator+(Vector4& vecOther)
	{
		return Vector4(m_flX + vecOther.m_flX, m_flY + vecOther.m_flY, m_flZ + vecOther.m_flZ, m_flW + vecOther.m_flW);
	}

	Vector4 operator-(Vector4& vecOther)
	{
		return Vector4(m_flX - vecOther.m_flX, m_flY - vecOther.m_flY, m_flZ - vecOther.m_flZ, m_flW - vecOther.m_flW);
	}


	Vector4 operator*(Vector4& vecOther)
	{
		return Vector4(m_flX * vecOther.m_flX, m_flY * vecOther.m_flY, m_flZ * vecOther.m_flZ, m_flW * vecOther.m_flW);
	}

	Vector4 operator/(Vector4& vecOther)
	{
		return Vector4(m_flX / vecOther.m_flX, m_flY / vecOther.m_flY, m_flZ / vecOther.m_flZ, m_flW / vecOther.m_flW);
	}

	Vector4& operator /=(Vector4& vecOther)
	{
		this->m_flX /= vecOther.m_flX;
		this->m_flY /= vecOther.m_flY;
		this->m_flZ /= vecOther.m_flZ;
		this->m_flW /= vecOther.m_flW;

		return *this;
	}

	Vector4& operator *=(Vector4& vecOther)
	{
		this->m_flX *= vecOther.m_flX;
		this->m_flY *= vecOther.m_flY;
		this->m_flZ *= vecOther.m_flZ;
		this->m_flW *= vecOther.m_flW;

		return *this;
	}

	Vector4& operator -=(Vector4& vecOther)
	{
		this->m_flX -= vecOther.m_flX;
		this->m_flY -= vecOther.m_flY;
		this->m_flZ -= vecOther.m_flZ;
		this->m_flW -= vecOther.m_flW;

		return *this;
	}

	Vector4& operator +=(Vector4& vecOther)
	{
		this->m_flX += vecOther.m_flX;
		this->m_flY += vecOther.m_flY;
		this->m_flZ += vecOther.m_flZ;
		this->m_flW += vecOther.m_flW;

		return *this;
	}

};