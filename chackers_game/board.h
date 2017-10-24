#pragma once
#include "transform.h"
#include "tile.h"
class board
{
public:
	tile tiles[100];
	float endX;
	float endY;
	Transform mytrans;
	float h;
	float w;
	board();
	void update();
	void draw();
};
