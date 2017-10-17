#include "vec3.h"
#include <cmath>
#include <cfloat>
#include "mathutils.h"
vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	return result;
	/*for (int i = 0; i < 3; ++i) 
	{
		result.v[i] = lhs.v[i] + rhs.v[i];
	}*/
}

vec3 operator+=( vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON&&abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result2;
	result2.x = lhs.x - rhs.x;
	result2.y = lhs.y - rhs.y;
	result2.z = lhs.z - rhs.z;
	return result2;
}

vec3 operator-(const vec3 & lhs)
{
	vec3 result;
	result.x = lhs.x * -1;
	result.y = lhs.y * -1;
	result.z = lhs.z * -1;
	return result;
}

vec3 operator*(vec3 & lhs, const float & rhs)
{
	vec3 times;
	times.x = lhs.x *  rhs;
	times.y = lhs.y *  rhs;
	times.z = lhs.z *  rhs;
	return times;
}

vec3 operator/(vec3 & lhs, const float & rhs)
{
	vec3 div;
	div.x = lhs.x / rhs;
	div.y = lhs.y / rhs;
	div.z = lhs.z / rhs;
	return div;
}

vec3 operator/=(vec3 & lhs, const float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

vec3 operator*=(vec3 & lhs, const float & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON&&abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON)
	{
		return false;
	}
	return true;
}

float mag(const vec3 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	float cSqr = v.z * v.z;
	return sqrtf(aSqr + bSqr + cSqr);
}

vec3 norm(const vec3 & v)
{
	vec3 temp = v;
	float len = mag(v);

	temp /= len;


	return temp;
}

vec3 & normalize(vec3 & v)
{
	v = norm(v);
	return v;
}

float dot(const vec3 & a, const vec3 & b)
{
	return a.x*b.x + a.y*b.y +a.z*b.z;
}

float dist(const vec3 & a, const vec3 & b)
{
	return mag(b - a);
}

vec3 perp(const vec3 & v)
{
	return vec3{ v.y - v.x - v.z };
}

vec3 larp(const vec3 &s, const vec3 &e, float a)
{
	return s + a *(e - s);
}

vec3 min(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y );
	temp.z = min(a.z , b.z);
	return temp;
}

vec3 max(const vec3 & a, const vec3 & b)
{
	vec3 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);
	temp.z = max(a.z, b.z);

	return temp;
}

vec3 operator*(const float & lhs, vec3 & rhs)
{
	vec3 times;
	times.x = rhs.x *  lhs;
	times.y = rhs.y * lhs;
	times.z = rhs.z * lhs;
	return times;
}

vec3 clamp(const vec3 & a_min, const vec3 & v, const vec3 & a_max)
{
	return vec3();
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}
