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
	double getDistance(int x1, int y1, int x2, int y2);

private:
	bool quit;
	bool follow;
	int follow_point_x;
	int follow_point_y;
	Window *window;
	Sprite *grass;
	Sprite *player;
	SDL_Event *main_event;
	InputHandler *input_handler;

};

