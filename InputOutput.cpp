#include "InputOutput.h"
#include <iostream>
#include <string>
#include <Windows.h>
InputOutput::InputOutput(int m, int n) : m(m), n(n)
{
    singleton = singleton->GetInstance();
}

InputOutput::~InputOutput()
{
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string> list_logs)
{
    for (int i = 0; i < list_logs.size(); i++)
        os << list_logs[i];
    return os;
}

std::ofstream& operator<<(std::ofstream& os, const std::vector<std::string> list_logs)
{
    for (int i = 0; i < list_logs.size(); i++)
        os << list_logs[i];
    return os;
}
void InputOutput::Asking()
{
    std::cout << "Do you want to log in a file logs.txt? [y/n]\n";
    std::cin >> c;
    if (c == 'n')
        singleton->SetFileLog(false);
    std::cout << "Do you want to log in a console? [y/n]\n";
    std::cin >> c;
    if (c == 'n')
        singleton->SetConsoleLog(false);
    std::cout << "Do you want to log in changes of field, player and events? [y/n]\n";
    std::cin >> c;
    if (c == 'n')
        singleton->SetLevel1(false);
    std::cout << "Do you want to log game state? [y/n]\n";
    std::cin >> c;
    if (c == 'n')
        singleton->SetLevel2(false);
    std::cout << "Do you want to log critical states? [y/n]\n";
    std::cin >> c;
    if (c == 'n') {
        singleton->SetLevel3(false);
    }
    c = getchar();
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
    system("cls");
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
        singleton->logging(15);
        PrintLogsToConsole();
        PrintLogsToFile();
        return false;
    }
}

void InputOutput::Print(Field *Fld, Player *Plr)
{
    system("cls");
    matrix = Fld->GetField();
    for (int i = 0; i <= Fld->GetM() + 1; i++)
    {
        for (int j = 0; j <= Fld->GetN() + 1; j++)
        {
            std::cout << (char)matrix[i][j].GetC();
        }
        std::cout << '\n';
    }
    std::cout << "Health: "<<Plr->GetHP()<<'\n';
    std::cout << "Ammo: " << Plr->GetAmmo()<<'\n';
    std::cout << "Score: " << Plr->GetScore()<<'\n';
}

void InputOutput::info()
{
    std::cout << "Press [w] to move up\n";
    std::cout << "Press [a] to move left\n";
    std::cout << "Press [d] to move right\n";
    std::cout << "Press [s] to move down\n";
    std::cout << "\nPlayer sign [+]\n";
    std::cout << "Wall sign [#]\n";
    std::cout << "Pill sign [%]\n";
    std::cout << "Enemy sign [0]\n";
    std::cout << "Bomb sign [*]\n";
    std::cout << "Ammo sign [=]\n";
    std::cout << "\nOFF/ON signs of levels of logging:\n";
    std::cout << "[1]: Changes in the state of the player and the field, as well as triggering events\n";
    std::cout << "[2]: State of game\n";
    std::cout << "[3]: Critical states and errors\n";
    std::cout << "\nPlace where logs are recorded:\n";
    std::cout << "[F]: Record to a file\n";
    std::cout << "[C]: Record to a console\n\n";
}

int InputOutput::GetM()
{
    return this->m;
}

int InputOutput::GetN()
{
    return this->n;
}

void InputOutput::PrintLogsToConsole()
{
    if (singleton->GetConsoleLog()) {
        list_logs = singleton->GetListLogsConsole();
        std::cout << list_logs;
    }
}

void InputOutput::PrintLogsToFile()
{   
    if (singleton->GetFileLog()) {
        list_logs = singleton->GetListLogsFile();
        std::ofstream fout("logs.txt");
        fout << list_logs;
        fout.close();
    }
}


