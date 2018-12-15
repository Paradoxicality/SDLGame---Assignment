#include <iostream>
#include <fstream>
#include <string>
#include "SDL.h"
#include "hGameEngine.h"
#include "hGameTimer.h"
#include "hGameObject.h"

bool Game::init() {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //If SDL initializes / is setup right
		std::cout << "SDL initialized" << std::endl; //Debug

		window = SDL_CreateWindow("17631941 - Brennan Ceballos Pena - Games Computing - Temporary Name ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN); //Set window params and create window

		if (window != NULL) {
			std::cout << "Window initialized" << std::endl; //Debug
		}

		renderer = SDL_CreateRenderer(window, 0, 0); //Set rendrer params and create renderer

		if (renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Renderer initialized" << std::endl; //Debug
		}
	}
	else {
		return false; //If can't initialize set game running to false
	}

	isRunning = true;

	readFile();
	build();

	return true; //Set the game running to true */
}

void Game::build() {


	for (int h = 0; h < windowColumns; h++) {

		for (int w = 0; w < windowRows; w++) {
			GameObject tile = GameObject();
			tile.rect.x = w * blockSize;
			tile.rect.y = h * blockSize;
			tile.rect.w = blockSize;
			tile.rect.h = blockSize;


			switch (worldInts[(h*windowRows) + w])
			{
			case 0:
				tile.init(0,0,0);
				worldTiles.push_back(tile);
				break;
			case 1:
				player.init(255,0,0);
				player.rect.x = w * blockSize;
				player.rect.y = h * blockSize;
				player.rect.w = blockSize;
				player.rect.h = blockSize;
				break;
			case 2:
				tile.init(0,0,255);
				worldTiles.push_back(tile);
				break;
			case 3:
				tile.init(0,255,0);
				worldTiles.push_back(tile);
				break;
			case 4:
				tile.init(255,0,255);
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
	player.update();
}

void Game::lateUpdate() {

}

void Game::render() {
	SDL_RenderClear(renderer); //Clear the renderer's buffer

	for (GameObject object : worldTiles) {
		object.render(renderer);
	}
	player.render(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderPresent(renderer);
}

void Game::input() {
	SDL_Event event; //Check events 

	while (SDL_PollEvent(&event) != 0) { //Get type of event, event is dereferenced

		switch (event.type) { //If the event is SDL_QUIT, break the game loop and quit the game
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			player.input(event);
			break;
		}

	}
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