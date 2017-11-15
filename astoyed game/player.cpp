#include "player.h"
#include <random>
#include <sstream>
bool doCollision2(Player & player, const Wall & wall)
{
	auto hit = collides(player.transform, player.collider, wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		return true;
	}
	return false;
}

bool doCollision(star & star, const Wall & wall)
{
	auto hit = collides(star.transform, star.collider,
		wall.transform, wall.collider);

	if (hit.penetrationDepth > 0)
	{
		static_resolution(star.transform.position, star.rigidbody.velocity, hit);
		return true;
	}
	return false;
}

bool doCollision(enmey & badguy, Player & player)
{
	auto hit = collides(badguy.transform, badguy.collider, player.transform, player.collider);
	if (hit.penetrationDepth > 0) 
	{
		sfw::termContext();
		return true;
	}
	return false;
}

bool doCollision(enmey& badguy, star & star)
{
	auto hit = collides(badguy.transform, badguy.collider, star.transform, star.collider);
	if (hit.penetrationDepth > 0) 
	{
		badguy.health -= 1;
		/*if (badguy.health <= 0) 
		{
			badguy.enabled = false;
			

		}*/
	}
	return false;
}

void Player::shoot()
{
	float dt = sfw::getDeltaTime();
	if (controller.fire == true)
	{
		for (int i = 0; i < 100; i++) 
		{
			if (!ninjastar[i].enabled)
			{
				ninjastar[i].lifetime = 5;
				ninjastar[i].enabled= true;
				ninjastar[i].transform.position = transform.position;
				ninjastar[i].rigidbody.inpulse += { 900,0 };
				ninjastar[i].transform.dimenson = { 20,20 };
				break;
			}
		}
		
	}
	
}

void Player::update()
{
	for (int i = 0; i < 100; i++) 
	{
		if (ninjastar[i].enabled) 
		{
			ninjastar[i].update();
		}
	}
}

void Player::draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (ninjastar[i].enabled)
		{
			ninjastar[i].draw();
		}
	}
}

Player::Player()
{
	for (int i = 0; i < 100; i++) {
		ninjastar[i].sprite = sfw::loadTextureMap("../resources/star.png");
	}
}

void star::update()
{
	float dt = sfw::getDeltaTime();
	rigidbody.integraten(transform, dt);
	lifetime  -= sfw::getDeltaTime();
	collider.box.extents = { .5,.5 };
	drawAABB2(collider.getGlobalBox(transform), GREEN);
	if (lifetime <= 0) 
	{
		enabled = false;
	}
	
	
	

}

void star::draw()
{
	/*sprite = sfw::loadTextureMap("../resources/star.png");*/
	sprite.draw(transform);
	
}

void enmey::update(int&score)
{
	
		rigidbody.force += force;
		if (health < 0)
		{
			score++;
			enabled = false;

		}
		
		rigidbody.integraten(transform, sfw::getDeltaTime());
		collider.box.extents = { .5,.5 };
		drawAABB2(collider.getGlobalBox(transform), CYAN);
		
	
}

void enmey::draw()
{
	sprite.draw(transform);
	
	
}

enmey::enmey()
{ 
	sprite = sfw::loadTextureMap("../resources/zombie.png");
	health = 1;
}

void spawner::update(int&score)
{
	float dt = sfw::getDeltaTime();
	spawnintervel -= dt;
	if(spawnintervel <= 0)
	{
		for (int i = 0; i < 10; i++) 
		{
			if (!badguys[i].enabled) 
			{
				badguys[i].health = 1;
				badguys[i].enabled = true;
				int randomy = rand() % 500 + 50;
				badguys[i].transform.position = vec2{ 850,(float)randomy };
				badguys[i].transform.dimenson = { 40,40 };
				badguys[i].force = vec2{ -10,0 };
				break;
				
			}
		}
	}
	for (int i = 0; i<10; i++)
	{
		if (badguys[i].enabled)
		{
			badguys[i].update(score);
		}
	}
}



void spawner::draw()
{
	for(int i = 0; i<10;i++)
	{
		if (badguys[i].enabled == true) 
		{
			badguys[i].draw();
		}
	}
}

spawner::spawner()
{
	starttimer = 10;
	spawnintervel = starttimer;
}

void scoremanger::draw()
{
	std::string str = std::to_string(score);

	sfw::drawString(handle, str.c_str(), 50, 500, 20, 20);
}

void scoremanger::update()
{
	
}
