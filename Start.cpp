#include "Start.h"
#include <iostream>
#include "InputOutput.h"
#include "Field.h"
#include "FieldGenerators.h"
#include "PlayerMoving.h"
#include "Frames.h"
void Start::run()
{
	InputOutput InOut;
	InOut.Asking();
	system("cls");
	Field *Fld = new Field(InOut.GetM(), InOut.GetN());
	Fld->InitMatrix();
	FieldGenerators FldGen;
	FldGen.GeneratorWalls(Fld);
	FldGen.GeneratorHealth(Fld);
	Player *Plr = new Player();
	Fld->SetPosPlayer(Plr);
	Frames Frm;
	//PlayerMoving PlrMove;
	InOut.Print(Fld, Plr);
	//PlrMove.Move(Fld, Plr);
	Frm.Update(Fld, Plr);
	delete Fld;
	delete Plr;
}



