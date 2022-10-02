#pragma once
#include "Field.h"
#include <cmath>
class FieldGenerators
{
public:
	FieldGenerators();
	~FieldGenerators();
	void GeneratorWalls(Field*);
	void GeneratorHealth(Field*);
private:
	std::vector<std::vector<Cell>> TempMatrix;
};

