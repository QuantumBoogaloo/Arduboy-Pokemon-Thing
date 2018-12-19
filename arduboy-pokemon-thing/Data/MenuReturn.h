#pragma once

#include <stdint.h>

enum class MenuReturn : uint8_t
{
	None,
	
	//Generic
	Yes,
	No,
	
	//Main
	MainNewGame,
	MainLoadGame,
};