#include <iostream>
#include <SDL_image.h>
#include <cmath>
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
	grass->draw(0, 0, window->getWidth(), window->getHeight(), window->getRenderer());

	bob = new Sprite();
	if (!bob->load("data/bob.png", window->getRenderer()))
	{
		quit = true;
	}
	bob->draw(100, 100, 100, 150, window->getRenderer());
	bob->setOrigin(bob->getWidth() / 2.0, bob->getHeight());

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
	double bob_x = bob->getX();
	double bob_y = bob->getY();
	int mouse_x = input_handler->getMouseX();
	int mouse_y = input_handler->getMouseY();
	cout << mouse_x << " " << mouse_y << endl;

	double distance = getDistance(bob_x, bob_y, mouse_x, mouse_y);
	if (distance != 0)
	{
		if (mouse_y < bob_y)
			bob->setY(bob_y - (bob_y - mouse_y) / distance * 2.5);
		if (bob_y < mouse_y)
			bob->setY(bob_y - (bob_y - mouse_y) / distance * 2.5);
		if (mouse_x < bob_x)
			bob->setX(bob_x - (bob_x - mouse_x) / distance * 2.5);
		if (bob_x < mouse_x)
			bob->setX(bob_x - (bob_x - mouse_x) / distance * 2.5);
	}
}

double CMain::getDistance(int x1, int y1, int x2, int y2)
{
	double diff_x = x1 - x2;
	double diff_y = y1 - y2;
	double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
	return distance;
}
