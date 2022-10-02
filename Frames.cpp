#include "Frames.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
#include "CommandReader.h"
#include <time.h>
#include "Event.h"
#include "EnemySpawn.h"
#include "FieldGenerators.h"
#include "EnemyAttack.h"
Frames::Frames()
{
}

Frames::~Frames()
{
}

void Frames::Update(Field* Fld, Player* Plr)
{
    int key = 0;
    CommandReader CommRead;
    InputOutput InOut;
    do
    {
        if (_kbhit()) {
            key = _getch();
            CommRead.ReadFromKeyb(Fld, Plr, Enemies, key);
            InOut.Print(Fld, Plr);
        }
    } while (key != 27);
}
