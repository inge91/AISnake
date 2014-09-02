#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <iostream>
#include <SDL.h>
#include <string>

using namespace std;

// SDL util contains various wrappers around SDL functionalities
class SDL_util
{
public:
	static SDL_Rect* create_rect(int x, int y, int w, int h);
	static SDL_Surface* load_bmp(string location);
	static int init(SDL_Window** window, SDL_Surface** screenSurface, int w, int h);
	static void close(SDL_Window* window, SDL_Surface* surface);

};



#endif