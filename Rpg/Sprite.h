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
	void setX(double x);
	void setY(double y);
	void setPosition(double x, double y);
	void setOrigin(double x, double y);
	double getOriginX();
	double getOriginY();
	double getX();
	double getY();
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
	double x_pos;
	double y_pos;
	double origin_x;
	double origin_y;
};

