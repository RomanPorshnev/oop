#include "MoveUp.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
MoveUp::MoveUp()
{
}

MoveUp::~MoveUp()
{
}

void MoveUp::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    TempMatrix = Fld->GetField();
    Event* ev = nullptr;
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Fld->GetM());
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX() - 1][Plr->GetY()];
        Plr->SetX(Plr->GetX() - 1);
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetHealthPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = new GetHealthPlayer();
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = new GetAmmoPlayer();
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
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
