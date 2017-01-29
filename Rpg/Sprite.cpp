#include <string>
#include <SDL_image.h>
#include "Sprite.h"


Sprite::Sprite() : texture(nullptr)
{
	rect = new SDL_Rect();
	rect->x = rect->y = 0;
	rect->w = rect->h = 100;
	origin_x = origin_y = 0;
}


Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
	delete rect;
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
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	SDL_RenderCopy(renderer, texture, nullptr, rect);
}

void Sprite::draw(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, nullptr, rect);
}

void Sprite::setX(int x)
{
	rect->x = x;
}

void Sprite::setY(int y)
{
	rect->y = y;
}

void Sprite::setPosition(int x, int y)
{
	rect->x = x;
	rect->y = y;
}

void Sprite::setOrigin(int x, int y)
{
	origin_x = x;
	origin_y = y;
}

int Sprite::getOriginX()
{
	return origin_x;
}

int Sprite::getOriginY()
{
	return origin_y;
}

int Sprite::getX()
{
	return rect->x;
}

int Sprite::getY()
{
	return rect->y;
}

int Sprite::getWidth()
{
	return rect->w;
}

int Sprite::getHeight()
{
	return rect->h;
}

void Sprite::setWidth(int w)
{
	rect->w = w;
}

void Sprite::setHeight(int h)
{
	rect->h = h;
}

void Sprite::moveUp()
{
	rect->y -= 3;
}

void Sprite::moveDown()
{
	rect->y += 3;
}

void Sprite::moveRight()
{
	rect->x += 3;
}

void Sprite::moveLeft()
{
	rect->x -= 3;
}
