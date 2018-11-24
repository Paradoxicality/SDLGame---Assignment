#ifndef gameObject
#define gameObject

class GameObject {

public:

	enum class BlockType { EMPTY, DOOR, WALL, FINISH, PLAYER, PICKUP, ENEMY };

	SDL_Rect rect;

	void init(BlockType type);
	void update();
	void lateUpdate();
	void render(SDL_Renderer* renderer);

	BlockType type;

private:

	int r = 0;
	int b = 255;
	int g = 0;
	int alpha = 255;

};

#endif 