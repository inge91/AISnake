#include "screen.h"

bool Screen::handle_input(SDL_Event e)
{

	if (e.type == SDL_QUIT)
	{
		return false;
	}
}