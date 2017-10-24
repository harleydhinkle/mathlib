#include "board.h"
#include "sfwdraw.h"
board::board()
{
	h = 800 / 8;
	w = 800 / 8;
	mytrans.position = vec2{ 0, 0 };
	mytrans.position.x = 0;
	mytrans.position.y = 0;
	for (int i = 0; i < 9; i++)
	{
		mytrans.position.y = i * h;
		mytrans.position.x = i * w;

		for (int j = 0; j < 9; j++)
		{

			tiles[j + (i * 9)].mytrans.position.x = j*w;
			tiles[j + (i * 9)].mytrans.position.y = i*h;
			tiles[j + (i * 9)].h = h;
			tiles[j + (i * 9)].w = w;
			/*tiles[j + (i * 9)].w = j*w;
			tiles[j + (i * 9)].h = x;*/
			/*tiles[i].w = j*h;
			tiles[i].h = y;
			tiles[i].y = j*w;
			tiles[i].x = x;*/
		}
	}
}

void board::update()
{

}

void board::draw()
{
	//draw board
	for (int i = 0; i < 100; i++)
	{
		tiles[i].draw();
	}

}
