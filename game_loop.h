#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include "screen.h"
#include "game_specs.h"
#include "screen.h"
#include "main_screen.h"
#include "game_screen.h"

class Game_loop
{
public:
	void start(SDL_Renderer* renderer);
	Game_loop(SDL_Renderer* renderer);
private:
	Screen *active_screen;
	Uint32 t;
};

#endif