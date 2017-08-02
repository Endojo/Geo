#pragma once
#include "defines.h"
#include "vec3.h"
#include <cmath>

namespace geo
{
	class quat
	{
	public:
		//components
		real x, y, z, w;

		//constructors
		quat(real X, real Y, real Z, real W) : x(X), y(Y), z(Z), w(W)
		{
		}
		//expects the axis to be normalised
		quat(const vec3 &axis, real angle)
		{
			real sn = sin(angle / 2);
			x = axis.x * sn;
			y = axis.y * sn;
			z = axis.z * sn;
			w = cos(angle / 2);
		}

		//rotations
		vec3 operator*(const vec3 &right)
		{
			// vector part of the quaternion
			vec3 u(x, y, z);

			return 2.0f * u.dot(right) * u
				+ (w*w - u.length2()) * right
				+ 2.0f * w * u.cross(right);
		}
		friend vec3 operator*(const vec3 &left, const quat& right)
		{
			// vector part of the quaternion
			vec3 u(x, y, z);

			return 2.0f * u.dot(left) * u
				+ (right.w*right.w - u.length2()) * left
				+ 2.0f * right.w * u.cross(left);
		}
		
		quat slerp(quat right, real t)
		{
			real d = dot(right);

			// If the dot product is negative, the quaternions
			// have opposite handed-ness and slerp won't take
			// the shorter path. Fix by reversing one quaternion.
			if (d < real(0.f)) {
				right = -right;
				d = -d;
			}

			real theta_0 = acos(d);  // theta_0 = angle between input vectors
			real theta = theta_0*t;    // theta = angle between v0 and result 

			quat v2 = right – (*this)*right;
			v2.normalize();              // { v0, v2 } is now an orthonormal basis

			return (*this)*cos(theta) + v2*sin(theta);
		}

		//functions
		real length2()
		{
			return x*x + y*y + z*z + w*w;
		}
		real length()
		{
			return sqrt(length2());
		}
		real dot(const quat & right)
		{
			return x*right.x + y*right.y + z*right.z + w*right.w;
		}
		quat & normalize()
		{
			real n = length();

			if (n > real(0))
			{
				*this /= n;
			}

			return *this;
		}
		quat normalized()
		{
			quat ret(*this);
			ret.normalize();
			return ret;
		}

		//operators
		const quat & operator+()
		{
			return *this;
		}
		//inverts the direction
		quat operator-()
		{
			return quat(-x, -y, -z, w);
		}

		quat operator+(const quat & right)
		{
			return quat(x + right.x, y + right.y, z + right.z, w + right.w);
		}
		quat operator-(const quat & right)
		{
			return quat(x - right.x, y - right.y, z - right.z, w - right.w);
		}
		quat operator*(const quat & right)
		{
			return quat(x * right.x, y * right.y, z * right.z, w*right.w);
		}
		quat operator/(const quat & right)
		{
			return quat(x / right.x, y / right.y, z / right.z, w / right.w);
		}

		quat operator*(const real right)
		{
			return quat(x * right, y * right, z * right, w*right);
		}
		inline friend quat operator*(const real left, const quat & right)
		{
			return quat(left * right.x, left * right.y, left * right.z);
		}

		quat & operator+=(const quat & right)
		{
			x += right.x;
			y += right.y;
			z += right.z;
			w += right.w;
			return *this;
		}
		quat & operator-=(const quat & right)
		{
			x -= right.x;
			y -= right.y;
			z -= right.z;
			w -= right.w;
			return *this;
		}
		quat & operator*=(const quat & right)
		{
			x *= right.x;
			y *= right.y;
			z *= right.z;
			w *= right.w;
			return *this;
		}
		quat & operator/=(const quat & right)
		{
			x /= right.x;
			y /= right.y;
			z /= right.z;
			w /= right.w;
			return *this;
		}

		quat & operator*=(const real right)
		{
			x *= right;
			y *= right;
			z *= right;
			w *= right;
			return *this;
		}
		quat & operator/=(const real right)
		{
			x /= right;
			y /= right;
			z /= right;
			w /= right;
			return *this;
		}
	};
}