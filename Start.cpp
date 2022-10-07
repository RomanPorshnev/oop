#include "Start.h"
#include <iostream>
#include "InputOutput.h"
#include "Field.h"
#include "FieldGenerators.h"
#include "Frames.h"
#include <Windows.h>
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
	FldGen.GeneratorEnemies(Fld, Enemies);
	Player *Plr = new Player();
	Fld->SetPosPlayer(Plr);
	Frames Frm;
	InOut.Print(Fld, Plr);
	Frm.Update(Fld, Plr, Enemies);
	delete Fld;
	delete Plr;
}



