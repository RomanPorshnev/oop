#include "MoveLeft.h"

MoveLeft::MoveLeft()
{
}

MoveLeft::~MoveLeft()
{
}

void MoveLeft::execute(Player* Plr, Field* Fld)
{
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Fld->GetN());
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX()][Plr->GetY() - 1];
        Plr->SetY(Plr->GetY() - 1);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
}
