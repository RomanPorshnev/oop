#pragma once
#include "Command.h"
class Kick : public Command
{
public:
	Kick();
	~Kick();
	void execute(Player*, Field*, std::vector<Enemy*>&);
	bool direction(Player*, Field*, Enemy*, int v, int h);
};

