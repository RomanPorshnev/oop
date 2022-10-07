#pragma once
#include "Field.h"
#include <cmath>
#include "Enemy.h"
#include "time.h"
class FieldGenerators
{
public:
	FieldGenerators();
	~FieldGenerators();
	void GeneratorWalls(Field*);
	void GeneratorHealth(Field*);
	void GeneratorEnemies(Field*, std::vector<Enemy*>&);
	void GeneratorBombs(Field*, std::vector<Enemy*> Enemies, Player* Plr, clock_t& start, clock_t end);
private:
	std::vector<std::vector<Cell>> TempMatrix;
};

