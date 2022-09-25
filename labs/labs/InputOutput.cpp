#include "InputOutput.h"
#include <iostream>
#include <string>
InputOutput::InputOutput(int m, int n) : m(m), n(n)
{

}

InputOutput::~InputOutput()
{
}

void InputOutput::Asking()
{
    std::string input;
    do
    {
        std::cout << "Enter the size of the field x = ";
        std::getline(std::cin, input, '\n');
        std::cout << '\n';
    } while (!CheckingForCorrectness(input, m));

    do
    {
        std::cout << "Enter the size of the field y = ";
        std::getline(std::cin, input, '\n');
        std::cout << '\n';
    } while (!CheckingForCorrectness(input, n));
}

bool InputOutput::CheckingForCorrectness(std::string input, int& x)
{

    int check = 0;
    if (input.length() == 0)
    {
        return true;
    }
    for (int i = 0; i < input.length(); i++)
    {
        if (((int)input[i] > 47 && (int)input[i] < 58) || input[i] == ' ')
        {
            check++;
        }
    }
    if (check == input.length())
    {
        x = std::stoi(input);
        return true;
    }
    else
    {
        std::cout << "Error! Invalid value\n";
        return false;
    }
}

void InputOutput::Print(Field Fld)
{
    matrix = Fld.GetField();
    for (int i = 0; i <= Fld.GetM() + 1; i++)
    {
        for (int j = 0; j <= Fld.GetN() + 1; j++)
        {
            std::cout << (char)matrix[i][j].GetC();
        }
        std::cout << '\n';
    }
}

int InputOutput::GetM()
{
    return this->m;
}

int InputOutput::GetN()
{
    return this->n;
}

