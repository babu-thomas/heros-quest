#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

using namespace std;

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	bool quit = false;
	SDL_Window *win = NULL;
	win = SDL_CreateWindow("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
		SDL_WINDOW_SHOWN);
	if (win == NULL)
		quit = true;

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		quit = true;
	
	SDL_Texture *grass_image = IMG_LoadTexture(renderer, "data/grass.bmp");
	if (grass_image == NULL)
	{
		cout << "Grass texture loading failed.\n";
		quit = true;
	}

	SDL_Rect grass_rect;
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 800;
	grass_rect.h = 600;

	SDL_Texture *bob_image = IMG_LoadTexture(renderer, "data/bob.png");
	if (bob_image == NULL)
	{
		cout << "Bob texture loading failed.\n";
		quit = true;
	}
	SDL_Rect bob_rect;
	bob_rect.x = 100;
	bob_rect.y = 100;
	bob_rect.w = 100;
	bob_rect.h = 150;

	SDL_Event *e = new SDL_Event();
	while (!quit && e -> type != SDL_QUIT)
	{
		SDL_PollEvent(e);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect);
		SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	delete e;

	return 0;
}