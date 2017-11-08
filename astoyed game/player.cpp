#include "player.h"

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
				ninjastar[i].enabled=true;
				ninjastar[i].transform.position = transform.position;
				ninjastar[i].rigidbody.force = { 3000,0 };
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
	sprite = sfw::loadTextureMap("../resources/star.png");
	sprite.draw(transform);
	
}
