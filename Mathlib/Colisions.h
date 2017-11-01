#pragma once
#include "mathutils.h"
#include "shapes.h"
#include <cmath>

struct Collision
{
	float penetrationDepth; // if penetration depth is negative, that's the distance
	float handedness;		// does A need to move left or right along the axis
	vec2  axis;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity = 1.0f);
void dynamic_resolution(vec2 &Apos, vec2&Avel, float Amass, vec2&Bpos, vec2 &Bvel, float Bmass, const Collision&hit, float elasticty);