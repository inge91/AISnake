#ifndef SCREEN_H
#define SCREEN_H
#include "SDL.h"
#include <iostream>
class Screen
{
public:
	virtual bool handle_input(SDL_Event e, Screen* s);
	virtual void execute_tick(SDL_Renderer* renderer);

};

#endif