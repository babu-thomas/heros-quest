#include "Main.h"
#include <SDL_image.h>

int main(int argc, char **argv)
{
	CMain cmain;
	cmain.init();
	cmain.gameLoop();
	SDL_Quit();
	IMG_Quit();
	return 0;
}