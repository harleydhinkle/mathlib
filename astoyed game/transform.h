#pragma once
#include "vec2.h"
#include "mat3.h"
class trans 
{
public:
	vec2 position;
	vec2 dimenson;
	float angle;
	trans *e_parent;
	trans(vec2 a_pos = { 0,0 }, vec2 a_dim = { 1,1 }, float a_ang = 0);

	mat3 getLocalTransform()const;
	mat3 getGlobalTransform() const;
};
void DrawMatrix(const mat3&t, float drawing_scale);