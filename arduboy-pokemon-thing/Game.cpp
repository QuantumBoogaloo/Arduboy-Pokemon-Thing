#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	if(!arduboy.nextFrame())
		return;
	
	if(this->stateStack.isEmpty())
		statePush(GameStateType::Startup);
	
	auto & stateCurrent = this->stateStack[this->stateStack.getCount() - 1];
	stateCurrent->update();
	stateCurrent->draw();
	
	arduboy.display();
}

//States
void Game::stateDropAll()
{
	while(!this->stateStack.isEmpty())
		stateDrop();
}

void Game::stateDrop()
{
	if(this->stateStack.isEmpty())
		return;
	delete this->stateStack[this->stateStack.getCount() - 1];
	this->stateStack.drop();
}

}