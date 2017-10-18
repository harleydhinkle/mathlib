#include"mathutils.h"
#include "vec2.h"
#include "mat3.h"
#include <iostream>
#include <cmath>
#include <cfloat>
#include "vec3.h"
#include <cassert>
int main() 
{
	int val = min(1, 3);
	vec2 test;
	test.x = 5;
	test.y = 20;
	vec2 testB;
	testB.x = 13;
	testB.y = 4;
	vec2 result = test + testB;
	vec2 testC;
	testC.x = 5;
	testC.y = 20;
	vec2 testD;
	testD.x = 13;
	testD.y = 4;
	vec2 result2 = testC - testD;
	vec2 times;
	times.x = 2;
	times.y = 2;
	vec2 timesresout;
	timesresout = times * 3;
	vec2 times2;
	times2.x = 3;
	times2.y = 3;
	vec2 times2resout;
	times2resout =  3 * times2;
	vec2 div;
	div.x = 6;
	div.y = 6;
	vec2 divresout;
	divresout = div / 2;
	vec2 num;
	num.x = 0;
	num.y = 0;
	num += test;
	bool   eq = num == test;
	bool ieq = num == testB;
	mat3 I = mat3::identity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	vec3 V = { 1,2,3 };
	assert(I + Z == I);
	assert(I + Z == I);
	assert(I - Z == I);
	assert(!(Z - I == I));
	assert(transpose(I) == I);
	assert(A*I == A);
	assert(A*I == A);
	assert(I*V == V);
	assert(inverse(I) == I);
	mat3 T = scale(vec2{ 1,2 })*rotate(90)*translate(vec2{ 3,0 });
	assert((T[2].xy == vec2{ 0,6 }));
	while (true){}
}