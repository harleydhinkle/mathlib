#pragma once
#include "shapes.h"
#include "transform.h"
#include"Colisions.h"
class Collider
{
public:
	AABB box;

	AABB getGlobalBox(const trans &t) const
	{
		return t.getGlobalTransform() * box;
	}

	Collider(const AABB &a_box = { { 0,0 },{ 1,1 } }) : box(a_box)
	{

	}
};

Collision collides(const trans &At, const Collider &Ac, const trans &Bt, const Collider &Bc);