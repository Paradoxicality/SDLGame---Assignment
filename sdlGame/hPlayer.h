#ifndef gamePlayer
#define gamePlayer

#include "hGameObject.h"

class Player : public GameObject{

public:

	SDL_Rect temp;

	void input();
	/*
	
		SDL_Event _event;
		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
				isRunning = false;
			if (_event.type == SDL_KEYDOWN)
			{
				switch (_event.key.keysym.sym) {
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				case SDLK_w:
					srcRect = { textureXPos * 38, 198, 38, 66 };
					break;

				case SDLK_a:
					srcRect = { textureXPos * 38, 66, 38, 66 };
					break;

				case SDLK_d:
					srcRect = { textureXPos * 38, 132, 38, 66 };
					break;

				case SDLK_s:
					srcRect = { textureXPos * 38, 0, 38, 66 };
					break;
				}
			}
		}
	*/
	void update();
	void lateUpdate();
	void render();

	char movementDir;

	bool sprinting;
	bool status;



private:




};

#endif 