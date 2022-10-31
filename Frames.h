#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
#include "Singleton.h"
class Frames
{
public:
	Frames();
	~Frames();
	void Update(Field*, Player*, std::vector<Enemy*>);

private:
	Singleton* singleton;
	bool CheckEnemies(std::vector<Enemy*> Enemies);
	std::vector<std::vector<Cell>> TempMatrix;
	std::vector<Enemy*> Enemies;
};
