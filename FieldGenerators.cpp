#include "FieldGenerators.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyAttack.h"
#include "Field.h"
#include "Player.h"
#include "Player.h"
#include "Windows.h"
FieldGenerators::FieldGenerators()
{
}

FieldGenerators::~FieldGenerators()
{
}

void FieldGenerators::GeneratorWalls(Field *Fld)
{
    int k = 0;
    int x_rand;
    int y_rand;
    TempMatrix = Fld->GetField();
    do
    {
        x_rand = 2 + rand() % (Fld->GetM() - 2);
        y_rand = 2 + rand() % (Fld->GetN() - 2);
        if ((x_rand != 0) || (y_rand != 0))
        {
            TempMatrix[x_rand][y_rand].SetC('#');
            k++;
        }
    } while (k < int(std::sqrt(Fld->GetM() * Fld->GetN())));
    Fld->SetMatrix(TempMatrix);
    TempMatrix = Fld->GetField();
}

void FieldGenerators::GeneratorHealth(Field* Fld)
{
    int k = 0;
    int x_rand;
    int y_rand;
    TempMatrix = Fld->GetField();
    do
    {
        x_rand = 2 + rand() % (Fld->GetM() - 2);
        y_rand = 2 + rand() % (Fld->GetN() - 2);
        if ((x_rand != 0) || (y_rand != 0))
        {
            TempMatrix[x_rand][y_rand].SetC('%');
            k++;
        }
    } while (k < int(std::sqrt(Fld->GetM() * Fld->GetN())/4));
    Fld->SetMatrix(TempMatrix);
    TempMatrix = Fld->GetField();
}

void FieldGenerators::GeneratorEnemies(Field* Fld, std::vector<Enemy*>& Enemies)
{
    int k = 0;
    int x_rand;
    int y_rand;
    TempMatrix = Fld->GetField();
    do
    {
        x_rand = 2 + rand() % (Fld->GetM() - 2);
        y_rand = 2 + rand() % (Fld->GetN() - 2);
        if ((x_rand != 0) || (y_rand != 0))
        {
            TempMatrix[x_rand][y_rand].SetC('0');
            Enemy* Enm = new Enemy(x_rand, y_rand);
            Enemies.push_back(Enm);
            k++;
        }
    } while (k < (std::sqrt(Fld->GetM() * Fld->GetN()) / 4));
    Fld->SetMatrix(TempMatrix);
    TempMatrix = Fld->GetField();
}

void FieldGenerators::GeneratorBombs(Field* Fld, std::vector<Enemy*> Enemies, Player* Plr, clock_t& start, clock_t end)
{
    if ((end - start) / CLOCKS_PER_SEC > 3) {
        for (int i = 0; i < Enemies.size(); i++) {
            if (Enemies[i]) {
                Event* ev = new EnemyAttack();
                ev->execute(Fld, nullptr, Enemies[i]);
                delete ev;
            }
        }
        InOut.Print(Fld, Plr);
        InOut.PrintLogsToConsole();
        InOut.PrintLogsToFile();
        start = end;
    }
}
