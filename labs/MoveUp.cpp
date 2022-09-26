#include "MoveUp.h"

MoveUp::MoveUp()
{
}

MoveUp::~MoveUp()
{
}

void MoveUp::execute(Player* Plr, Field* Fld)
{
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Fld->GetM());
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX() - 1][Plr->GetY()];
        Plr->SetX(Plr->GetX() - 1);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
}
