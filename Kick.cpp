#include "Kick.h"
#include "Event.h"
#include "LooseAmmoPlayer.h"
#include "LooseHealthEnemy.h"
#include "EnemyEvent.h"
#include "EnemyDie.h"

Kick::Kick()
{
}

Kick::~Kick()
{
}

void Kick::execute(Player* Plr, Field* Fld, Enemy* Enm)
{
	Event* ev1 = nullptr;
	TempMatrix = Fld->GetField();
	if (TempMatrix[Plr->GetX() + 1][Plr->GetY()].GetEnemyPos()) {
		if ((Plr->GetX() + 1 == Enm->GetX()) && (Plr->GetY() == Enm->GetY())) {
			ev1 = new LooseHealthEnemy();
		}
	}
	else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetEnemyPos()) {
			if ((Plr->GetX() - 1 == Enm->GetX()) && (Plr->GetY() == Enm->GetY())) {
				ev1 = new LooseHealthEnemy();
			}
	}
	else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetEnemyPos()) {
		if ((Plr->GetX() == Enm->GetX()) && (Plr->GetY() == Enm->GetY() + 1)) {
			ev1 = new LooseHealthEnemy();
		}
	}
	else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetEnemyPos()) {
		if ((Plr->GetX() == Enm->GetX()) && (Plr->GetY() == Enm->GetY() - 1)) {
			ev1 = new LooseHealthEnemy();
		}
	}
	if (ev1) {
		ev1->execute(Fld, Plr, Enm);
	}
	Event* ev2 = new EnemyDie();
	ev2->execute(Fld, Plr, Enm);
}
