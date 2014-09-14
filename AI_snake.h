#ifndef AI_SNAKE_H
#define AI_SNAKE_H
#include "snake.h"
#include "astar.h"
#include "game_specs.h"

class AI_snake : public Snake
{
public:
	AI_snake(int x, int y, SDL_Color c);
	vector<pair<int, int>> solution;
	void assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles);
private:
	void apply_direction(vector<pair<int, int>> s);
};

#endif