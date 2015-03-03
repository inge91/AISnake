#include "screen.h"

bool Screen::handle_input(SDL_Event e, Screen* s)
{
	if (e.type == SDL_QUIT)
	{
		return false;
	}
}

void Screen::execute_tick(SDL_Renderer* renderer){
	std::cout << "Here" << std::endl;
}