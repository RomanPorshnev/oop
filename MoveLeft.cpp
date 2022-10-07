#include "MoveLeft.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
MoveLeft::MoveLeft()
{
}

MoveLeft::~MoveLeft()
{
}

void MoveLeft::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    Event* ev = nullptr;
    if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Fld->GetN());
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX()][Plr->GetY() - 1];
        Plr->SetY(Plr->GetY() - 1);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetHealthPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = new GetHealthPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = new GetAmmoPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = new LooseHealthPlayer();
    }
    if (ev) {
        ev->execute(Fld, Plr, nullptr);
        Event* ev_plr_die = new PlayerDie();
        ev_plr_die->execute(Fld, Plr, nullptr);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);

}
