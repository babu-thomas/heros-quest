#include <iostream>
#include "Window.h"

using namespace std;

Window::Window() : window(nullptr), renderer(nullptr)
{
}


Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Window::init(int width, int height, bool *quit)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		cout << "Can't create window!\n";
		*quit = true;
	}
	this->width = width;
	this->height = height;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		cout << "Can't create renderer!\n";
		*quit = true;
	}
}

void Window::clear()
{
	SDL_RenderClear(renderer);
}

void Window::update()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer * Window::getRenderer()
{
	return renderer;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}
