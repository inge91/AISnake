#include <SDL.h>
#undef main
#include <iostream>
#include <vector>
#include <time.h>
#include "board.h"
#include "SDL_util.h"
#include "game_specs.h"


// Work away these global variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
using namespace std;
Uint32 t = 0;
Uint32 snake_speed = 0;
enum Movement {UP, DOWN, LEFT, RIGHT, NONE};
Movement dir = NONE;

int main()
{
	if (!SDL_util::init(&gWindow, &gScreenSurface, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		cout << "Initialization failed" << endl;
		exit(0);
	}
	else
	{
		bool quit = false;
		SDL_Event e;
		Board b("../Levels/1.dat");
		
		// The main loop
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_KEYDOWN)
				{
					b.assign_movement(e.key.keysym.sym);
				
				}
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			

			Uint32 passed_t = SDL_GetTicks();
		
			if ((passed_t - t) < (1000 / FRAME_RATE))
			{
				t = passed_t;
				SDL_Delay((1000 / FRAME_RATE) - (passed_t - t));
			}
			if (passed_t - snake_speed > SNAKE_SPEED)
			{
				b.assign_movement(NULL);
				// move snakes
				snake_speed = passed_t;
				b.move_snakes();
				b.draw_board(gScreenSurface);
				SDL_UpdateWindowSurface(gWindow);
				b.print_positions();
				b.handle_collision();
			}
		}
	}
	SDL_util::close(gWindow, gScreenSurface);
}