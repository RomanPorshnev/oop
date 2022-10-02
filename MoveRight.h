#pragma once
#include "Command.h"
#include "Field.h"
class MoveRight : public Command
{
public:
	MoveRight();
	~MoveRight();
	void execute(Player*, Field*, Enemy*);
};

