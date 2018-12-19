#include "MainMenuState.h"

void MainMenuState::enter(UIContainer & uiContainer)
{
	command = UICommand(UICommandType::Push, UIStateType::MainMenu);
}

void MainMenuState::update(Arduboy2 & arduboy, UIContainer & uiContainer)
{
}

void MainMenuState::draw(Arduboy2 & arduboy)
{
	
}