#include "PlayerMoving.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
PlayerMoving::PlayerMoving()
{
}

PlayerMoving::~PlayerMoving()
{
}

void PlayerMoving::Move(Field Fld, Player Plr)
{
    int key;
    char c;
    TempMatrix = Fld.GetField();
    do
    {
        c = TempMatrix[Plr.GetX()][Plr.GetY()].GetC();
        key = _getch();
        if (key == 115)
        {
            //down//
            if (TempMatrix[Plr.GetX() + 1][Plr.GetY()].GetBoarderPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()].SetC(' ');
                Plr.SetX(1);
            }
            else if (TempMatrix[Plr.GetX() + 1][Plr.GetY()].GetEmptyPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()] = TempMatrix[Plr.GetX() + 1][Plr.GetY()];
                Plr.SetX(Plr.GetX() + 1);
            }
            TempMatrix[Plr.GetX()][Plr.GetY()].SetC(c);
        }

        if (key == 119)
        {
            // up//
            if (TempMatrix[Plr.GetX() - 1][Plr.GetY()].GetBoarderPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()].SetC(' ');
                Plr.SetX(Fld.GetM());
            }
            else if (TempMatrix[Plr.GetX() - 1][Plr.GetY()].GetEmptyPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()] = TempMatrix[Plr.GetX() - 1][Plr.GetY()];
                Plr.SetX(Plr.GetX() - 1);
            }
            TempMatrix[Plr.GetX()][Plr.GetY()].SetC(c);
        }

        if (key == 97)
        {
            // left//
            if (TempMatrix[Plr.GetX()][Plr.GetY() - 1].GetBoarderPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()].SetC(' ');
                Plr.SetY(Fld.GetN());
            }
            else if (TempMatrix[Plr.GetX()][Plr.GetY() - 1].GetEmptyPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()] = TempMatrix[Plr.GetX()][Plr.GetY() - 1];
                Plr.SetY(Plr.GetY() - 1);
            }
            TempMatrix[Plr.GetX()][Plr.GetY()].SetC(c);
        }
        if (key == 100)
        {
            // right//
            if (TempMatrix[Plr.GetX()][Plr.GetY() + 1].GetBoarderPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()].SetC(' ');
                Plr.SetY(1);
            }
            else if (TempMatrix[Plr.GetX()][Plr.GetY() + 1].GetEmptyPos()) {
                TempMatrix[Plr.GetX()][Plr.GetY()] = TempMatrix[Plr.GetX()][Plr.GetY() + 1];
                Plr.SetY(Plr.GetY() + 1);
            }
            TempMatrix[Plr.GetX()][Plr.GetY()].SetC(c);
        }
        system("cls");
        Fld.SetMatrix(TempMatrix);
        InputOutput InOut;
        InOut.Print(Fld);

    } while (key != 27);
}
    
