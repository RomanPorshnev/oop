#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
class PlayerMoving
{
public:
	PlayerMoving();
	~PlayerMoving();
	void Move(Field*, Player*);
private:
	std::vector<std::vector<Cell>> TempMatrix;
	std::vector<Enemy*> Enemies;
};

