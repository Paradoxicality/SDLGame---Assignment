#include <iostream>
#include "SDL.h"
#include "hGameObject.h"

void GameObject :: render(SDL_Renderer* renderer) {

	//Change for sprites later
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void GameObject:: init (int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}