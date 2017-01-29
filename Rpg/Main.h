#pragma once

#include <SDL.h>
#include "Window.h"
#include "Sprite.h"
#include "InputHandler.h"

class CMain
{
public:
	CMain();
	~CMain();
	void init();
	void gameLoop();
	void handleEvents();

private:
	bool quit;
	Window *window;
	Sprite *grass;
	Sprite *bob;
	SDL_Event *main_event;
	InputHandler *input_handler;

};

