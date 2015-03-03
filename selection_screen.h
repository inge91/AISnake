#ifndef SELECTION_SCREEN_H
#define SELECTION_SCREEN_H
#include "SDL.h"
#include "screen.h"
#include "SDL_ttf.h"
#include "SDL_util.h"
#include <iostream>
#include <vector>

class Selection_screen : public Screen
{
public:
	Selection_screen(SDL_Renderer* renderer);
	bool handle_input(SDL_Event e, Screen* s);
	virtual void execute_tick(SDL_Renderer* renderer);
	SDL_Texture* Message;
protected:
	std::vector<SDL_util::texture> texture_container;
	void draw_textures(SDL_Renderer* renderer);
};

#endif // !MAIN_SCREEN_H
