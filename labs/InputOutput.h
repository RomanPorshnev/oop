#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include "Field.h"
class InputOutput
{
public:
    InputOutput(int m = 20, int n = 40);
    ~InputOutput();
    void Asking();
    bool CheckingForCorrectness(std::string, int&);
    void Print(Field*);
    int GetM();
    int GetN();
private:
    int m;
    int n;
    std::vector<std::vector<Cell>> matrix;
};

