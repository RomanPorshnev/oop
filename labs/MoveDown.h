#pragma once
#include "Command.h"
#include "Field.h"
class MoveDown : public Command
{
public:
	MoveDown();
	~MoveDown();
	void execute(Player*, Field*);
};

