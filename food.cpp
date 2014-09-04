#include "food.h"

Food::Food(vector<pair<int, int>> candidates)
{
	// Determine first food position
	srand(time(NULL));
	img = SDL_util::load_bmp("../Images/pellet.bmp");
	change_pos(candidates);
}

Food::Food(int x, int y)
{
	// Determine first food position
	srand(time(NULL));
	img = SDL_util::load_bmp("../Images/pellet.bmp");
	pos.first = x;
	pos.second = y;
}

//FIXME: This should only consider empty slots on the board
void Food::change_pos(vector<pair<int, int>> candidates)
{
	pos = candidates.at(rand() % candidates.size());
}



void Food::draw_food(SDL_Surface* surface)
{
	SDL_BlitSurface(img, NULL, surface, SDL_util::create_rect(pos.first * UNIT_SIZE, pos.second * UNIT_SIZE, UNIT_SIZE, UNIT_SIZE));
}