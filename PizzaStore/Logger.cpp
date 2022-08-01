#include "stdio.h"
#include <windows.h>
#include "Logger.h"

#pragma warning(disable:4996)

using namespace std;
CLogger* CLogger::instance = nullptr;

const string LOG_LEVEL_DEBUG = "debug";
const string LOG_LEVEL_INFO = "info";
const string LOG_LEVEL_WARNING = "warning";
const string LOG_LEVEL_ERROR = "error";
const string LOG_LEVEL_NO = "no";

CLogger::CLogger()
{
	logLevel = enInfo;
}

CLogger::~CLogger()
{
	if (logFile.is_open())
	{
		logFile.flush();
		logFile.close();
	}
}

void CLogger::write(const EN_LOGLEVEL& level, const int& line, const char* func, const char* msg, ...)
{
	if (msg == NULL)
		return;

	if (level < logLevel)
		return;

	// MESSSAGE
	char strBuf[SHRT_MAX];
	memset(strBuf, 0, sizeof(strBuf));

	va_list arg_ptr;
	va_start(arg_ptr, msg);
	int len = _vscprintf(msg, arg_ptr);
	if (len < 10000)
		vsprintf_s(strBuf, len + 1, msg, arg_ptr);

	va_end(arg_ptr);

	// LOG LEVEL STRING
	string logLevelHeader = "";
	switch (logLevel)
	{
	case enInfo:
		logLevelHeader = "[INFO]"; break;
	case enDebug:
		logLevelHeader = "[DEBUG]"; break;
	case enWarning:
		logLevelHeader = "[WARNING]"; break;
	case enError:
		logLevelHeader = "[ERROR]"; break;
	default:
		logLevelHeader = "[UnKnown]";
	}

	// DATE SETTING
	char currentDate[12];
	memset(currentDate, 0, sizeof(currentDate));

	SYSTEMTIME st;
	GetLocalTime(&st);
	sprintf_s(currentDate, "%04d%02d%02d", st.wYear, st.wMonth, st.wDay);

	char strOutBuf[SHRT_MAX];
	sprintf_s(strOutBuf, "%s\t%04d.%02d.%02d %02d:%02d:%02d.%03d  %s()[%d] %s",
		logLevelHeader.c_str(), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, func, line, strBuf);


	// FILE WRITE
	if (fileDate != currentDate)
	{
		fileDate = currentDate;

		char tmp[1024];
		memset(tmp, 0, sizeof(tmp));

		if (logFile.is_open())
			logFile.close();

		const string path = LOG_PATH + "\\PizzaStore.%04d%02d%02d.log";
		_snprintf_s(tmp, sizeof(tmp) - 1, path.c_str(), st.wYear, st.wMonth, st.wDay);

		logFile.open(tmp, std::ofstream::out | std::ofstream::app);
	}

	if (logFile.is_open())
	{
		logFile << strOutBuf << endl;
		logFile.flush();
	}

}

void CLogger::setLogLevel(const string& str)
{
	if (str.empty())
		return;

	if (str == LOG_LEVEL_ERROR)
		logLevel = enError;
	else if (str == LOG_LEVEL_WARNING)
		logLevel = enWarning;
	else if (str == LOG_LEVEL_DEBUG)
		logLevel = enDebug;
	else
		logLevel = enInfo;
}


// [DEBUG] 2022-03-20 22:54:31	"Client1이 주문 했습니다.(주문 내용: 고르곤졸라1, 마르게리따1)"