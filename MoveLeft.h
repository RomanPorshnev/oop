#pragma once
#include "Command.h"
#include "Field.h"
class MoveLeft : public Command
{
public:
	MoveLeft();
	~MoveLeft();
	void execute(Player*, Field*, std::vector<Enemy*>&);
};

