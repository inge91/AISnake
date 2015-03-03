#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include "screen.h"
#include "board.h"
#include "game_specs.h"
#include "SDL.h"
class Game_screen: public Screen {
public:
	Game_screen();
	bool handle_input(SDL_Event e, Screen* s);
	void execute_tick(SDL_Renderer* renderer);
private:
	Board b;
	Uint32 snake_speed;
};


#endif