#include <iostream>

#include "SDL.h"
#include "hPlayer.h"

void Player::input(SDL_Event movement) {
	switch (movement.key.keysym.sym) {
		case SDLK_w:
			std::cout << "W PRESSED" << std::endl;
			playerMove = FORWARD;
			break;

		case SDLK_a:
			std::cout << "A PRESSED" << std::endl;
			playerMove = LEFT;
			break;

		case SDLK_d:
			std::cout << "D PRESSED" << std::endl;
			playerMove = RIGHT;
			break;

		case SDLK_s:
			std::cout << "S PRESSED" << std::endl;
			playerMove = BACKWARDS;
			break;

		default:
			playerMove = NONE;
			break; 
	}
}

void Player::shiftDirection() {
	switch (playerMove) {
	case FORWARD:
		rect.y += 1;
		break;

	case BACKWARDS:
		rect.y -= 1;
		break;

	case LEFT:
		rect.x -= 1;
		break;

	case RIGHT:
		rect.x += 1;
		break;
	}
	
}

void Player::update() {
	std::cout << "Player xPos: " << rect.x << std::endl;
	std::cout << "Player yPos: " << rect.y << std::endl;
	std::cout << "Player MovementDir: " << playerMove << std::endl;
	shiftDirection();
}