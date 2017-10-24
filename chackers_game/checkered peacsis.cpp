#include "checkered peacsis.h"
#include "sfwdraw.h"
#include<iostream>
#include <cmath>
checkersp::checkersp()
{

}
bool checkersp::checkCollison(float otherX, float otherY, float otherRadius)
{
	
	//float dis = sqrt((otherX - x) *(otherX - x) + (otherY - y) * (otherY - y));
	float dis = dist(mytrans.position, vec2{ sfw::getMouseX(), sfw::getMouseY() });
	if (dis < radus + otherRadius)
	{

		return true;
	}
	else
	{
		return false;
	}
	/*checkCollison() == false;*/
}
void checkersp::update(bool &HoldingPiece)
{
	//float dis = (x2-x)*2+(y2-y)*2;


	if (checkCollison(sfw::getMouseX(), sfw::getMouseY(), 20))
	{
		if (sfw::getMouseButton(0) == true && HoldingPiece == false)
		{
			mytrans.position.x = sfw::getMouseX();
			mytrans.position.y = sfw::getMouseY();
			HoldingPiece = true;
		}
		else
		{
			HoldingPiece = false;
		}
		/*else
		{

		}*/
	}

}

void checkersp::draw()
{
	sfw::drawCircle(mytrans.position.x, mytrans.position.y, radus, 12, RED);
	//for (int i = 0; i < 12; i++) 
	//{
	//	/*sfw::drawCircle(tiles[i].x, tiles[i].y , 20);*/
	//	
	//	sfw::drawCircle(tiles[i].x + x, tiles[i].y + x, radus,12,RED);
	//	for (int j = 0; j < 12; j++)
	//	{
	//		/*sfw::drawCircle(tiles[i].x, tiles[i].y , 20);*/

	//		sfw::drawCircle(tiles[j].x + x, tiles[j].y + 800 - y - 100, radus, 12, BLACK);
	//	}
	//}
}
