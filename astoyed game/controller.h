#pragma once
#include "transform.h"
#include "rigidbody.h"
#include "sfwdraw.h"


// Poll for input and apply changes to the rigidbody
class Controll
{

public:
	void poll(rigidbody &rb, const trans &t) {
		if (sfw::getKey('W'))rb.force += { 0, 300 };
		if (sfw::getKey('A'))rb.force += { -300, 0 };
		if (sfw::getKey('S'))rb.force += { 0, -300 };
		if (sfw::getKey('D'))rb.force += { 300, 0 };
		if (sfw::getKey('F')) { fire = true; }
		else
		{
			fire = false;
		}
	}
	bool fire = false;
};