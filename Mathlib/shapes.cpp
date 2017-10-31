#include "shapes.h"
#include<cmath>
circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;
	ret.position = (M*vec3{ C.position.x,C.position.y,1.f}).xy;
	vec2 scele;
	scele.x = mag(M[0].xy);
	scele.y = mag(M[1].xy);
	ret.radius *= fmaxf(scele.x, scele.y);
	return ret;
}

AABB operator*(const mat3 & M, const AABB & B)
{
	vec2 b = B.position + B.extents;
	vec2 c = B.position + B.extents;
	vec2 A = vec2{ c.x,b.y };
	vec2 D = vec2{ b.x,c.y };
}
