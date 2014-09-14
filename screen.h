#ifndef SCREEN_H
#define SCREEN_H
#include "SDL.h"
class Screen
{
public:
	virtual bool handle_input(SDL_Event e);
	virtual void execute_tick(SDL_Renderer* renderer) = 0;

};

#endif