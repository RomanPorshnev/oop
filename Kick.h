#pragma once
#include "Command.h"
class Kick : public Command
{
public:
	Kick();
	~Kick();
	void execute(Player*, Field*, Enemy*);
};

