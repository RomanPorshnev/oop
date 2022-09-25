#pragma once
#include "Player.h"
#include "Field.h"
class PlayerMoving
{
public:
	PlayerMoving();
	~PlayerMoving();
	void Move(Field, Player);
private:
	std::vector<std::vector<Cell>> TempMatrix;
};

