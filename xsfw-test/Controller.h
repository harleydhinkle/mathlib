#pragma once
#include "transform.h"
#include "rigidbody.h"
#include "sfwdraw.h"

// Poll for input and apply changes to the rigidbody
class Controller
{

public:
	void poll(rigidbody &rb, const Transform &t)
	{

		if (sfw::getKey('W'))rb.force +=
			t.getGlobalTransform()[1].xy * 100;

		if (sfw::getKey('A'))rb.torque += 360;
		if (sfw::getKey('D'))rb.torque += -360;

		if (sfw::getKey('Q')) rb.inpulse +=
			-t.getGlobalTransform()[1].xy * 10;

		if (sfw::getKey(' ')) //breaking force
		{
			rb.force += -rb.velocity * 20;
			rb.torque += -rb.angelerAcceleration * 20;
		}
	}
};