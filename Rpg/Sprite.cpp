#include <string>
#include <SDL_image.h>
#include "Sprite.h"


Sprite::Sprite() : texture(nullptr)
{
}


Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

bool Sprite::load(string file_name, SDL_Renderer *renderer)
{
	texture = IMG_LoadTexture(renderer, file_name.c_str());
	if (texture != nullptr)
		return true;
	cout << "Texture loading failed! Filename: " << file_name << endl;
	return false;
}

void Sprite::draw(int x, int y, int w, int h, SDL_Renderer *renderer)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}
