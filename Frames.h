#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
class Frames
{
public:
	Frames();
	~Frames();
	void Update(Field*, Player*);
private:
	std::vector<std::vector<Cell>> TempMatrix;
	std::vector<Enemy*> Enemies;
};
