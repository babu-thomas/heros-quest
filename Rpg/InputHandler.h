#pragma once

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void update(bool *quit);
	bool isKeyDown(SDL_Scancode key);
	void onMouseMove(SDL_Event event);
	int getMouseX();
	int getMouseY();
private:
	const Uint8 *kb_state;
	int mouse_x;
	int mouse_y;
};

