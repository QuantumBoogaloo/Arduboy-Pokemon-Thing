#pragma once
#include <stdint.h>

enum class GameStateType : uint8_t
{
	Startup,
	Menu,
	Overworld,
	Battle,
};