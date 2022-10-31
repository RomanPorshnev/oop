#include "Frames.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
#include "ReadFromKeyb.h"
#include <time.h>
#include "Event.h"
#include "FieldGenerators.h"
#include "EnemyAttack.h"
#define esc 27
Frames::Frames()
{
    singleton = singleton->GetInstance();
}

Frames::~Frames()
{
}

void Frames::Update(Field* Fld, Player* Plr, std::vector<Enemy*> Enemies)
{
    int key = 0;
    ReadFromKeyb Rfk;
    InputOutput InOut;
    singleton->logging(13);
    InOut.PrintLogsToConsole();
    InOut.PrintLogsToFile();
    FieldGenerators FldGen;
    clock_t start = clock(), end;
    do
    {
        end = clock();
        FldGen.GeneratorBombs(Fld, Enemies, Plr, start, end);
        if (_kbhit()) {
            key = _getch();
            Rfk.CommRead(Fld, Plr, Enemies, key);
            Rfk.LoggingRead(key);
            InOut.Print(Fld, Plr);
            InOut.PrintLogsToConsole();
            InOut.PrintLogsToFile();
        }
    } while (key != esc && Plr->GetHP() && CheckEnemies(Enemies));
    singleton->logging(14);
    InOut.Print(Fld, Plr);
    InOut.PrintLogsToConsole();
    InOut.PrintLogsToFile();
}

bool Frames::CheckEnemies(std::vector<Enemy*> Enemies)
{
    bool check = false;
    for (int i = 0; i < Enemies.size(); i++) {
        if (Enemies[i])
            check = true;
    }
    if (check) {
        return true;
    }
    else {
        std::cout << "You win!\n";
        for (int i = 0; i < Enemies.size(); i++) {
            delete Enemies[i];
        }
        Sleep(5000);
        return false;
    }
}
