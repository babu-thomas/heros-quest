#include "InputHandler.h"



InputHandler::InputHandler()
{
	kb_state = SDL_GetKeyboardState(nullptr);
}


InputHandler::~InputHandler()
{
	delete kb_state;
}

void InputHandler::update(bool *quit)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			*quit = true;
			break;
		default:
			break;
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (kb_state[key])
		return true;
	else
		return false;
}
