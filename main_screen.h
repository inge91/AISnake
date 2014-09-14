#ifndef MAIN_SCREEN
#define MAIN_SCREEN

#include "selection_screen.h"
#include "SDL_util.h"
#include "game_specs.h"

class Main_screen : public Selection_screen
{
public:
	Main_screen(SDL_Renderer* renderer);
};

#endif