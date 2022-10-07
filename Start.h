#pragma once
#include "Enemy.h"
#include <vector>
class Start
{
public:
	void run();
private:
	std::vector<Enemy*> Enemies;
};

