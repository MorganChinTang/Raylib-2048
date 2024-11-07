#include "Game.h"
#include <time.h>
#include <string>

//Choose Color depending on number
Color map_color(int number) {
	switch (number) {
	case 2: return TWO;
	case 4: return FOUR;
	case 8: return EIGHT;
	case 16: return SIXTEEN;
	case 32: return THIRTWO;
	case 64: return SIXFOUR;
	case 128: return ONETEIGHT;
	case 256: return TWOFSIX;
	case 512: return FIVEONET;
	case 1024: return TENTWOFOUR;
	case 2048: return RED;
	default: return LIGHT_BROWN;
	}
}
//convert int to string
const char* map_text(int number) {
    switch (number) {
    case 2: return "2";
    case 4: return "4";
    case 8: return "8";
    case 16: return "16";
    case 32: return "32";
    case 64: return "64";
    case 128: return "128";
    case 256: return "256";
    case 512: return "512";
    case 1024: return "1024";
    case 2048: return "2048";
    default: return "";
    }
}

void Game::Main()
{
	Start();
	InitWindow(wWindow, hWindow, "2048 Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(bgColor);
		Update();
		Draw();
		EndDrawing();
	}
	CloseWindow();
}

void Game::Start()
{
	//Start the game with 2 tiles

	int index1 = rand() % WORLD_SIZE;
	int index2 = rand() % WORLD_SIZE;
	//populate with 0 as default
	for (int i = 0; i < WORLD_SIZE; i++) {
		world[i] = 0;
	}

	//add number
	world[index1] = 2;
	world[index2] = 4;
}

void Game::Draw()
{
	//loop through all tiles
	for (int row = 0; row < GRID_SIZE; row++) {
		for (int col = 0; col < GRID_SIZE; col++) {
			int index = row * GRID_SIZE + col; 
			int number = world[index];
			//x and y pos of tile
			int pos_x = col * TILE_SIZE + (col + 1) * GAP_SIZE; 
			int pos_y = row * TILE_SIZE + (row + 1) * GAP_SIZE;
			DrawRectangle(pos_x, pos_y, TILE_SIZE, TILE_SIZE, map_color(number));

			DrawRectangle(pos_x, pos_y, TILE_SIZE, TILE_SIZE, map_color(number));

			int width = MeasureText(map_text(number), FONT_SIZE);
		
			//draw text
			DrawText(map_text(number),
					pos_x + TILE_SIZE / 2 - width / 2,
					pos_y + TILE_SIZE / 2 - FONT_SIZE / 2,
					FONT_SIZE, DARKGRAY);
		}
	}
}

void Game::Update()
{
	if (IsKeyPressed(KEY_DOWN)) {
	
		for (int col = 0; col < GRID_SIZE; col++) {
			int slice[GRID_SIZE] = { 0 };
			//Slide all tiles from the column (bottom to top)
			for (int row = GRID_SIZE - 1, i = 0; row >= 0; row--) {
				int index = row * GRID_SIZE + col;
				if (world[index] != 0) {
					slice[i++] = world[index];
				}
			}

			//merge equal tiles
			for (int i = 0; i < GRID_SIZE - 1; i++) {
				if (slice[i] == slice[i + 1]) {
					slice[i] = slice[i] + slice[i + 1];
					// Shift the remaining tiles to the left
					for (int j = i + 1; j < GRID_SIZE - 1; j++) {
						slice[j] = slice[j + 1];
					}
					slice[GRID_SIZE - 1] = 0;
				}
			}

			// Place the merged tiles back into the world
			for (int row = GRID_SIZE - 1, i = 0; row >= 0; row--) {
				int index = row * GRID_SIZE + col;
				world[index] = slice[i++];
			}
		}
		int length = 0;
		// Count how many cells are empty
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				length++;
			}
		}

		//Add new number
		if (length == 0) {
			return;
		}
		// Select a random empty cell
		int index = rand() % length;
		int j = 0;
		// Place a new tile at the selected empty position
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				if (index == j) {
					world[i] = 2;
					break;
				}
				j++;
			}
		}
	}

	else if (IsKeyPressed(KEY_UP)) {
		for (int col = 0; col < GRID_SIZE; col++) {
			int slice[GRID_SIZE] = { 0 };
			//Slide all tiles from the column (top to bottom)
			for (int row = 0, i = 0; row < GRID_SIZE; row++) {
				int index = row * GRID_SIZE + col;
				if (world[index] != 0) {
					slice[i++] = world[index];
				}
			}

			//merge equal tiles
			for (int i = 0; i < GRID_SIZE - 1; i++) {
				if (slice[i] == slice[i + 1]) {
					slice[i] = slice[i] + slice[i + 1];
					// Shift the remaining tiles to the left
					for (int j = i + 1; j < GRID_SIZE - 1; j++) {
						slice[j] = slice[j + 1];
					}
					slice[GRID_SIZE - 1] = 0;
				}
			}

			// Place the merged tiles back into the world
			for (int row = 0, i = 0; row < GRID_SIZE; row++) {
				int index = row * GRID_SIZE + col;
				world[index] = slice[i++];
			}
		}

		//Add New num
		int length = 0;
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				length++;
			}
		}

		if (length == 0) {
			return;
		}
		// Select a random empty cell
		int index = rand() % length;
		int j = 0;
		// Place a new '2' tile at the selected empty position
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				if (index == j) {
					world[i] = 2;
					break;
				}
				j++;
			}
		}
	}

	else if (IsKeyPressed(KEY_LEFT)) {
		for (int row = 0; row < GRID_SIZE; row++) {
			int slice[GRID_SIZE] = { 0 };
			//Slide all tiles from the column (left to right)
			for (int col = 0, i = 0; col < GRID_SIZE; col++) {
				int index = row * GRID_SIZE + col;
				if (world[index] != 0) {
					slice[i++] = world[index];
				}
			}
			//Merge equal number
			for (int i = 0; i < GRID_SIZE - 1; i++) {
				if (slice[i] == slice[i + 1]) {
					slice[i] = slice[i] + slice[i + 1];
					// Shift the remaining tiles to the left
					for (int j = i + 1; j < GRID_SIZE - 1; j++) {
						slice[j] = slice[j + 1];
					}
					slice[GRID_SIZE - 1] = 0;
				}
			}
			// Place the merged tiles back into the world
			for (int col = 0, i = 0; col < GRID_SIZE; col++) {
				int index = row * GRID_SIZE + col;
				world[index] = slice[i++];
			}
		}
		int length = 0;
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				length++;
			}
		}

		//Add new number
		if (length == 0) {
			return;
		}
		int index = rand() % length;
		int j = 0;
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				if (index == j) {
					world[i] = 2;
					break;
				}
				j++;
			}
		}
	}

	else if (IsKeyPressed(KEY_RIGHT)) {
		for (int row = 0; row < GRID_SIZE; row++) {
			int slice[GRID_SIZE] = { 0 };
			//Slide all tiles from the column (right to left)
			for (int col = GRID_SIZE - 1, i = 0; col >= 0; col--) {
				int index = row * GRID_SIZE + col;
				if (world[index] != 0) {
					slice[i++] = world[index];
				}
			}
			//Merge equal num
			for (int i = 0; i < GRID_SIZE - 1; i++) {
				if (slice[i] == slice[i + 1]) {
					slice[i] = slice[i] + slice[i + 1];
					for (int j = i + 1; j < GRID_SIZE - 1; j++) {
						slice[j] = slice[j + 1];
					}
					slice[GRID_SIZE - 1] = 0;
				}
			}
			for (int col = GRID_SIZE - 1, i = 0; col >= 0; col--) {
				int index = row * GRID_SIZE + col;
				world[index] = slice[i++];
			}
		}
		int length = 0;
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				length++;
			}
		}

		//Add new num
		if (length == 0) {
			return; 
		}

		int index = rand() % length;
		int j = 0;
		for (int i = 0; i < WORLD_SIZE; i++) {
			if (world[i] == 0) {
				if (index == j) {
					world[i] = 2;
					break;
				}
				j++;
			}
		}
	}
}


	//Game Flow

	//Setup
	//1. 4x4 grid
	//2. Game begins, 2 tiles spawns


	//Game Loop
	//3. press up, down, left, or right
	//4. all tiles stacks to one side
	//5. two same number stacks onto each other (from the direction pressed) 
	// 2 2 2 -> 0 2 4
	//combines into 1 tile of the next number(the number of their mutiplied)
	//6. another tile spawns in a random empty tile. 
	//7. goes back to 3. 
