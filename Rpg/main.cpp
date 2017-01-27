#include "stdafx.h"
#include "Main.h"



CMain::CMain() : quit(false), window(NULL), renderer(NULL), grass_image(NULL), bob_image(NULL),
	main_event(), grass_rect(), bob_rect()
{
	SDL_Init(SDL_INIT_VIDEO);
}


CMain::~CMain()
{
	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void CMain::init()
{
	window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
		SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		cout << "Can't create window!\n";
		quit = true;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		cout << "Can't create renderer!\n";
		quit = true;
	}

	grass_image = IMG_LoadTexture(renderer, "data/grass.bmp");
	if (grass_image == NULL)
	{
		cout << "Grass texture loading failed!\n";
		quit = true;
	}
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 800;
	grass_rect.h = 600;

	bob_image = IMG_LoadTexture(renderer, "data/bob.png");
	if (bob_image == NULL)
	{
		cout << "Bob texture loading failed!\n";
		quit = true;
	}
	bob_rect.x = 100;
	bob_rect.y = 100;
	bob_rect.w = 100;
	bob_rect.h = 150;
}

void CMain::gameLoop()
{
	while (!quit && main_event.type != SDL_QUIT)
	{
		SDL_PollEvent(&main_event);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect);
		SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect);
		SDL_RenderPresent(renderer);
	}
}
