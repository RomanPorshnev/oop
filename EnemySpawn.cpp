#include "EnemySpawn.h"

void EnemySpawn::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	bool flag = false;
	int x_rand, y_rand;
	std::vector<std::vector<Cell>> TempMatrix = Fld->GetField();
	do {
		x_rand = 1 + rand() % (Fld->GetM() - 1);
		y_rand = 1 + rand() % (Fld->GetN() - 1);
		if (TempMatrix[x_rand][y_rand].GetEmptyPos()) {
			TempMatrix[x_rand][y_rand].SetC('0');
			flag = true;
		}
	} while (!flag);
	Enm->SetX(x_rand);
	Enm->SetY(y_rand);
	Fld->SetMatrix(TempMatrix);
}

EnemySpawn::~EnemySpawn()
{
}
