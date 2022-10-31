#include "Start.h"
#include <iostream>
#include <Windows.h>
#include "Singleton.h"

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
	Singleton* singleton = singleton->GetInstance();
	InOut.Asking();
	Fld = new Field(InOut.GetM(), InOut.GetN());
	Fld->InitMatrix();
	FldGen.GeneratorWalls(Fld);
	FldGen.GeneratorHealth(Fld);
	FldGen.GeneratorEnemies(Fld, Enemies);
	Fld->SetPosPlayer(Plr);
	Plr->SetAmmo((int)(std::sqrt(Fld->GetM() * Fld->GetN()) / 4 * 3));
	InOut.Print(Fld, Plr);
	Frm.Update(Fld, Plr, Enemies);
}



