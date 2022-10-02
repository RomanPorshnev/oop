#pragma once
#include "Command.h"
#include "Field.h"
class MoveUp : public Command
{
public:
	MoveUp();
	~MoveUp();
	void execute(Player*, Field*, Enemy*);
};

