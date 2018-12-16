#include "MainMenuState.h"

void MainMenuState::enter(UIContainer & uiContainer)
{
	uiContainer.push(UIStateType::Textbox);
	
}

void MainMenuState::update(Arduboy2 & arduboy, UIContainer & uiContainer)
{
}

void MainMenuState::draw(Arduboy2 & arduboy)
{
	arduboy.print("testing123");
}