#include "sfwdraw.h"
#include "player.h"
#include "drawshapes.h"
#include "main.h"

int main()
{
	
	sfw::initContext(900,600, "game");
	Player player;

	player.sprite = sfw::loadTextureMap("../resources/Ninja (2).png");
	player.transform.dimenson = vec2{ 48, 48 };
	player.transform.position = vec2{ 400,200 };
	player.collider.box.extents = { .5,.5 };

	Wall walls[3];
	walls[0].transform.position = { 0,0 };
	walls[0].transform.dimenson = { 3000,80 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/wall.png");

	walls[1].transform.position = { 0,300 };
	walls[1].transform.dimenson = { 80,600 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = sfw::loadTextureMap("../resources/wall.png");

	walls[2].transform.position = { 300,600 };
	walls[2].transform.dimenson = { 900,80 };
	walls[2].collider.box.extents = { .5,.5 };
	walls[2].sprite.handle = sfw::loadTextureMap("../resources/wall.png");
	star star;
	/*unsigned int handle = sfw::loadTextureMap("../resources/fontmap.png", 16, 16);
	enmey badguy[10];*/
	/*badguy.sprite = sfw::loadTextureMap("../resources/zombie.png");
	badguy.health = 1;
	badguy.enabled = true;
	badguy.transform.position = vec2{ 400,400 };
	badguy.transform.dimenson = { 40,40 };
	badguy.force = vec2{ -10,0 };*/
	spawner spawnbadguys;
	scoremanger scoreboard;
	while (sfw::stepContext())
	{
	/*	sfw::drawString(handle, "score", 400, 500, 100, 100);*/
		float dt = sfw::getDeltaTime();
		player.controller.poll(player.rigidbody, player.transform);
		player.rigidbody.integraten(player.transform, dt);
		player.shoot();
		player.update();
		player.draw();
		player.sprite.draw(player.transform);
		for (int i = 0; i < 3; ++i)
			walls[i].sprite.draw(walls[i].transform);
		for (int i = 0; i < 3; ++i)
		{
			doCollision2(player, walls[i]);
			for (int j = 0; j < 100; j++) {
				doCollision(player.ninjastar[j], walls[i]);
			}
		}
		for ( int i= 0; i < 10; i++)
		{
			//doCollision(spawnbadguys.badguys[i], star);
			doCollision(spawnbadguys.badguys[i], player);
			for (int j = 0; j < 100; j++)
			{
				if (spawnbadguys.badguys[i].enabled && player.ninjastar[j].enabled)
				{
					doCollision(spawnbadguys.badguys[i], player.ninjastar[j]);
				}
			}
		}
		
		
		/*badguy.draw();
		badguy.update();*/
		spawnbadguys.draw();
		spawnbadguys.update(scoreboard.score);
		scoreboard.draw();
		drawAABB2(player.collider.getGlobalBox(player.transform), BLUE);
		for (int i = 0; i < 3; ++i) {
			drawAABB2(walls[i].collider.getGlobalBox(walls[i].transform), RED);
		}
	}
	sfw::termContext();

}