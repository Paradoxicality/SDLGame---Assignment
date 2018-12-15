#ifndef gamePlayer
#define gamePlayer

#include "hGameObject.h"

class Player : public GameObject{

public:

	enum Direction { NONE, FORWARD, LEFT, RIGHT, BACKWARDS };

	Direction playerMove = NONE;

	SDL_Rect temp;

	void input(SDL_Event movement);
	void update();
	void lateUpdate();

	void shiftDirection();

	bool sprinting;
	int health;



private:



};

#endif 