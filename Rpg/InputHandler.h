#pragma once

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void update(bool *quit);
	bool isKeyDown(SDL_Scancode key);
private:
	const Uint8 *kb_state;
};

