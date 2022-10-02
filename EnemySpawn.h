#pragma once
#include "EnemyEvent.h"
class EnemySpawn : public EnemyEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~EnemySpawn();
};

