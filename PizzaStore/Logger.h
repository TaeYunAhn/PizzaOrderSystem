#pragma once
enum EN_LOGLEVEL
{
	enDebug,
	enInfo,
	enWarning,
	enError,
};

class CLogger
{
public:
	static CLogger* getInstance()
	{
		if ( !instance )
			instance = new CLogger();

		return instance;
	}

	void write(const EN_LOGLEVEL& level, char* args, ...);

private:
	CLogger() {}
	static CLogger* instance;

};



