#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include "Field.h"
#include "Enemy.h"
class InputOutput
{
public:
    InputOutput(int m = 20, int n = 40);
    ~InputOutput();
    void Asking();
    bool CheckingForCorrectness(std::string, int&);
    void Print(Field*, Player*);
    void info();
    bool CheckEnemies(std::vector<Enemy*>);
    int GetM();
    int GetN();
private:
    int m;
    int n;
    std::vector<std::vector<Cell>> matrix;
    std::vector<Enemy*> Enemies;
};

