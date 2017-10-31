#include "transform.h"
#include "sfwdraw.h"
#include "mat3.h"
#include "rigidbody.h"
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
int main()
{
	sfw::initContext();
	/*Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimenson = vec2{ 1,1 };*/
	Transform transform;
	rigidbody rigidbody;
	transform.position = vec2{ 400,600 };
	transform.dimenson = vec2{ 1,1 };
	/*rigidbody.velocity = normalize(vec2{ 800,600 });*/
	while (sfw::stepContext()) 
	{
		float dt = sfw::getDeltaTime();
		/*rigidbody.force = { 0,-10 };*/
		/*rigidbody.integraten(transform, dt);*/
		/*if (sfw::getKey('W'))rigidbody.force += { 0,100 };
		if (sfw::getKey('A'))rigidbody.force += { -100,0 };
		if (sfw::getKey('S'))rigidbody.force += { 0,-100 };
		if (sfw::getKey('D'))rigidbody.force += { 100,0 };*/
		if (sfw::getKey('W'))rigidbody.force +=
			transform.getGlobalTransform()[1].xy * 200;
		if (sfw::getKey('A'))rigidbody.torque += 360;
		if (sfw::getKey('D'))rigidbody.torque += -360;
		if(sfw::getKey('Q')) rigidbody.inpulse +=
			-transform.getGlobalTransform()[1].xy * 10;
		if (sfw::getKey(' ')) //breaking force
		{
			rigidbody.force += -rigidbody.velocity * 20;
			rigidbody.torque += -rigidbody.angulerVelocity * 20;
		}

		rigidbody.integraten(transform, dt);
		DrawMatrix(transform.getGlobalTransform(), 30);
		/*DrawMatrix(myTransform.getLocalTransform(), 40);
		myTransform.angle += sfw::getDeltaTime()*180;*/
		
	}
	sfw::termContext();
}