#include "GetAmmoPlayer.h"

void GetAmmoPlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Plr->SetAmmo(Plr->GetAmmo() + 1);
}

GetAmmoPlayer::~GetAmmoPlayer()
{
}
