#pragma once
#include "Field.h"
#include <cmath>
class FieldGenerators
{
public:
	FieldGenerators();
	~FieldGenerators();
	void GeneratorWalls(Field*);
private:
	std::vector<std::vector<Cell>> TempMatrix;
};

