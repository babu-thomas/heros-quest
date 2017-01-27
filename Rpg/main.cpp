#include "stdafx.h"
#include "Main.h"



CMain::CMain() : quit(false), window(nullptr), grass_image(nullptr), bob_image(nullptr),
	main_event(nullptr), grass_rect(), bob_rect()
{
}


CMain::~CMain()
{
	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
	delete main_event;
}

void CMain::init()
{
	window = new Window();
	window -> init(&quit);

	grass_image = IMG_LoadTexture(window -> getRenderer(), "data/grass.bmp");
	if (grass_image == nullptr)
	{
		cout << "Grass texture loading failed!\n";
		quit = true;
	}
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 800;
	grass_rect.h = 600;

	bob_image = IMG_LoadTexture(window -> getRenderer(), "data/bob.png");
	if (bob_image == nullptr)
	{
		cout << "Bob texture loading failed!\n";
		quit = true;
	}
	bob_rect.x = 100;
	bob_rect.y = 100;
	bob_rect.w = 100;
	bob_rect.h = 150;

	main_event = new SDL_Event();
}

void CMain::gameLoop()
{
	while (!quit && main_event -> type != SDL_QUIT)
	{
		SDL_PollEvent(main_event);
		window -> clear();
		SDL_RenderCopy(window -> getRenderer(), grass_image, nullptr, &grass_rect);
		SDL_RenderCopy(window -> getRenderer(), bob_image, nullptr, &bob_rect);
		window -> update();
	}
}
