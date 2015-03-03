#include <SDL.h>
#undef main
#include <iostream>
#include <vector>
#include <time.h>
#include "screen.h"
#include "main_screen.h"
#include "SDL_util.h"
#include "game_specs.h"
#include "game_loop.h"


// Work away these global variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* renderer = NULL;
using namespace std;

int main()
{
	if (!SDL_util::init(&gWindow, &gScreenSurface, &renderer, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		cout << "Initialization failed" << endl;
		exit(0);
	}
	else
	{
		Game_loop g = Game_loop(renderer);
		g.start(renderer);
	}

	SDL_util::close(gWindow, gScreenSurface);
}