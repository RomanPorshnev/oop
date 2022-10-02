#include "MoveRight.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"

MoveRight::MoveRight()
{
}

MoveRight::~MoveRight()
{
}

void MoveRight::execute(Player* Plr, Field* Fld, Enemy* Enm)
{
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    Event* ev = nullptr;
    if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(1);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX()][Plr->GetY() + 1];
        Plr->SetY(Plr->GetY() + 1);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetHealthPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = new GetHealthPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = new GetAmmoPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = new LooseHealthPlayer();
    }
    if (ev) {
        ev->execute(Fld, Plr, nullptr);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
}

