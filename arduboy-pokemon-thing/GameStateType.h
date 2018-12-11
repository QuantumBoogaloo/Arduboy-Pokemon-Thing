#pragma once
#include <stdint.h>

enum class GameStateType : uint8_t
{
	None,
	Startup,
	Menu,
	Overworld,
	Battle,
};