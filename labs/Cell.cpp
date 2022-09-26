#include "Cell.h"

Cell::Cell(char c = ' ') : c(c)
{
	
}

Cell::~Cell()
{
}

char Cell::GetC()
{
	return this->c;
}

void Cell::SetC(int c_new)
{
	c = c_new;
}

bool Cell::GetPersonPos()
{
	return (this->c == '+');
}

bool Cell::GetWallPos()
{
	return (this->c == '#');
}

bool Cell::GetBoarderPos()
{
	return (this->c == '@');
}

bool Cell::GetEmptyPos()
{
	return (this->c == ' ');
}

