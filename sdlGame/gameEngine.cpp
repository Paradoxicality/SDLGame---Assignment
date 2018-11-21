//INCLUDES
#include "hGameEngine.h"

#include <iostream>

#include "SDL.h"
//END - INCLUDES


bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	int flags = 0; //Set to read from file 
	if (fullscreen) { //If fullscreen option is on
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //If SDL initializes / is setup right
		std::cout << "SDL initialized" << std::endl; //Debug

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); //Set window params and create window

		if (window) {
			std::cout << "Window initialized" << std::endl; //Debug
		}

		renderer = SDL_CreateRenderer(window, -1, 0); //Set rendrer params and create renderer

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Renderer initialized" << std::endl; //Debug
		}
	}
	else {
		isRunning = false;
		return false; //If can't initialize set game running to false
	}

	isRunning = true;
	return true; //Set the game running to true
}

void Game::run() {

	while (isRunning) {

		input();

		update();

		render();
	}

}

void Game::update() {

}

void Game::lateUpdate() {

}

void Game::eventHandler() {
	SDL_Event event; //Check events 

	while (SDL_PollEvent(&event) != 0) { //Get type of event, event is dereferenced

		switch (event.type) { //If the event is SDL_QUIT, break the game loop and quit the game
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
		}

	}
}

void Game::render() {
	SDL_RenderClear(renderer); //Clear the renderer's buffer
	//Area to add stuff to render

	SDL_RenderPresent(renderer);

}

void Game::input() {
	eventHandler();
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game closed & cleaned" << std::endl;
}