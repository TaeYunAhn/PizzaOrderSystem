#pragma once
#include <vector>
#include "mysql_connection.h"
#include "mysql_driver.h"

struct AccInfo;
class DBConnector
{
public:
	static DBConnector* getInstance()
	{
		if (!instance)
			instance = new DBConnector();

		return instance;
	}

	bool connectDB();

	bool readLoginData(std::vector<AccInfo>& GenAcc);
	bool saveLoginData(const std::vector<AccInfo>& GenAcc);

private:
	DBConnector();
	~DBConnector();

private:
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	static DBConnector* instance;
};

