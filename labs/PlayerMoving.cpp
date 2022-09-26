#include "PlayerMoving.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
#include "Command.h"
#include "MoveDown.h"
#include "MoveUp.h"
#include "MoveLeft.h"
#include "MoveRight.h"

#define down 115
#define up 119
#define left 97
#define right 100

PlayerMoving::PlayerMoving()
{
}

PlayerMoving::~PlayerMoving()
{
}

void PlayerMoving::Move(Field *Fld, Player *Plr)
{
    int key;
    char c;
    do
    {   
        Command* command = nullptr;
        key = _getch();
        if (key == down)
        {
            command = new MoveDown();
            
        }

        if (key == up)
        {
            command = new MoveUp();
        }

        if (key == left)
        {
            command = new MoveLeft();
        }
        if (key == right)
        {
            command = new MoveRight();
        }

        if (command) {
            command->execute(Plr, Fld);
        }
        HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD cd;
        cd.X = 0;
        cd.Y = 0;
        SetConsoleCursorPosition(hd, cd);
        InputOutput InOut;
        InOut.Print(Fld);
    } while (key != 27);
}
    
