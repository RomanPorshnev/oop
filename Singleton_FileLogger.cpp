#include "Singleton_FileLogger.h"

Singleton_FileLogger* Singleton_FileLogger::GetInstance()
{
    if (instance == nullptr) {
        instance = new Singleton_FileLogger();
    }
    return instance;
}

Singleton_FileLogger* Singleton_FileLogger::instance = nullptr;
void Singleton_FileLogger::logging(int type)
{
    list_logs.push_back(msg.GetMessage(type));

}
