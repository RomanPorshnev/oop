#include "MoveUp.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
#include "EventFactory.h"
#include "PlayerEventFactory.h"
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
    EventFactory* ev_factory = new PlayerEventFactory();
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
        ev = ev_factory->CreateGetHealthPlayer();
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = ev_factory->CreateGetAmmoPlayer();
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = ev_factory->CreateLooseHealthPlayer();
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
    if (ev) {
        ev->execute(Fld, Plr, nullptr);
        Event* ev_plr_die = ev_factory->CreatePlayerDie();
        ev_plr_die->execute(Fld, Plr, nullptr);
    }
}
