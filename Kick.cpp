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
	ev_factory_enm = new EnemyEventFactory();
	ev_factory_plr = new PlayerEventFactory();
	ev_loose_hp_enemy = nullptr;
	ev_get_score_plr = nullptr;
	ev_enemy_die = nullptr;
	ev_loose_ammo_plr = nullptr;
	singleton = singleton->GetInstance();
}

Kick::~Kick()
{
	delete ev_factory_enm; 
	delete ev_factory_plr;
	delete ev_loose_hp_enemy;
	delete ev_get_score_plr;
	delete ev_enemy_die;
	delete ev_loose_ammo_plr;

}

void Kick::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
	hit = false;
	for (int i = 0; i < Enemies.size(); i++) {
		ev_loose_hp_enemy = nullptr;
		TempMatrix = Fld->GetField();
		if ((Enemies[i]) && (direction(Plr, Fld, Enemies[i], 1, 0) || direction(Plr, Fld, Enemies[i], -1, 0)
			|| direction(Plr, Fld, Enemies[i], 0, 1) || direction(Plr, Fld, Enemies[i], 0, -1))) {
			ev_loose_hp_enemy = ev_factory_enm->CreateLooseHealthEnemy();
		}
		if (ev_loose_hp_enemy && Enemies[i]) {
			hit = true;
			ev_loose_hp_enemy->execute(Fld, Plr, Enemies[i]);
			singleton->logging(9);
			ev_get_score_plr = ev_factory_plr->CreateGetScorePlayer();
			ev_get_score_plr->execute(Fld, Plr, Enemies[i]);
			ev_enemy_die = ev_factory_enm->CreateEnemyDie();
			ev_enemy_die->execute(Fld, Plr, Enemies[i]);
			if (!Enemies[i]->GetHP()) {
				singleton->logging(11);
				singleton->logging(10);
				Enemies[i] = nullptr;
			}
		}
	}
	if (!hit) {
		singleton->logging(12);
	}
	ev_loose_ammo_plr = ev_factory_plr->CreateLooseAmmoPlayer();
	ev_loose_ammo_plr->execute(Fld, Plr, nullptr);
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
