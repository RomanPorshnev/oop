#pragma once
#include "EnemyEvent.h"
class EnemyAttack : public EnemyEvent
{
public:
	void execute(Field* Fld, Player* Plr, Enemy* Enm);
	~EnemyAttack();
};

