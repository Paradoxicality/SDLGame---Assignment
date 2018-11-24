#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"
#include "hGameEngine.h"
#include "hGameTimer.h"
#include "hGameObject.h"

bool Game::init() {
	
	int flags = 0; //Set to read from file 
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //If SDL initializes / is setup right
		std::cout << "SDL initialized" << std::endl; //Debug

		window = SDL_CreateWindow("17631941 - Brennan Ceballos Pena - Games Computing - Temporary Name ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, flags); //Set window params and create window

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

	readFile();
	build();

	return true; //Set the game running to true
}

void Game::build() {
	GameObject tile;
	tile.rect.w = blockSize;
	tile.rect.h = blockSize;

	for (int h = 0; h < windowColumns; h++) {

		for (int w = 0; w < windowRows; w++) {
			switch (worldInts[(h*windowRows) + w])
			{
			case 1:
				std::cout << "Player Spawned" << std::endl;
				break;
			case 2:
				tile.init(w*blockSize, h*blockSize);
				std::cout << "Tile thing" << std::endl;
				worldTiles.push_back(tile);
				break;

			default:
				break;
			}
		}

	}
}

void Game::run() {

	GameTimer fpsLock;

	while (isRunning) {

		input();

		update();

		render();

		fpsLock.gameLoopDelay();
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

	for (GameObject object : worldTiles) {
		object.render(renderer);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
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


void Game::readFile() {
	std::string line;
	
	std::ifstream f("Assets/Maps/world.txt");

	if (f.is_open())
	{
		std::cout << "File: opened" << std::endl;
		while (std::getline(f, line))
		{ 
			for (char num : line) {
				if (!isspace(num)) {
					worldInts.push_back(num-'0');
				}
			}
		}
		f.close();
	} else {
		std::cout << "File: Unable to open" << std::endl;
	}
}