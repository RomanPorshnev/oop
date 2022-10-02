#include "PlayerDie.h"
#include <iostream>
#include <Windows.h>
void PlayerDie::execute(Field* Field, Player* Plr, Enemy* Enm)
{
	if (Plr->GetHP() == 0) {
		std::cout << "Game Over! You Died!";
		Sleep(3000);
		exit(0);
	}
}

PlayerDie::~PlayerDie()
{
}
