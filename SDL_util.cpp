#include "SDL_util.h"

// Create SDL window 
int SDL_util::init(SDL_Window** window, SDL_Surface** screenSurface, int w, int h)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return 0;
	}
	else
	{
		*window = SDL_CreateWindow("AISnake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			return 0;
		}
		else
		{
			*screenSurface = SDL_GetWindowSurface(*window);
		}
	}
	return 1;
}

// Returns a SDL_Rect with specified coordinates
SDL_Rect* SDL_util::create_rect(int x, int y, int w, int h)
{
	SDL_Rect* r = new SDL_Rect();
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
	return r;
}

SDL_Surface* SDL_util::load_bmp(string location)
{
	SDL_Surface* img = NULL;
	img = SDL_LoadBMP(location.c_str());
	if (img == NULL)
	{
		cout << "Error loading bmp at location: " << endl;
		cout << location;
		return NULL;
	}
	else
	{
		return img;
	}
}

// TODO: make this applicable for multiple windows and surfaces
void SDL_util::close(SDL_Window* window, SDL_Surface* surface)
{
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	window = NULL;
	surface = NULL;
	SDL_Quit();
}