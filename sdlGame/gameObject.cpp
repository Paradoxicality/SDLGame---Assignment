#include <iostream>
#include "SDL.h"
#include "hGameObject.h"

void GameObject :: render(SDL_Renderer* renderer) {

	//Change for sprites later
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
	SDL_RenderFillRect(renderer, &rect);
}

void GameObject:: init (int x, int y) {
	rect.x = x;
	rect.y = y;
}