#ifndef gameObject
#define gameObject

class GameObject {

public:

	SDL_Rect rect;

	void init(int r, int g, int b);
	void update();
	void lateUpdate();
	void render(SDL_Renderer* renderer);

	int r = 0;
	int b = 255;
	int g = 0;

private:

};

#endif 