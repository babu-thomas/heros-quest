#pragma once

#include <vector>
#include <SDL.h>

using namespace std;

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void update(bool *quit);
	bool isKeyDown(SDL_Scancode key);
	int getMouseX();
	int getMouseY();
	bool getMouseButtonState(int button_num);

private:
	const Uint8 *kb_state;
	int mouse_x;
	int mouse_y;
	vector<bool> mouse_button_states;

	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
};

