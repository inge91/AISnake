#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <time.h>
#include <SDL.h>
#include <vector>
#include "SDL_util.h"
#include "game_specs.h"


/*
Create a class board that has snake objects and a food object
food_pos then get's  a reference to board to check all free spaces, and from these free spaces determines a new pellet position (best i can think of now
update board function updates drawing of snakes and food as well as collision handling as i dont know
*/

using namespace std;
// The food pellets
class Food
{
public:
	Food(vector<pair<int, int>> candidates);
	Food(int x, int y);
	SDL_Surface* img;
	// Food pellets have a position
	pair <int, int> pos;
	void change_pos(vector<pair<int, int>> obstacles);
	vector<pair<int, int>> get_unoccupied(vector<pair<int, int>> obstacles);
	void draw_food(SDL_Surface* surface);
};

#endif