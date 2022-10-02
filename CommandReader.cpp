#include "CommandReader.h"
#include "PlayerMoving.h"
#include "Command.h"
#include "MoveDown.h"
#include "MoveUp.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Kick.h"
#include <iostream>
#include <Windows.h>

#define down 115
#define up 119
#define left 97
#define right 100
#define kick 320
CommandReader::~CommandReader()
{
}

void CommandReader::ReadFromKeyb(Field* Fld, Player* Plr, std::vector<Enemy*>& Enemies, int key)
{
    Command* command = nullptr;
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
    if (key == kick) {
        command = new Kick();
    }
    if (command) {
        command->execute(Plr, Fld, nullptr);
        /*for (int i = 0; Enemies.size(); i++) {
            command->execute(Plr, Fld, Enemies[i]);
        }
        */
            
    }
}
