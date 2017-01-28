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
	int	getX();
	int getY();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	
private:
	SDL_Texture *texture;
	SDL_Rect *rect;
};

