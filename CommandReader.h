#pragma once
#include "Field.h"
#include "Enemy.h"
class CommandReader
{
public:
	~CommandReader();
	void ReadFromKeyb(Field*, Player*, std::vector<Enemy*>&, int);

};

