#ifndef gameEngine
#define gameEngine

class Game {
	public:

		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void run();
		void update();
		void lateUpdate();
		void render();
		void input();
		void eventHandler();
		void clean();

		bool running() { return isRunning; };

	private:
	
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;

};

#endif // !GameEngine
