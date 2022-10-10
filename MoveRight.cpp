#include "MoveRight.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
#include "EventFactory.h"
#include "PlayerEventFactory.h"
MoveRight::MoveRight()
{
}

MoveRight::~MoveRight()
{
}

void MoveRight::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    Event* ev = nullptr;
    EventFactory* ev_factory = new PlayerEventFactory();
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
        ev = ev_factory->CreateGetHealthPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = ev_factory->CreateGetAmmoPlayer();
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
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

