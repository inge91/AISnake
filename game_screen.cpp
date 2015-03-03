#include "game_screen.h"

Game_screen::Game_screen()
	:b("../Levels/1.dat"){}

bool Game_screen::handle_input(SDL_Event e, Screen* s)
{

	if (!Screen::handle_input(e, s))
	{
		return false;
	}
	else
	{
		if (e.type == SDL_KEYDOWN)
		{
			b.assign_movement(e.key.keysym.sym);
			return true;
		}
	}

}

void Game_screen::execute_tick(SDL_Renderer* renderer)
{
	Uint32 passed_t = SDL_GetTicks();
	if (passed_t - snake_speed > SNAKE_SPEED)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		b.assign_movement(NULL);
		// move snakes
		snake_speed = passed_t;
		b.move_snakes();
		b.draw_board( renderer);
		SDL_RenderPresent(renderer);
		b.print_positions();
		b.handle_collision();
	}
}