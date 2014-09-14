#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

// SDL util contains various wrappers around SDL functionalities
class SDL_util
{
public:
	static SDL_Rect* create_rect(int x, int y, int w, int h);
	static SDL_Color create_color(int r, int g, int b, int a);
	static SDL_Surface* load_bmp(string location);
	static int init(SDL_Window** window, SDL_Surface** screenSurface, SDL_Renderer** renderer, int w, int h);
	static void close(SDL_Window* window, SDL_Surface* surface);
	static SDL_Texture* load_ttf(string location, string text, SDL_Color c, SDL_Renderer* renderer);

	struct texture
	{
		texture(SDL_Texture* t, SDL_Color c)
		{
			text = t;
			int w = 0;
			int h = 0;
			int i = SDL_QueryTexture(text,
				NULL,
				NULL,
				&w,
				&h);
			rect = SDL_util::create_rect(0, 0, w, h);
			color = c;
		}
		SDL_Texture* text;
		SDL_Rect* rect;
		SDL_Color color;
	};
};



#endif