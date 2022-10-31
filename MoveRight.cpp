#include "MoveRight.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"

MoveRight::MoveRight()
{
    ev = nullptr;
    ev_factory = new PlayerEventFactory();
    ev_plr_die = nullptr;
    singleton = singleton->GetInstance();
}

MoveRight::~MoveRight()
{
    delete ev;
    delete ev_factory;
    delete ev_plr_die;
}

void MoveRight::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    singleton->logging(7);
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
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
        singleton->logging(2);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = ev_factory->CreateGetAmmoPlayer();
        singleton->logging(3);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() + 1);
        ev = ev_factory->CreateLooseHealthPlayer();
        singleton->logging(4);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() + 1].GetWallPos()) {
        singleton->logging(5);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
    if (ev) {
        ev->execute(Fld, Plr, nullptr);
        ev_plr_die = ev_factory->CreatePlayerDie();
        ev_plr_die->execute(Fld, Plr, nullptr);
    }
}

