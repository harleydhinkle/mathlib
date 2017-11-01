#pragma once

#include "transform.h"
#include "rigidbody.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class Player
{
public:
	Transform   transform;
	rigidbody   rigidbody;
	Collider    collider;
	Controller  controller;
	Sprite		sprite;
};
