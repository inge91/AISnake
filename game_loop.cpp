#include "game_loop.h"

Game_loop::Game_loop(SDL_Renderer* renderer)
{
	t = 0;
	active_screen = new Main_screen(renderer);
}

void Game_loop::start(SDL_Renderer* renderer)
{
	bool quit = false;
	SDL_Event e;
	Screen *next_s = NULL;

	// The main loop
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			active_screen->handle_input(e, next_s);
			if (next_s)
			{
				active_screen = next_s;
			}
		}

		// Framerate capping
		Uint32 passed_t = SDL_GetTicks();
		if ((passed_t - t) < (1000 / FRAME_RATE))
		{
			t = passed_t;
			SDL_Delay((1000 / FRAME_RATE) - (passed_t - t));
		}
		active_screen->execute_tick(renderer);
	}
}