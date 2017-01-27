#pragma once

#include <iostream>
#include <SDL.h>

using namespace std;

class Sprite
{
public:
	Sprite();
	~Sprite();
	bool load(string file_name, SDL_Renderer *renderer);
	void draw(int x, int y, int w, int h, SDL_Renderer *renderer);
private:
	SDL_Texture *texture;
};

