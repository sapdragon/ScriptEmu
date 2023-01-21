#pragma once
#include <memory>

/* It's a simple fucking rename of Vector3 */

class Angle
{
public:
	/* x, y, z dots */
	float m_flPitch, m_flYaw, m_flRoll;

	/* Basic constructors for initializing, reinitializing Angles. */
	Angle(void)
	{
		m_flPitch = 0.f;
		m_flYaw = 0.f;
		m_flRoll = 0.f;
	}


	Angle(float flX, float flY, float flZ)
	{
		this->m_flPitch = flX;
		this->m_flYaw = flY;
		this->m_flRoll = flZ;
	}


	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		m_flPitch = ix; m_flYaw = iy; m_flRoll = iz;
	}


	/* All kinds of validity checks  */
	bool IsValid()
	{
		return !isinf(m_flPitch) && !isinf(m_flYaw) && !isinf(m_flRoll);
	}

	bool IsEmpty()
	{
		return m_flYaw == 0.f && m_flPitch == 0.f && m_flRoll == 0.f;
	}


	/* Clear Angle */
	void Clear()
	{
		m_flPitch = m_flYaw = m_flRoll = 0.f;
	}

	/* Geometric Functions */

	float Length()
	{
		return (float)sqrt((this->m_flPitch * this->m_flPitch) + (this->m_flYaw * this->m_flYaw) + (this->m_flRoll * this->m_flRoll));
	}

	float DistTo(Angle& vecOther)
	{
		Angle vecDelta;

		vecDelta.m_flPitch = this->m_flPitch - vecOther.m_flPitch;
		vecDelta.m_flYaw = this->m_flYaw - vecOther.m_flYaw;
		vecDelta.m_flRoll = this->m_flRoll - vecOther.m_flRoll;

		return vecDelta.Length();
	}



	Angle& operator=(const Angle& vOther)
	{
		m_flPitch = vOther.m_flPitch; m_flYaw = vOther.m_flYaw; m_flRoll = vOther.m_flRoll;
		return *this;
	}


	/* Logical operators */
	bool operator==(const Angle& vecOther) const
	{
		return (this->m_flPitch == vecOther.m_flPitch) && (this->m_flYaw == vecOther.m_flYaw) && (this->m_flRoll == vecOther.m_flRoll);
	}

	bool operator!=(const Angle& vecOther) const
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

	Angle operator-() const
	{
		return Angle(-m_flPitch, -m_flYaw, -m_flRoll);
	}

	/* With float */
	Angle operator+(float flValue) const
	{
		return Angle(m_flPitch + flValue, m_flYaw + flValue, m_flRoll + flValue);
	}

	Angle operator-(float flValue) const
	{
		return Angle(m_flPitch - flValue, m_flYaw - flValue, m_flRoll - flValue);
	}


	Angle operator*(float flValue) const
	{
		return Angle(m_flPitch * flValue, m_flYaw * flValue, m_flRoll * flValue);
	}

	Angle operator/(float flValue) const
	{
		return Angle(m_flPitch / flValue, m_flYaw / flValue, m_flRoll / flValue);
	}

	Angle& operator+=(float flValue)
	{
		this->m_flPitch += flValue;
		this->m_flYaw += flValue;
		this->m_flRoll += flValue;

		return *this;
	}

	Angle& operator-=(float flValue)
	{
		this->m_flPitch -= flValue;
		this->m_flYaw -= flValue;
		this->m_flRoll -= flValue;

		return *this;
	}

	Angle& operator*=(float flValue)
	{
		this->m_flPitch *= flValue;
		this->m_flYaw *= flValue;
		this->m_flRoll *= flValue;

		return *this;
	}

	Angle& operator/=(float flValue)
	{
		this->m_flPitch /= flValue;
		this->m_flYaw /= flValue;
		this->m_flRoll /= flValue;

		return *this;
	}

	/* With Angle */


	Angle operator+(const Angle& vecOther) const
	{
		return Angle(m_flPitch + vecOther.m_flPitch, m_flYaw + vecOther.m_flYaw, m_flRoll + vecOther.m_flRoll);
	}

	Angle operator-(const Angle& vecOther) const
	{
		return Angle(m_flPitch - vecOther.m_flPitch, m_flYaw - vecOther.m_flYaw, m_flRoll - vecOther.m_flRoll);
	}


	Angle operator*(const Angle& vecOther) const
	{
		return Angle(m_flPitch * vecOther.m_flPitch, m_flYaw * vecOther.m_flYaw, m_flRoll * vecOther.m_flRoll);
	}

	Angle operator/(const Angle& vecOther) const
	{
		return Angle(m_flPitch / vecOther.m_flPitch, m_flYaw / vecOther.m_flYaw, m_flRoll / vecOther.m_flRoll);
	}

	Angle& operator /=(const Angle& vecOther)
	{
		this->m_flPitch /= vecOther.m_flPitch;
		this->m_flYaw /= vecOther.m_flYaw;
		this->m_flRoll /= vecOther.m_flRoll;

		return *this;
	}

	Angle& operator *=(const Angle& vecOther)
	{
		this->m_flPitch *= vecOther.m_flPitch;
		this->m_flYaw *= vecOther.m_flYaw;
		this->m_flRoll *= vecOther.m_flRoll;

		return *this;
	}

	Angle& operator -=(const Angle& vecOther)
	{
		this->m_flPitch -= vecOther.m_flPitch;
		this->m_flYaw -= vecOther.m_flYaw;
		this->m_flRoll -= vecOther.m_flRoll;

		return *this;
	}

	Angle& operator +=(const Angle& vecOther)
	{
		this->m_flPitch += vecOther.m_flPitch;
		this->m_flYaw += vecOther.m_flYaw;
		this->m_flRoll += vecOther.m_flRoll;

		return *this;
	}

};