#include "mat3.h"
#include <cmath>
#include <cfloat>
#include "vec3.h"
bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];
}
mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 add;
	for (int i = 0; i < 9; ++i)
	{
		add.m[i] = A.m[i] + B.m[i];
	}
	return add;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	mat3 sub;
	for (int i = 0; i < 9; ++i)
	{
		sub.m[i] = A.m[i] + B.m[i];
	}
	return sub;
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval;
	/*for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			retval[i][j] = dot(vec3{A[0][j],A[1][j],A[2][j]}b[i]);
		}
	}*/
	mat3 At = transpose(A);
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			retval[i][j] = dot(At[j], B[i]);
		}
	}
	return retval;
}

vec3 operator*(const mat3 & A, const vec3 & B)
{
	mat3 At = transpose(A);
	return vec3{ dot(At[0], B),
				 dot(At[1], B),
				 dot(At[2], B) };
}

mat3 transpose(const mat3 & A)
{
	mat3 retval;
	for (int x = 0; x < 3; ++x) 
	{
		for (int y = 0; y < 3; ++y) 
		{
			retval[x][y] = A[y][x];
		}
	}
	return retval;
}

float determainant(const mat3 & A)
{
	return dot(A[0], cross(A[1], A[2]));
}

mat3 inverse(const mat3 & A)
{
	float di = 1 / determainant(A);
	return mat3{cross(A[1], A[2])*di,cross(A[2], A[0])*di , cross(A[0], A[1])*di };
}

mat3 translate(const vec2 & t)
{
	mat3 retval = mat3::identity();
	retval[2].xy = t;
	return retval;
}
mat3 scale(const vec2 & s)
{
	return mat3{s.x, 0,0,0,s.y,0,0,  0,1};
}
mat3 rotate(float deg)
{
	float rad = deg * 0.0174533;
	return mat3{cos(rad),sin(rad),0,-sin(rad),cos(rad),0,0,0,1};
}

vec3 & mat3::operator[](size_t idx)
{
	return c[idx];
}

const vec3 & mat3::operator[](size_t idx) const
{
	return c[idx];
}

mat3 mat3::identity()
{
	return{ 1,0,0,
			0,1,0,
			0,0,1 };
}

mat3 mat3::zero()
{
	return{ 0,0,0,
			0,0,0,
			0,0,0};
}
