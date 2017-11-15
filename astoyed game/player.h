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
	float lifetime = 3;
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
class enmey 
{
public:
	trans transform;
	rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
	float health = 1;
	bool enabled = false;
	vec2 force;
	void update(int & score);
	void draw();
	enmey();

};
class spawner 
{
public:
	enmey badguys[10];
	int badguyssize = 10;
	float spawnintervel;
	float starttimer;
	void update(int &score);
	void draw();
	spawner();
};
class scoremanger 
{
public:
	void draw();
	unsigned int handle = sfw::loadTextureMap("../resources/fontmap.png", 16, 16);
	int score = 0;
	void update();
};

bool doCollision2(Player&player, const Wall&wall);
bool doCollision(star &star, const Wall &wall);
bool doCollision(enmey&badguy, Player &player);
bool doCollision(enmey&badguy, star &star);