#include "Frames.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
#include "CommandReader.h"
#include <time.h>
#include "Event.h"
#include "FieldGenerators.h"
#include "EnemyAttack.h"
#define esc 27
Frames::Frames()
{
}

Frames::~Frames()
{
}

void Frames::Update(Field* Fld, Player* Plr, std::vector<Enemy*> Enemies)
{
    int key = 0;
    CommandReader CommRead;
    InputOutput InOut;
    FieldGenerators FldGen;
    clock_t start = clock(), end;
    do
    {
        end = clock();
        FldGen.GeneratorBombs(Fld, Enemies, Plr, start, end);
        if (_kbhit()) {
            key = _getch();
            CommRead.ReadFromKeyb(Fld, Plr, Enemies, key);
            InOut.Print(Fld, Plr);
        }
    } while (key != esc && Plr->GetHP() && InOut.CheckEnemies(Enemies));
}
