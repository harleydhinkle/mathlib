#include "tile.h"
#include "sfwdraw.h"
tile::tile()
{
	
}

void tile::draw()
{
	
	//draw tiles for each think
	sfw::drawLine(mytrans.position.x,mytrans.position.y,mytrans.position.x, mytrans.position.y + h,BLUE);
	sfw::drawLine(mytrans.position.x, mytrans.position.y, mytrans.position.y + w, mytrans.position.y,RED);
	sfw::drawLine(mytrans.position.x, mytrans.position.y + h, mytrans.position.x + w, mytrans.position.y + h,BLUE);
	sfw::drawLine(mytrans.position.x + w, mytrans.position.y, mytrans.position.x + w, mytrans.position.y + h,RED);
}
//tiles[i].w = j*w;
//tiles[i].h = y;
//tiles[i].y = j*h;
//tiles[i].x = x;