#include "PlayerMoving.h"
#include <conio.h>
#include "InputOutput.h"
#include <windows.h>
#include "CommandReader.h"
#include <time.h>
#include "Event.h"
#include "EnemySpawn.h"
#include "FieldGenerators.h"
#include "EnemyAttack.h"
PlayerMoving::PlayerMoving()
{
}

PlayerMoving::~PlayerMoving()
{
}

void PlayerMoving::Move(Field *Fld, Player *Plr)
{
    int key = 0;
    CommandReader CommRead;
    clock_t start_spawn = clock(), start_drop = clock(), end;
    InputOutput InOut;
    do
    {
        end = clock();
        /*if ((end - start_spawn) / CLOCKS_PER_SEC > 10) {
            Enemy* Enm = new Enemy();
            Event* ev = new EnemySpawn();
            ev->execute(Fld, Plr, Enm);
            Enemies.push_back(Enm);
            start_spawn = clock();
            InOut.Print(Fld, Plr);
        }
        if ((end - start_drop) / CLOCKS_PER_SEC > 2) {
            for (int i = 0; i < Enemies.size(); i++) {
                Event* ev = new EnemyAttack();
                ev->execute(Fld, Plr, Enemies[i]);
            }
            start_drop = clock();
            InOut.Print(Fld, Plr);
        }
        */
        if (_kbhit()) {
            key = _getch();
            CommRead.ReadFromKeyb(Fld, Plr, Enemies, key);
            InOut.Print(Fld, Plr);
        }
    } while (key != 27);
}
    
