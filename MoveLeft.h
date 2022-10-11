#pragma once
#include "Command.h"
#include "Field.h"
#include "EventFactory.h"
#include "PlayerEventFactory.h"
class MoveLeft : public Command
{
public:
	MoveLeft();
	~MoveLeft();
	void execute(Player*, Field*, std::vector<Enemy*>&);
private:
	Event* ev;
	EventFactory* ev_factory;
	Event* ev_plr_die;
};

