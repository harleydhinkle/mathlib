#pragma once
#include "transform.h"
#include "rigidbody.h"
#include "Colison.h"
#include "Controller.h"
#include "Sprite.h"
#include "drawshapes.h"
class star // dynamic rigidbody
{
public:
	trans transform;
	rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
	bool enabled = false;
	void update();
	void draw();
	float lifetime = 5;
};
class Player
{
public:
	trans   transform;
	rigidbody   rigidbody;
	Collider    collider;
	star ninjastar[100];
	Controll  controller;
	Sprite		sprite;
	void shoot();
	void update();
	void draw();
	Player();
};
class Wall
{
public:
	trans transform;
	Collider collider;
	Sprite sprite;
};

bool doCollision2(Player&player, const Wall&wall);
bool doCollision(star &star, const Wall &wall);