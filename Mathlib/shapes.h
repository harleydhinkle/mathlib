#pragma once
#include"vec2.h"
#include "mat3.h"
struct circle 
{
	vec2 position;
	float radius;
};

struct AABB
{
	vec2 position;
	vec2 extents;

	//FOR Points
	//position width and hight
	//min and max
};
circle operator*(const mat3&M, const circle &C);
AABB operator*(const mat3&M, const AABB &B);