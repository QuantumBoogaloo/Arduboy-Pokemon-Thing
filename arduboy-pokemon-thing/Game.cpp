#include "Game.h"

void Game::begin()
{
	arduboy.begin();
}

void Game::update()
{
	if(!arduboy.nextFrame())
		return;
	arduboy.pollButtons();
	
	arduboy.display();
}

}