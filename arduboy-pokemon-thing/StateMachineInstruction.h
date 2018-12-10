#pragma once

#include "GameStateType.h"

enum class StateMachineInstructionType
{
	None,
	Push,
	Drop,
	Change,
	DropAllPush,
};

struct StateMachineInstruction
{
	StateMachineInstructionType instruction = StateMachineInstructionType::None;
	GameStateType state = GameStateType::None;
	
	StateMachineInstruction() = default;
	StateMachineInstruction(StateMachineInstructionType instruction) : instruction(instruction) {}
	StateMachineInstruction(StateMachineInstructionType instruction, GameStateType state) : instruction(instruction), state(state) {}
};