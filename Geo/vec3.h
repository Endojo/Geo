#pragma once
#include "defines.h"
#include <cmath>


namespace geo
{

	class vec3
	{
	public:
		//components
		real x, y, z;

		
		//constructors
		vec3()
			: x(0), y(0), z(0)
		{
		}
		vec3(const real X, const real Y, const real Z)
			: x(X), y(Y), z(Z)
		{
		}
		vec3(const real s)
			: x(s), y(s), z(s)
		{
		}

		//functions
		real length2()
		{
			return x*x + y*y + z*z;
		}
		real length()
		{
			return sqrt(length2());
		}
		real dot(const vec3 & right)
		{
			return x*right.x + y*right.y + z*right.z;
		}
		vec3 cross(const vec3 & right)
		{
			return vec3(
				y*right.z - z*right.y,
				z*right.x - x*right.z,
				x*right.y - y*right.x
			);
		}
		vec3 & normalize()
		{
			real n = length();
			
			if (n > real(0))
			{
				*this /= n;
			}

			return *this;
		}
		vec3 normalized()
		{
			vec3 ret(*this);
			ret.normalize();
			return ret;
		}

		//operators
		const vec3 & operator+()
		{
			return *this;
		}
		vec3 operator-()
		{
			return vec3(-x, -y, -z);
		}

		vec3 operator+(const vec3 & right)
		{
			return vec3(x + right.x, y + right.y, z + right.z);
		}
		vec3 operator-(const vec3 & right)
		{
			return vec3(x - right.x, y - right.y, z - right.z);
		}
		vec3 operator*(const vec3 & right)
		{
			return vec3(x * right.x, y * right.y, z * right.z);
		}
		vec3 operator/(const vec3 & right)
		{
			return vec3(x / right.x, y / right.y, z / right.z);
		}

		vec3 operator*(const real right)
		{
			return vec3(x * right, y * right, z * right);
		}
		vec3 operator/(const real right)
		{
			return vec3(x / right, y / right, z / right);
		}

		inline friend vec3 operator*(const real left, const vec3 & right)
		{
			return vec3(left * right.x, left * right.y, left * right.z);
		}

		vec3 & operator+=(const vec3 & right)
		{
			x += right.x;
			y += right.y;
			z += right.z;
			return *this;
		}
		vec3 & operator-=(const vec3 & right)
		{
			x -= right.x;
			y -= right.y;
			z -= right.z;
			return *this;
		}
		vec3 & operator*=(const vec3 & right)
		{
			x *= right.x;
			y *= right.y;
			z *= right.z;
			return *this;
		}
		vec3 & operator/=(const vec3 & right)
		{
			x /= right.x;
			y /= right.y;
			z /= right.z;
			return *this;
		}

		vec3 & operator*=(const real right)
		{
			x *= right;
			y *= right;
			z *= right;
			return *this;
		}
		vec3 & operator/=(const real right)
		{
			x /= right;
			y /= right;
			z /= right;
			return *this;
		}
	};

}