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

//States
void Game::stateDropAll()
{
	while(!this->stateStack.isEmpty())
		stateDrop();
}
}