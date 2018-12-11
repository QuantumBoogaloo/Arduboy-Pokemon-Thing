#include "StartupState.h"

void StartupState::update(Arduboy2 & arduboy)
{
}

void StartupState::draw(Arduboy2 & arduboy)
{
	arduboy.print(F("STANDBY"));
}