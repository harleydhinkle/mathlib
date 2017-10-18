#pragma once
#include "vec3.h"
union mat3 
{
	vec3 c[3];
	float m[9];
	float mm[3][3];
	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;
	static mat3 identity();
	static mat3 zero();

};
bool operator==(const mat3 &A, const mat3 &B);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &V);
mat3 transpose(const mat3 &A);
float determainant(const mat3 &A);
mat3 inverse(const mat3 &A);
mat3 translate(const vec2 &t);
mat3 scale(const vec2 &s);
mat3 rotate(float deg);