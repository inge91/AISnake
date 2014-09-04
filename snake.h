#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <iostream>
#include <SDL.h>
#include "SDL_util.h"
#include "game_specs.h"

using namespace std;

class Snake
{
public:
	enum direction { UP, DOWN, LEFT, RIGHT, NONE };
	direction d;
	Snake(int b);
	Snake(int x, int y, int b);
	SDL_Surface* img;
	// Snake has a vector containing body parts
	vector<pair<int, int>> body;
	void draw_snake(SDL_Surface* surface);
	void grow();
	void print_body();
	void move();
	bool check_self_collision();
	bool check_collision(vector<pair<int,int>> elements);
	virtual void assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles) = 0;

private:
	void move(int x, int y);

};

#endif