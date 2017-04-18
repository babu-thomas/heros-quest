#include "InputHandler.h"


InputHandler::InputHandler()
{
	kb_state = SDL_GetKeyboardState(nullptr);
	mouse_button_states = vector<bool>(3, false);
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
		case SDL_KEYDOWN:
			*quit = true;
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
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

void InputHandler::onMouseButtonDown(SDL_Event event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		mouse_button_states[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		mouse_button_states[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		mouse_button_states[RIGHT] = true;
		break;
	default:
		break;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		mouse_button_states[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		mouse_button_states[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		mouse_button_states[RIGHT] = false;
		break;
	default:
		break;
	}
}

int InputHandler::getMouseX()
{
	return mouse_x;
}

int InputHandler::getMouseY()
{
	return mouse_y;
}

bool InputHandler::getMouseButtonState(int button_num)
{
	return mouse_button_states[button_num];
}
