#include <iostream>
#include "Window.h"

using namespace std;

Window::Window() : window(nullptr), renderer(nullptr)
{
}


Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::init(bool *quit)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		cout << "Can't create window!\n";
		*quit = true;
	}

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
