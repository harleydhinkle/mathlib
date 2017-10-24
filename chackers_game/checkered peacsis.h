#pragma once
#include "transform.h"
#include "board.h"
class checkersp : public board
{
public:
	checkersp();
	Transform mytrans;
	
	float radus = 20;

	virtual void update(bool &HoldingPiece);
	virtual void draw();
	bool checkCollison(float otherX, float otherY, float otherRadius);
};
