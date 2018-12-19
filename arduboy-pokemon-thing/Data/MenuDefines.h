#pragma once

#include <avr/pgmspace.h>
#include "../utilities/FlashString.h"

#include "MenuReturn.h"
#include "MenuItem.h"

// Main menu
const char StringMainMenuStart[] PROGMEM = "New Game";
const char StringMainMenuLoad[] PROGMEM = "Load Game";

const MenuItem MainMenuItems[] PROGMEM =
{
	MenuItem(asFlashString(StringMainMenuStart), MenuReturn::MainNewGame),
	MenuItem(asFlashString(StringMainMenuLoad), MenuReturn::MainLoadGame),
};