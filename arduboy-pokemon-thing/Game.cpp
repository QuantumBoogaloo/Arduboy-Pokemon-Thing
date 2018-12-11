#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	if(!arduboy.nextFrame())
		return;
	arduboy.pollButtons();
	
	states.update(arduboy);
	
	arduboy.display();
}