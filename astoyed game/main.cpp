#include "sfwdraw.h"
#include "player.h"
#include "drawshapes.h"
#include "main.h"
int main()
{
	sfw::initContext();
	sfw::loadSound("../resources/stronger than you sans addison.mp3");
	Player player;

	player.sprite = sfw::loadTextureMap("../resources/Ninja (2).png");
	player.transform.dimenson = vec2{ 48, 48 };
	player.transform.position = vec2{ 400,200 };
	player.collider.box.extents = { .5,.5 };
	Wall walls[3];
	walls[0].transform.position = { 0,0 };
	walls[0].transform.dimenson = { 4000,80 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/wall.png");

	walls[1].transform.position = { 0,300 };
	walls[1].transform.dimenson = { 80,600 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = sfw::loadTextureMap("../resources/wall.png");

	walls[2].transform.position = { 300,600 };
	walls[2].transform.dimenson = { 800,80 };
	walls[2].collider.box.extents = { .5,.5 };
	walls[2].sprite.handle = sfw::loadTextureMap("../resources/wall.png");
	star star;
	while (sfw::stepContext())
	{
		
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
			doCollision(star, walls[i]);
		}

		drawAABB2(player.collider.getGlobalBox(player.transform), BLUE);
		for (int i = 0; i < 3; ++i) {
			drawAABB2(walls[i].collider.getGlobalBox(walls[i].transform), RED);
		}
		sfw::playSound(100,true);
	}
	sfw::termContext();

}