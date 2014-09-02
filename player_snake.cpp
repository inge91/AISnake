#include "player_snake.h"

Player_snake::Player_snake(int x, int y)
:Snake(x, y)
{
	keys.insert(pair<SDL_Keycode, Snake::direction>(SDLK_UP, UP));
	keys.insert(pair<SDL_Keycode, Snake::direction>(SDLK_DOWN, DOWN));
	keys.insert(pair<SDL_Keycode, Snake::direction>(SDLK_LEFT, LEFT));
	keys.insert(pair<SDL_Keycode, Snake::direction>(SDLK_RIGHT, RIGHT));
}

void Player_snake::assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles)
{
	if (keys.find(k) == keys.end())
	{
		//pass
	}
	else
	{
		d = keys.at(k);
	}
}