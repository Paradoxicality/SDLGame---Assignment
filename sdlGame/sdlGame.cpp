#include <iostream>
#include "SDL.h"
#include "hGameEngine.h"


int main(int argc, char *argv[])
{
	Game game = Game();

	if (game.init()) {
		game.run();
	}

	game.clean();
	
	return 0;
}
