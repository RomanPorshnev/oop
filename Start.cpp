#include "Start.h"
#include <iostream>
#include <Windows.h>
Start::Start() {
	Fld = new Field(InOut.GetM(), InOut.GetN());
	Plr = new Player();
}

Start::~Start() {
	delete Fld;
	delete Plr;
}
void Start::run()
{
	InOut.Asking();
	Fld = new Field(InOut.GetM(), InOut.GetN());
	Fld->InitMatrix();
	FldGen.GeneratorWalls(Fld);
	FldGen.GeneratorHealth(Fld);
	FldGen.GeneratorEnemies(Fld, Enemies);
	Fld->SetPosPlayer(Plr);
	InOut.Print(Fld, Plr);
	Frm.Update(Fld, Plr, Enemies);
}



