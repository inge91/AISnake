#include "SDL_util.h"

// Create SDL window 
int SDL_util::init(SDL_Window** window, SDL_Surface** screenSurface, SDL_Renderer** renderer, int w, int h)
{
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
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

			*renderer = SDL_CreateRenderer(*window, 0, SDL_RENDERER_ACCELERATED);
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

SDL_Color SDL_util::create_color(int r, int g, int b, int a)
{
	SDL_Color c = { r, g, b, a };
	return c;
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

SDL_Texture* SDL_util::load_ttf(string location, string text, SDL_Color c, SDL_Renderer* renderer)
{
	TTF_Font* sans = TTF_OpenFont("../Fonts/OpenSans.ttf", 24); //this opens a font style and sets a size
	if (!sans) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sans, text.c_str(), c); 
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	if (!message)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}
	return message;
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