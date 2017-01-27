#pragma once

#include "stdafx.h"

class CMain
{
public:
	CMain();
	~CMain();
	void init();
	void gameLoop();

private:
	bool quit;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *grass_image;
	SDL_Rect grass_rect;
	SDL_Texture *bob_image;
	SDL_Rect bob_rect;
	SDL_Event main_event;
};

