#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <regex>
#include <fstream>

#include "SDL_util.h"
#include "AI_snake.h"
#include "snake.h"
#include "player_snake.h"
#include "food.h"
#include "game_specs.h"
#include "astar.h"

using namespace std;
class Board
{
public:
	Board(string location);
	~Board();
	vector<pair<int, int>> obstacles;
	vector<Snake*> snakes;
	Food food;
	void draw_board(SDL_Renderer* renderer);
	void update_board();
	void handle_collision();
	void move_snakes();
	void assign_movement(SDL_Keycode k);
	void print_positions();

private:
	void load_obstacles(string location);
	vector<pair<int, int>> get_unoccupied();

};

#endif