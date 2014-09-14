#include <SDL.h>
#undef main
#include <iostream>
#include <vector>
#include <time.h>
#include "screen.h"
#include "main_screen.h"
#include "SDL_util.h"
#include "game_specs.h"


// Work away these global variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* renderer = NULL;
using namespace std;
Uint32 t = 0;
Uint32 snake_speed = 0;
enum Movement {UP, DOWN, LEFT, RIGHT, NONE};
Movement dir = NONE;

int main()
{
	if (!SDL_util::init(&gWindow, &gScreenSurface, &renderer, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		cout << "Initialization failed" << endl;
		exit(0);
	}
	else
	{
		bool quit = false;
		SDL_Event e;
		Main_screen s = Main_screen(renderer);
		
		// The main loop
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				s.handle_input(e);
				
			}

			// Framerate capping
			Uint32 passed_t = SDL_GetTicks();
			if ((passed_t - t) < (1000 / FRAME_RATE))
			{
				t = passed_t;
				SDL_Delay((1000 / FRAME_RATE) - (passed_t - t));
			}
			s.execute_tick(renderer);
		}
	}

	SDL_util::close(gWindow, gScreenSurface);
}