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
class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};
class Ball // dynamic rigidbody
{
public:
	Transform transform;
	rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};
bool doCollision(Player&player, const Wall&wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(Player &player, Ball &wall);