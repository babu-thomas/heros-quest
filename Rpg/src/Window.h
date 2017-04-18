#pragma once

#include <SDL.h>

class Window
{
public:
	Window();
	~Window();
	void init(int width, int height, bool *quit);
	void clear();
	void update();
	SDL_Renderer * getRenderer();
	int getWidth();
	int getHeight();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width;
	int height;
};

