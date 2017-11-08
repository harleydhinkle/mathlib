#include "colison.h"

Collision collides(const trans & At, const Collider & Ac, const trans & Bt, const Collider & Bc)
{
	return intersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}
