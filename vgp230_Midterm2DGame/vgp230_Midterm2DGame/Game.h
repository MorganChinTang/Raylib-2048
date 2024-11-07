#include "raylib.h"
#include <vector>

#ifndef GAME_H
#define GAME_H
using namespace std;

class Game
{
public:
#define GAP_SIZE 16
#define TILE_SIZE 128
#define GRID_SIZE 4
#define WORLD_SIZE (GRID_SIZE * GRID_SIZE)
#define FONT_SIZE 40

#define TWO CLITERAL(Color){255,240,225,255}
#define FOUR CLITERAL(Color){245,223,200,255}
#define EIGHT CLITERAL(Color){240,179,122,255}
#define SIXTEEN CLITERAL(Color){245,149,99,255}
#define THIRTWO CLITERAL(Color){251,121,99,255}
#define SIXFOUR CLITERAL(Color){248,95,63,255}
#define ONETEIGHT CLITERAL(Color){236,205,112,255}
#define TWOFSIX CLITERAL(Color){230,195,43,255}
#define FIVEONET CLITERAL(Color){242,202,110,255}
#define TENTWOFOUR CLITERAL(Color){237,76,90,255}
#define LIGHT_BROWN CLITERAL(Color){186,165,145,255}
#define GRAY_BROWN CLITERAL(Color){135,120,110,255}

	// width and height of canvas
	const int wWindow = TILE_SIZE * GRID_SIZE + GAP_SIZE * (GRID_SIZE + 1);
	const int hWindow = TILE_SIZE * GRID_SIZE + GAP_SIZE * (GRID_SIZE + 1);
	int world[WORLD_SIZE];
	Color bgColor = GRAY_BROWN;
	
	bool gameFinished = false;
	void Main();
	void Start();
	void Draw();
	void Update();
};

#endif 