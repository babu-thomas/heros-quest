#pragma once

#include <SDL.h>
#include "Window.h"
#include "Sprite.h"

class CMain
{
public:
	CMain();
	~CMain();
	void init();
	void gameLoop();

private:
	bool quit;
	Window *window;
	Sprite *grass;
	Sprite *bob;
	SDL_Event *main_event;
};

