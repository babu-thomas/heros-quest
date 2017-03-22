#include <iostream>
#include <SDL_image.h>
#include <cmath>
#include "Main.h"

using namespace std;



CMain::CMain() : quit(false), window(nullptr), main_event(nullptr), grass(nullptr), player(nullptr),
	input_handler(nullptr)
{
}


CMain::~CMain()
{
	delete window;
	delete grass;
	delete player;
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

	player = new Sprite();
	if (!player->load("data/tom.png", window->getRenderer()))
	{
		quit = true;
	}
	player->setNumberOfFrames(4, 4);
	int frame_width = player->getWidth() / player->getFramesX();
	int frame_height = player->getHeight() / player->getFramesY();
	player->setCrop(1 * frame_width, 0, frame_width, frame_height);
	player->draw(200, 200, 190, 200, window->getRenderer());
	player->setOrigin(player->getWidth() / 2.0, player->getHeight());

	main_event = new SDL_Event();
	input_handler = new InputHandler();
	follow = false;
	follow_point_x = 0;
	follow_point_y = 0;
}

void CMain::gameLoop()
{
	Uint32 old_time = SDL_GetTicks();
	while (!quit)
	{
		Uint32 new_time = SDL_GetTicks();
		Uint32 delta = new_time - old_time;
		if (10 < delta)
		{
			//Update
			handleEvents();
			//Render
			window->clear();
			grass->draw(window->getRenderer());
			player->draw(window->getRenderer());
			window->update();
			old_time = new_time;
		}
	}
}

void CMain::handleEvents()
{
	input_handler->update(&quit);
	double player_x = player->getX();
	double player_y = player->getY();
	int mouse_x = input_handler->getMouseX();
	int mouse_y = input_handler->getMouseY();
	if (input_handler->getMouseButtonState(LEFT))
	{
		follow = true;
		follow_point_x = mouse_x;
		follow_point_y = mouse_y;
	}

	double angle_rad = atan2(follow_point_y - player->getY(), follow_point_x - player->getX());
	double angle_deg = angle_rad * (180 / M_PI) + 180;

	double distance = getDistance(player_x, player_y, follow_point_x, follow_point_y);
	if (follow)
	{
		if (45 < angle_deg && angle_deg <= 135)
		{
			//Up
			player->playAnimation(0, 3, 3, 1);
		}
		else if (135 < angle_deg && angle_deg <= 225)
		{
			//Right
			player->playAnimation(0, 3, 2, 1);
		}
		else if (225 < angle_deg && angle_deg <= 315)
		{
			//Down
			player->playAnimation(0, 3, 0, 1);
		}
		else
		{
			//Left
			player->playAnimation(0, 3, 1, 1);
		}
		
		if (distance > 2)
		{
			player->setY(player_y - (player_y - follow_point_y) / distance * 3.0);
			player->setX(player_x - (player_x - follow_point_x) / distance * 3.0);
		}
		else
		{
			follow = false;
		}
	}
}

double CMain::getDistance(int x1, int y1, int x2, int y2)
{
	double diff_x = x1 - x2;
	double diff_y = y1 - y2;
	double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
	return distance;
}
