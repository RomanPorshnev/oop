#pragma once
#include "Field.h"
#include "Enemy.h"
#include "Command.h"
class CommandReader
{
public:
	CommandReader();
	~CommandReader();
	void ReadFromKeyb(Field*, Player*, std::vector<Enemy*>&, int);
private:
	Command* command;
};

