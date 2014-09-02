#ifndef PLAYER_SNAKE_H
#define PLAYER_SNAKE_H

#include "snake.h"
#include <map>
#include <SDL.h>
#include "SDL_util.h"


class Player_snake : public Snake
{
public:
	Player_snake(int x, int y);
	void assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles);

private:
	map < SDL_Keycode, Snake::direction > keys;
};

#endif