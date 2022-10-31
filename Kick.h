#pragma once
#include "Command.h"
#include "EnemyEventFactory.h"
#include "PlayerEventFactory.h"
class Kick : public Command
{
public:
	Kick();
	~Kick();
	void execute(Player*, Field*, std::vector<Enemy*>&);
	bool direction(Player*, Field*, Enemy*, int v, int h);
private:
	bool hit;
	EventFactory* ev_factory_enm;
	EventFactory* ev_factory_plr;
	Event* ev_loose_hp_enemy;
	Event* ev_get_score_plr;
	Event* ev_enemy_die;
	Event* ev_loose_ammo_plr;
};

