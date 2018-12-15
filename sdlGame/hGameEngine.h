#ifndef gameEngine
#define gameEngine

#include <vector>
#include "hGameObject.h"
#include "hPlayer.h"

class Game {
	public:

		bool init();

		void build();
		void run();
		void update();
		void lateUpdate();
		void render();
		void input();
		void eventHandler();
		void clean();

		//Fix later
		void readFile();

		std::vector<int> worldInts;
		std::vector<GameObject> worldTiles;

		bool running() { return isRunning; };

		const int blockSize = 20;
		const int windowRows = 40;
		const int windowColumns = 30;
		const int windowHeight = 600;
		const int windowWidth = 800;

		Player player;

	private:
	
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;

};

#endif // !GameEngine
