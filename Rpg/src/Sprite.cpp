#include <string>
#include <SDL_image.h>
#include "Sprite.h"


Sprite::Sprite() : texture(nullptr)
{
	rect = new SDL_Rect();
	crop = new SDL_Rect();
	rect->x = rect->y = 0;
	rect->w = rect->h = 0;
	origin_x = origin_y = 0.0;
	x_pos = y_pos = 0.0;
	image_width = image_height = 0;
	frames_x = frames_y = 0;
	current_frame = 0;
	animation_delay = 150;
}


Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
	delete rect;
	delete crop;
}

bool Sprite::load(string file_name, SDL_Renderer *renderer)
{
	texture = IMG_LoadTexture(renderer, file_name.c_str());
	if (texture != nullptr)
	{
		if (SDL_QueryTexture(texture, nullptr, nullptr, &image_width, &image_height) < 0)
		{
			cout << "QueryTexture failed! Filename: " << file_name << endl;
			return false;
		}
		rect->w = image_width;
		rect->h = image_height;
		crop->w = image_width;
		crop->h = image_height;
		return true;
	}
	cout << "Texture loading failed! Filename: " << file_name << endl;
	return false;
}

void Sprite::draw(int x, int y, int w, int h, SDL_Renderer *renderer)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;

	x_pos = x;
	y_pos = y;

	SDL_RenderCopy(renderer, texture, crop, rect);
}

void Sprite::draw(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, crop, rect);
}

void Sprite::setCrop(int x, int y, int w, int h)
{
	crop->x = x;
	crop->y = y;
	crop->w = w;
	crop->h = h;
}

void Sprite::setX(double x)
{
	x_pos = x;
	rect->x = int(x_pos - origin_x);
}

void Sprite::setY(double y)
{
	y_pos = y;
	rect->y = int(y_pos - origin_y);
}

void Sprite::setPosition(double x, double y)
{
	x_pos = x;
	y_pos = y;

	rect->x = int(x_pos - origin_x);
	rect->y = int(y_pos - origin_y);
}

void Sprite::setOrigin(double x, double y)
{
	origin_x = x;
	origin_y = y;
	setPosition(getX(), getY());
}

double Sprite::getOriginX()
{
	return origin_x;
}

double Sprite::getOriginY()
{
	return origin_y;
}

double Sprite::getX()
{
	return x_pos;
}

double Sprite::getY()
{
	return y_pos;
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

void Sprite::setNumberOfFrames(int frames_x, int frames_y)
{
	this->frames_x = frames_x;
	this->frames_y = frames_y;
}

int Sprite::getFramesX()
{
	return frames_x;
}

int Sprite::getFramesY()
{
	return frames_y;
}

void Sprite::playAnimation(int begin_frame, int end_frame, int row, float speed)
{
	unsigned int ticks = SDL_GetTicks();
	int current_frame = begin_frame;

	if(begin_frame != end_frame)
	{
		int current_delay = float(animation_delay / speed) + 0.5;
		current_frame = (ticks / current_delay) % (end_frame + 1);
	}

	crop->x = current_frame * (image_width / frames_x);
	crop->y = row * (image_height / frames_y);
	crop->w = image_width / frames_x;
	crop->h = image_height / frames_y;
}