#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include "Field.h"
#include "Enemy.h"
#include <fstream>
#include "Singleton.h"
class InputOutput
{
public:
    InputOutput(int m = 20, int n = 40);
    ~InputOutput();
    void Asking();
    bool CheckingForCorrectness(std::string, int&);
    void Print(Field*, Player*);
    void info();
    int GetM();
    int GetN();
    void PrintLogsToConsole();
    void PrintLogsToFile();
private:
    char c;
    std::vector<std::string> list_logs;
    int m;
    int n;
    std::vector<std::vector<Cell>> matrix;
    std::vector<Enemy*> Enemies;
    Singleton* singleton;
};

