#pragma once
#include <memory>
/*
Vector3 is a class that represents a vector in 3D dimension, this class implements basic geometric operations, as well as arefmetic operations with it.
@SapDragon 26.11.2022
*/

class Vector
{
public:
	/* x, y, z dots */
	float m_flX, m_flY, m_flZ;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector(void)
	{
		m_flX = 0.f;
		m_flY = 0.f;
		m_flZ = 0.f;
	}


	Vector(float flX, float flY, float flZ)
	{
		this->m_flX = flX;
		this->m_flY = flY;
		this->m_flZ = flZ;
	}


	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		m_flX = ix; m_flY = iy; m_flZ = iz;
	}


	/* All kinds of validity checks  */
	bool IsValid()
	{
		return !isinf(m_flX) && !isinf(m_flY) && !isinf(m_flZ);
	}

	bool IsEmpty()
	{
		return m_flY == 0.f && m_flX == 0.f && m_flZ == 0.f;
	}


	/* Clear vector */
	void Clear()
	{
		m_flX = m_flY = m_flZ = 0.f;
	}

	/* Geometric Functions */

	float Length()
	{
		return (float)sqrt((this->m_flX * this->m_flX) + (this->m_flY * this->m_flY) + (this->m_flZ * this->m_flZ));
	}

	float DistTo(Vector& vecOther)
	{
		Vector vecDelta;

		vecDelta.m_flX = this->m_flX - vecOther.m_flX;
		vecDelta.m_flY = this->m_flY - vecOther.m_flY;
		vecDelta.m_flZ = this->m_flZ - vecOther.m_flZ;

		return vecDelta.Length();
	}



	Vector& operator=(const Vector& vOther)
	{
		m_flX = vOther.m_flX; m_flY = vOther.m_flY; m_flZ = vOther.m_flZ;
		return *this;
	}


	/* Logical operators */
	bool operator==(const Vector& vecOther) const
	{
		return (this->m_flX == vecOther.m_flX) && (this->m_flY == vecOther.m_flY) && (this->m_flZ == vecOther.m_flZ);
	}

	bool operator!=(const Vector& vecOther) const
	{
		return !(vecOther == *this);
	}

	/* Aphemetic overloads */

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}
	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector operator-() const
	{
		return Vector(-m_flX, -m_flY, -m_flZ);
	}

	/* With float */
	Vector operator+(float flValue) const
	{
		return Vector(m_flX + flValue, m_flY + flValue, m_flZ + flValue);
	}

	Vector operator-(float flValue) const
	{
		return Vector(m_flX - flValue, m_flY - flValue, m_flZ - flValue);
	}


	Vector operator*(float flValue) const
	{
		return Vector(m_flX * flValue, m_flY * flValue, m_flZ * flValue);
	}

	Vector operator/(float flValue) const
	{
		return Vector(m_flX / flValue, m_flY / flValue, m_flZ / flValue);
	}

	Vector& operator+=(float flValue)
	{
		this->m_flX += flValue;
		this->m_flY += flValue;
		this->m_flZ += flValue;

		return *this;
	}

	Vector& operator-=(float flValue)
	{
		this->m_flX -= flValue;
		this->m_flY -= flValue;
		this->m_flZ -= flValue;

		return *this;
	}

	Vector& operator*=(float flValue)
	{
		this->m_flX *= flValue;
		this->m_flY *= flValue;
		this->m_flZ *= flValue;

		return *this;
	}

	Vector& operator/=(float flValue)
	{
		this->m_flX /= flValue;
		this->m_flY /= flValue;
		this->m_flZ /= flValue;

		return *this;
	}

	/* With vector */


	Vector operator+(const Vector& vecOther) const
	{
		return Vector(m_flX + vecOther.m_flX, m_flY + vecOther.m_flY, m_flZ + vecOther.m_flZ);
	}

	Vector operator-(const Vector& vecOther) const
	{
		return Vector(m_flX - vecOther.m_flX, m_flY - vecOther.m_flY, m_flZ - vecOther.m_flZ);
	}


	Vector operator*(const Vector& vecOther) const
	{
		return Vector(m_flX * vecOther.m_flX, m_flY * vecOther.m_flY, m_flZ * vecOther.m_flZ);
	}

	Vector operator/(const Vector& vecOther) const
	{
		return Vector(m_flX / vecOther.m_flX, m_flY / vecOther.m_flY, m_flZ / vecOther.m_flZ);
	}

	Vector& operator /=(const Vector& vecOther)
	{
		this->m_flX /= vecOther.m_flX;
		this->m_flY /= vecOther.m_flY;
		this->m_flZ /= vecOther.m_flZ;

		return *this;
	}

	Vector& operator *=(const Vector& vecOther)
	{
		this->m_flX *= vecOther.m_flX;
		this->m_flY *= vecOther.m_flY;
		this->m_flZ *= vecOther.m_flZ;

		return *this;
	}

	Vector& operator -=(const Vector& vecOther)
	{
		this->m_flX -= vecOther.m_flX;
		this->m_flY -= vecOther.m_flY;
		this->m_flZ -= vecOther.m_flZ;

		return *this;
	}

	Vector& operator +=(const Vector& vecOther)
	{
		this->m_flX += vecOther.m_flX;
		this->m_flY += vecOther.m_flY;
		this->m_flZ += vecOther.m_flZ;

		return *this;
	}

};