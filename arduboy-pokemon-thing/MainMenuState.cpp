#include "MainMenuState.h"

void MainMenuState::enter(UIContainer & uiContainer)
{
	static_cast<void>(uiContainer);
	command = UICommand(UICommandType::Push, UIStateType::MainMenu);
}

void MainMenuState::update(Arduboy2 & arduboy, UIContainer & uiContainer)
{
	static_cast<void>(arduboy);
	static_cast<void>(uiContainer);
}

void MainMenuState::draw(Arduboy2 & arduboy)
{
	static_cast<void>(arduboy);
}