#include <iostream>
#include <SDL_image.h>
#include "Main.h"

using namespace std;



CMain::CMain() : quit(false), window(nullptr), main_event(nullptr), grass(nullptr), bob(nullptr)
{
}


CMain::~CMain()
{
	delete main_event;
}

void CMain::init()
{
	window = new Window();
	window->init(&quit);

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

	main_event = new SDL_Event();
}

void CMain::gameLoop()
{
	while (!quit && main_event->type != SDL_QUIT)
	{
		SDL_PollEvent(main_event);
		window->clear();
		grass->draw(0, 0, 800, 600, window->getRenderer());
		bob->draw(100, 100, 100, 150, window->getRenderer());
		window->update();
	}
}
