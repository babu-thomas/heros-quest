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
		case SDL_MOUSEMOTION:
			onMouseMove(event);
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

void InputHandler::onMouseMove(SDL_Event event)
{
	mouse_x = event.motion.x;
	mouse_y = event.motion.y;
}

int InputHandler::getMouseX()
{
	return mouse_x;
}

int InputHandler::getMouseY()
{
	return mouse_y;
}
