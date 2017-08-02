#pragma once
#include "defines.h"
#include <cmath>


namespace geo
{

	class vec2
	{
	public:
		//components
		real x, y;


		//constructors
		vec2()
			: x(0), y(0)
		{
		}
		vec2(const real X, const real Y)
			: x(X), y(Y)
		{
		}
		vec2(const real s)
			: x(s), y(s)
		{
		}

		//functions
		real length2()
		{
			return x*x + y*y;
		}
		real length()
		{
			return sqrt(length2());
		}
		real dot(const vec2 & right)
		{
			return x*right.x + y*right.y;
		}
		vec2 & normalize()
		{
			real n = length();

			if (n > real(0))
			{
				*this /= n;
			}

			return *this;
		}
		vec2 normalized()
		{
			vec2 ret(*this);
			ret.normalize();
			return ret;
		}

		//coperators
		const vec2 & operator+()
		{
			return *this;
		}
		vec2 operator-()
		{
			return vec2(-x, -y);
		}

		vec2 operator+(const vec2 & right)
		{
			return vec2(x + right.x, y + right.y);
		}
		vec2 operator-(const vec2 & right)
		{
			return vec2(x - right.x, y - right.y);
		}
		vec2 operator*(const vec2 & right)
		{
			return vec2(x * right.x, y * right.y);
		}
		vec2 operator/(const vec2 & right)
		{
			return vec2(x / right.x, y / right.y);
		}

		vec2 operator+(const real right)
		{
			return vec2(x + right, y + right);
		}
		vec2 operator-(const real right)
		{
			return vec2(x - right, y - right);
		}
		vec2 operator*(const real right)
		{
			return vec2(x * right, y * right);
		}
		vec2 operator/(const real right)
		{
			return vec2(x / right, y / right);
		}

		inline friend vec2 operator*(const real left, const vec2 & right)
		{
			return vec2(left * right.x, left * right.y);
		}
		inline friend vec2 operator/(const real left, const vec2 & right)
		{
			return vec2(left / right.x, left / right.y);
		}

		vec2 & operator+=(const vec2 & right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}
		vec2 & operator-=(const vec2 & right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}
		vec2 & operator*=(const vec2 & right)
		{
			x *= right.x;
			y *= right.y;
			return *this;
		}
		vec2 & operator/=(const vec2 & right)
		{
			x /= right.x;
			y /= right.y;
			return *this;
		}
		vec2 & operator*=(const real right)
		{
			x *= right;
			y *= right;
			return *this;
		}
		vec2 & operator/=(const real right)
		{
			x /= right;
			y /= right;
			return *this;
		}
	};

}