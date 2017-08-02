#pragma once
#include "defines.h"
#include "vec2.h"
#include <cmath>

namespace geo
{

	inline real toRadian(real degree)
	{
		return degree / real(180) * pi;
	}
	inline real toDegree(real radian)
	{
		return radian / pi * real(180);
	}

	class angle
	{
	public:
		angle() : radian(0) {}
		angle(real r) : radian(r) {}

		real radian;

		const angle & operator+()
		{
			return *this;
		}
		angle operator-()
		{
			return -radian;
		}

		angle operator+(const angle & right)
		{
			return radian + right.radian;
		}
		angle operator-(const angle & right)
		{
			return radian - right.radian;
		}
		angle operator*(const angle & right)
		{
			return radian * right.radian;
		}
		angle operator/(const angle & right)
		{
			return radian / right.radian;
		}

		angle & operator+=(const angle & right)
		{
			radian += right.radian;
			return *this;
		}
		angle & operator-=(const angle & right)
		{
			radian -= right.radian;
			return *this;
		}
		angle & operator*=(const angle & right)
		{
			radian *= right.radian;
			return *this;
		}
		angle & operator/=(const angle & right)
		{
			radian /= right.radian;
			return *this;
		}

		vec2 operator*(const vec2 & right)
		{
			real sn = sin(radian);
			real cs = cos(radian);

			return vec2(
				right.x*cs - right.y*sn,
				right.x*sn + right.y*cs
			);
		}
		friend vec2 operator*(const vec2 & left, const angle & right)
		{
			real sn = sin(right.radian);
			real cs = cos(right.radian);

			return vec2(
				left.x*cs - left.y*sn,
				left.x*sn + left.y*cs
			);
		}

		friend vec2 & operator*=(vec2 & left, const angle & right)
		{
			real sn = sin(right.radian);
			real cs = cos(right.radian);

			left = left * right;
			return left;
		}
	
	};

}