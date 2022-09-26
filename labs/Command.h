#pragma once
#include "Player.h"
#include "Field.h"
class Command
{
public:
	virtual ~Command();
	virtual void execute(Player*, Field*) = 0;
protected:
	std::vector<std::vector<Cell>> TempMatrix;
};

