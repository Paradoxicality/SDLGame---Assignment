#ifndef gameObject
#define gameObject

class GameObject {

public:

	SDL_Rect rect;

	void init(int x, int y);
	void render(SDL_Renderer* renderer);
	void update();
	void lateUpdate();

private:

	int r = 0;
	int b = 255;
	int g = 0;
	int alpha = 255;

};

#endif 