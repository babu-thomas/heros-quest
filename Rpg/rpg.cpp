#include "stdafx.h"
#include "Main.h"

int main(int argc, char **argv)
{
	CMain cmain;
	cmain.init();
	cmain.gameLoop();
	return 0;
}