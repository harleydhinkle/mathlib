#include "transform.h"
#include "sfwdraw.h"
#include "mat3.h"
int main()
{
	sfw::initContext();
	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimenson = vec2{ 1,1 };
	while (sfw::stepContext()) 
	{
		DrawMatrix(myTransform.getLocalTransform(), 40);
		myTransform.angle  ;
	}
	sfw::termContext();
}