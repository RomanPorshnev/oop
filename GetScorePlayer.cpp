#include "GetScorePlayer.h"

void GetScorePlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Plr->SetScore(Plr->GetScore() + 100);
}

GetScorePlayer::~GetScorePlayer()
{
}
