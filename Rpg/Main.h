#pragma once

#include "stdafx.h"
#include "Window.h"

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
	SDL_Texture *grass_image;
	SDL_Rect grass_rect;
	SDL_Texture *bob_image;
	SDL_Rect bob_rect;
	SDL_Event *main_event;
};

