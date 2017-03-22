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
	void setCrop(int x, int y, int w, int h);
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
	void setNumberOfFrames(int frames_x, int frames_y);
	int getFramesX();
	int getFramesY();
	void playAnimation(int begin_frame, int end_frame, int row, float speed);
	
private:
	SDL_Texture *texture;
	SDL_Rect *rect;
	SDL_Rect *crop;
	double x_pos;
	double y_pos;
	double origin_x;
	double origin_y;
	int image_width;
	int image_height;
	int frames_x;
	int frames_y;
	int current_frame;
	int animation_delay;
};

