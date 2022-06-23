#pragma once
#include <string>

const std::string LOG_PATH = "C:\\PSData\\logs";

enum EN_LOGLEVEL
{
	enDebug,
	enInfo,
	enWarning,
	enError,
};

class CLogger
{
//// Singleton
public:
	static CLogger* getInstance()
	{
		if ( !instance )
			instance = new CLogger();

		return instance;
	}

	void write(const EN_LOGLEVEL& level, const int& line, const char* func, const char* msg, ...);

private:
	CLogger();
	~CLogger();
	static CLogger* instance;


//// General
public:
	void setLogLevel(const std::string& str);

private:
	EN_LOGLEVEL logLevel;
	std::string fileDate;
	FILE* fd;

	std::string logPath;

};