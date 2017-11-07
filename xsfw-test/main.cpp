//#include "transform.h"
//#include "sfwdraw.h"
//#include "mat3.h"
//#include "rigidbody.h"
//#include <cmath>
//#include <string>
//#include <cstring>
//#include <cassert>
//int main()
//{
////	sfw::initContext();
////	/*Transform myTransform;
////	myTransform.position = vec2{ 300,400 };
////	myTransform.dimenson = vec2{ 1,1 };*/
////	Transform transform;
////	rigidbody rigidbody;
////	transform.position = vec2{ 400,600 };
////	transform.dimenson = vec2{ 1,1 };
////	/*rigidbody.velocity = normalize(vec2{ 800,600 });*/
////	while (sfw::stepContext()) 
////	{
////		float dt = sfw::getDeltaTime();
////		/*rigidbody.force = { 0,-10 };*/
////		/*rigidbody.integraten(transform, dt);*/
////		/*if (sfw::getKey('W'))rigidbody.force += { 0,100 };
////		if (sfw::getKey('A'))rigidbody.force += { -100,0 };
////		if (sfw::getKey('S'))rigidbody.force += { 0,-100 };
////		if (sfw::getKey('D'))rigidbody.force += { 100,0 };*/
////		if (sfw::getKey('W'))rigidbody.force +=
////			transform.getGlobalTransform()[1].xy * 200;
////		if (sfw::getKey('A'))rigidbody.torque += 360;
////		if (sfw::getKey('D'))rigidbody.torque += -360;
////		if(sfw::getKey('Q')) rigidbody.inpulse +=
////			-transform.getGlobalTransform()[1].xy * 10;
////		if (sfw::getKey(' ')) //breaking force
////		{
////			rigidbody.force += -rigidbody.velocity * 20;
////			rigidbody.torque += -rigidbody.angulerVelocity * 20;
////		}
////
////		rigidbody.integraten(transform, dt);
////		DrawMatrix(transform.getGlobalTransform(), 30);
////		/*DrawMatrix(myTransform.getLocalTransform(), 40);
////		myTransform.angle += sfw::getDeltaTime()*180;*/
////		
////	}
////	sfw::termContext();
//
//}
#include "sfwdraw.h"
#include "Player.h"
#include "DrawSapes.h"


int main()
{
	sfw::initContext();


	Player player;

	player.sprite = sfw::loadTextureMap("../resources/girl.jpg");
	player.transform.dimenson = vec2{ 48, 48 };
	player.transform.position = vec2{ 400,200 };
	player.collider.box.extents = { .5,.5 };
	Wall walls[2];
	walls[0].transform.position = { 600,300 };
	walls[0].transform.dimenson= { 80,240 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	walls[1].transform.position = { 200,300 };
	walls[1].transform.dimenson = { 80,240 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");
	Ball ball;
	ball.transform.position = { 400,300 };
	ball.sprite.handle = sfw::loadTextureMap("../resources/Gungeon.jpg");
	ball.transform.dimenson = { 32,32 };
	ball.collider.box.extents = { .5,.5 };
	ball.rigidbody.velocity = { 200,0 };
	ball.rigidbody.drag = 0;


	while (sfw::stepContext())
	{

		float dt = sfw::getDeltaTime();

		// update controllers0
		player.controller.poll(player.rigidbody, player.transform);

		// update rigibodies
		player.rigidbody.integraten(player.transform, dt);
		ball.rigidbody.integraten(ball.transform, dt);

		// draw stuff
		player.sprite.draw(player.transform);
		ball.sprite.draw(ball.transform);
		for (int i = 0; i < 2; ++i)
			walls[i].sprite.draw(walls[i].transform);

		// Collision resolution
		for (int i = 0; i < 2; ++i)
		{
			doCollision(player, walls[i]);
			doCollision(ball, walls[i]);
		}

		doCollision(player, ball);

		// Debug boxes
		drawAABB(player.collider.getGlobalBox(player.transform), BLUE);
		for (int i = 0; i < 2; ++i){
			drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
		}
	}

	sfw::termContext();
}
