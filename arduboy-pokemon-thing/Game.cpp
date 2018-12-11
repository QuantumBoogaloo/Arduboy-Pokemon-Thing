#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	if(!arduboy.nextFrame())
		return;
	
	states.update();
	
	arduboy.display();
}