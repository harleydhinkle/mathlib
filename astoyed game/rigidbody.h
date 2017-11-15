#pragma once
#include "vec2.h"
#include"transform.h"
class rigidbody
{
public:
	float mass, drag;
	vec2 velocity, acceleration, force, inpulse;
	float angulerVelocity, angelerAcceleration, torque;
	float anglerDrag;
	rigidbody() :velocity{ 0,0 }, acceleration{ 0,0 }, force{ 0,0 }, inpulse{ 0,0 }, mass(1), drag(1), angelerAcceleration(0), angulerVelocity(0), torque(0), anglerDrag(.25f)
	{

	}
	void integraten(trans&T, float dt)
	{
		acceleration = force / mass;
		T.position += velocity*dt;
		velocity += acceleration*dt + inpulse / mass;
		inpulse = { 0,0 };
		force = -velocity *drag;
		angelerAcceleration = torque / mass;
		angulerVelocity += angelerAcceleration*dt;
		T.angle += angulerVelocity*dt;
		torque = angulerVelocity*anglerDrag;

	}
};
