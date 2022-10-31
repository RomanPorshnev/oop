#pragma once
#include "Message.h"
class Singleton_FileLogger
{
public:
	Singleton_FileLogger(const Singleton_FileLogger& other) = delete;
	void operator = (const Singleton_FileLogger) = delete;
	static Singleton_FileLogger* GetInstance();
	void logging(int type);
protected:
	Singleton_FileLogger() {
	}
	static Singleton_FileLogger* instance;
private:
	Message msg;
	std::vector<std::string> list_logs;
};

