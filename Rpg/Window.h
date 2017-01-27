#pragma once

#include <SDL.h>

class Window
{
public:
	Window();
	~Window();
	void init(bool *quit);
	void clear();
	void update();
	SDL_Renderer * getRenderer();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};

