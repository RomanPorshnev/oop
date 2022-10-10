#include "Kick.h"
#include "Event.h"
#include "LooseAmmoPlayer.h"
#include "LooseHealthEnemy.h"
#include "GetScorePlayer.h"
#include "EnemyEvent.h"
#include "EnemyDie.h"
#include <iostream>
#include "Windows.h"
#include "EnemyEventFactory.h"
#include "PlayerEventFactory.h"
Kick::Kick()
{
}

Kick::~Kick()
{
}

void Kick::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
	EventFactory* ev_factory_enm = new EnemyEventFactory();
	EventFactory* ev_factory_plr = new PlayerEventFactory();
	for (int i = 0; i < Enemies.size(); i++) {
		Event* ev_loose_hp_enemy = nullptr;
		TempMatrix = Fld->GetField();
		if ((Enemies[i]) && (direction(Plr, Fld, Enemies[i], 1, 0) || direction(Plr, Fld, Enemies[i], -1, 0)
			|| direction(Plr, Fld, Enemies[i], 0, 1) || direction(Plr, Fld, Enemies[i], 0, -1))) {
			ev_loose_hp_enemy = ev_factory_enm->CreateLooseHealthEnemy();
		}
		if (ev_loose_hp_enemy && Enemies[i]) {
			ev_loose_hp_enemy->execute(Fld, Plr, Enemies[i]); 
			Event* ev_get_score_plr = ev_factory_plr->CreateGetScorePlayer();
			ev_get_score_plr->execute(Fld, Plr, Enemies[i]);
			Event* ev_enemy_die = ev_factory_enm->CreateEnemyDie();
			ev_enemy_die->execute(Fld, Plr, Enemies[i]);
			if (!Enemies[i]->GetHP()) {
				Enemies[i] = nullptr;
			}
			delete ev_get_score_plr; delete ev_enemy_die;
		}
		delete ev_loose_hp_enemy;
	}
	Event* ev_loose_ammo_plr = ev_factory_plr->CreateLooseAmmoPlayer();
	ev_loose_ammo_plr->execute(Fld, Plr, nullptr);
	delete ev_loose_ammo_plr;
	delete ev_factory_enm; delete ev_factory_plr;
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
