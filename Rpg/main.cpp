#include <iostream>
#include <SDL_image.h>
#include "Main.h"

using namespace std;



CMain::CMain() : quit(false), window(nullptr), main_event(nullptr), grass(nullptr), bob(nullptr),
	input_handler(nullptr)
{
}


CMain::~CMain()
{
	delete window;
	delete grass;
	delete bob;
	delete main_event;
}

void CMain::init()
{
	window = new Window();
	window->init(800, 600, &quit);

	grass = new Sprite();
	if (!grass->load("data/grass.bmp", window->getRenderer()))
	{
		quit = true;
	}

	bob = new Sprite();
	if (!bob->load("data/bob.png", window->getRenderer()))
	{
		quit = true;
	}
	grass->draw(0, 0, window->getWidth(), window->getHeight(), window->getRenderer());
	bob->draw(100, 100, 100, 150, window->getRenderer());

	main_event = new SDL_Event();
	input_handler = new InputHandler();
}

void CMain::gameLoop()
{
	Uint32 old_time = SDL_GetTicks();
	while (!quit)
	{
		Uint32 new_time = SDL_GetTicks();
		Uint32 delta = new_time - old_time;
		if (20 < delta)
		{
			handleEvents();
			old_time = new_time;
		}

		window->clear();
		grass->draw(window->getRenderer());
		bob->draw(window->getRenderer());
		window->update();
	}
}

void CMain::handleEvents()
{
	input_handler->update(&quit);
	if (input_handler->isKeyDown(SDL_SCANCODE_W))
	{
		bob->moveUp();
	}
	if (input_handler->isKeyDown(SDL_SCANCODE_S))
	{
		bob->moveDown();
	}
	if (input_handler->isKeyDown(SDL_SCANCODE_A))
	{
		bob->moveLeft();
	}
	if (input_handler->isKeyDown(SDL_SCANCODE_D))
	{
		bob->moveRight();
	}
}
