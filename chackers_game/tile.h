#pragma once
#include "transform.h"


class tile
{
public:
	Transform mytrans;
	int w;
	int h;
	tile();
	void draw();
};


//tile::tile()
//{
//}
//
//void tile::draw()
//{
//	sfw::drawLine(x, y, x, y + h);
//	sfw::drawLine(x, y, x + w, y);
//	sfw::drawLine(x, y + h, x + w, y + h);
//	sfw::drawLine(x + w, y, x + w, y + h);
//}