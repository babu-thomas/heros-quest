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
	void draw(SDL_Renderer *renderer);
	void setX(int x);
	void setY(int y);
	void setPosition(int x, int y);
	void setOrigin(int x, int y);
	int getOriginX();
	int getOriginY();
	int	getX();
	int getY();
	int getWidth();
	int getHeight();
	void setWidth(int w);
	void setHeight(int h);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	
private:
	SDL_Texture *texture;
	SDL_Rect *rect;
	int origin_x;
	int origin_y;
};

