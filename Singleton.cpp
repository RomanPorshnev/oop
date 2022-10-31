#include "Singleton.h"
#include <iostream>
#include <fstream>
Singleton* Singleton::GetInstance()
{
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::logging(int type)
{
    if ((type > 0) && (type < 13) && (GetLevel1()) && (console)) {
        list_logs_console.push_back(msg.GetMessage(type));
    }
    if ((type > 0) && (type < 13) && (GetLevel1()) && (file)) {
        list_logs_file.push_back(msg.GetMessage(type));
    }
    if ((type > 12) && (type < 15) && (GetLevel2()) && (console)) {
        list_logs_console.push_back(msg.GetMessage(type));
    }
    if ((type > 12) && (type < 15) && (GetLevel2()) && (file)) {
        list_logs_file.push_back(msg.GetMessage(type));
    }
    if ((type > 14) && (GetLevel3()) && (console)) {
        list_logs_console.push_back(msg.GetMessage(type));
    }
    if ((type > 14) && (GetLevel3()) && (file)) {
        list_logs_file.push_back(msg.GetMessage(type));
    }
    /*if ((type > 18) && (type < 30) && GetLevel3()) {
        list_logs.push_back(msg.GetMessage(type));
    }*/
    
}

bool Singleton::GetConsoleLog()
{
    if (this->console) {
        return true;
    }
    return false;
}

bool Singleton::GetFileLog()
{
    if (this->file) {
        return true;
    }
    return false;
}

void Singleton::SetConsoleLog(bool new_off_on)
{
    this->console = new_off_on;
}

void Singleton::SetFileLog(bool new_off_on)
{
    this->file = new_off_on;
}

bool Singleton::GetLevel1()
{
    if (this->level1) {
        return true;
    }
    return false;
}

bool Singleton::GetLevel2()
{
    if (this->level2) {
        return true;
    }
    return false;
}

Singleton* Singleton::instance = nullptr;

bool Singleton::GetLevel3()
{
    if (this->level3) {
        return true;
    }
    return false;
}

void Singleton::SetLevel1(bool new_level1)
{
    this->level1 = new_level1;
}

void Singleton::SetLevel2(bool new_level2)
{
    this->level2 = new_level2;
}

void Singleton::SetLevel3(bool new_level3)
{
    this->level3 = new_level3;
}

std::vector<std::string> Singleton::GetListLogsConsole()
{
    return list_logs_console;
}

std::vector<std::string> Singleton::GetListLogsFile()
{
    return list_logs_file;
}

Singleton::Singleton() 
{
    console = true;
    file = true;
    level1 = true;
    level2 = true;
    level3 = true;
}