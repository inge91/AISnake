#include "selection_screen.h"

/*
We should have a scene handler
whish has an active scene as object
handle input should return a Scene type if a new kind of scene is entered
else it returns NULL
the scene handler sets this scene as its new active handler
*/
Selection_screen::Selection_screen(SDL_Renderer* renderer)
{
	
}

bool Selection_screen::handle_input(SDL_Event e, Screen* s)
{
	
	if (!Screen::handle_input(e, s))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Selection_screen::execute_tick(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	std::cout << "here2" << std::endl;
	draw_textures(renderer);
	
	SDL_RenderPresent(renderer);
}

void Selection_screen::draw_textures(SDL_Renderer* renderer)
{
	for (SDL_util::texture t : texture_container)
	{
		SDL_SetRenderDrawColor(renderer, t.color.r, t.color.g, t.color.b, t.color.a);
		if (SDL_RenderCopy(renderer, t.text, NULL, t.rect) != 0)
		{
			std::cout << "Something went wrong" << std::endl;
		}
	}
}