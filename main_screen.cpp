#include "main_screen.h"

Main_screen::Main_screen(SDL_Renderer* renderer)
	:Selection_screen(renderer)
{
	SDL_util::texture t(SDL_util::load_ttf("../Fonts/sans.ttf", "New Game", SDL_util::create_color(255, 255, 255, 255), renderer), SDL_util::create_color(255, 255, 255, 255));
	texture_container.push_back(t);
}