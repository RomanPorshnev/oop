#include "Start.h"
#include <iostream>
#include "InputOutput.h"
#include "Field.h"
#include "FieldGenerators.h"
#include "PlayerMoving.h"
void Start::run()
{
	InputOutput InOut;
	InOut.Asking();
	Field Fld(InOut.GetM(), InOut.GetN());
	Fld.InitMatrix();
	FieldGenerators FldGen;
	FldGen.GeneratorWalls(Fld);
	//Player Plr;
	//Fld.SetPosPlayer(Plr);
	//PlayerMoving PlrMove;
	//InOut.Print(Fld);
	//PlrMove.Move(Fld, Plr);
}
