#include <iostream>
#include "SDL.h"
#include "hGameEngine.h"


int main(int argc, char *argv[])
{
	Game game = Game();

	if (game.init("17631941 - Brennan Ceballos Peña", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)) {
		game.run();
	}

	game.clean();

	return 0;
}
