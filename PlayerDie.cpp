#include "PlayerDie.h"
#include <iostream>
#include <Windows.h>
#include "InputOutput.h"
void PlayerDie::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	if (!Plr->GetHP()) {
		matrix = Fld->GetField();
		matrix[Plr->GetX()][Plr->GetY()].SetC(' ');
		Fld->SetMatrix(matrix);
		InputOutput InOut;
		InOut.Print(Fld, Plr);
		std::cout << "Game Over! You Died!";
		Sleep(5000);
		
	}
}

PlayerDie::~PlayerDie()
{
}
