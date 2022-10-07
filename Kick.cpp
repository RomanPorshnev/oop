#include "Kick.h"
#include "Event.h"
#include "LooseAmmoPlayer.h"
#include "LooseHealthEnemy.h"
#include "GetScorePlayer.h"
#include "EnemyEvent.h"
#include "EnemyDie.h"
#include <iostream>
#include "Windows.h"
Kick::Kick()
{
}

Kick::~Kick()
{
}

void Kick::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
	for (int i = 0; i < Enemies.size(); i++) {
		Event* ev_loose_hp_enemy = nullptr;
		TempMatrix = Fld->GetField();
		if ((Enemies[i]) && (direction(Plr, Fld, Enemies[i], 1, 0) || direction(Plr, Fld, Enemies[i], -1, 0)
			|| direction(Plr, Fld, Enemies[i], 0, 1) || direction(Plr, Fld, Enemies[i], 0, -1))) {
			ev_loose_hp_enemy = new LooseHealthEnemy();
		}
		if (ev_loose_hp_enemy && Enemies[i]) {
			ev_loose_hp_enemy->execute(Fld, Plr, Enemies[i]);
			Event* ev_get_score_plr = new GetScorePlayer;
			ev_get_score_plr->execute(Fld, Plr, Enemies[i]);
			Event* ev_enemy_die = new EnemyDie();
			ev_enemy_die->execute(Fld, Plr, Enemies[i]);
			if (!Enemies[i]->GetHP()) {
				Enemies[i] = nullptr;
			}
			delete ev_get_score_plr; delete ev_enemy_die;
		}
		delete ev_loose_hp_enemy;
	}
	Event* ev_loose_ammo_plr = new LooseAmmoPlayer();
	ev_loose_ammo_plr->execute(Fld, Plr, nullptr);
	delete ev_loose_ammo_plr;
}

bool Kick::direction(Player* Plr, Field* Fld, Enemy* Enm, int v, int h)
{
	if (TempMatrix[Plr->GetX() + v][Plr->GetY() + h].GetEnemyPos()) {
		if ((Plr->GetX() + v == Enm->GetX()) && (Plr->GetY() + h == Enm->GetY())) {
			if (Plr->GetAmmo())
				return true;
		}
	}
	return false;
}
