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
	bool readOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList);
	bool saveOrderList(const std::map<std::string, std::vector<AccountwithPizza>>& orderList);
	bool readIngredient(std::map<std::string, IngredientInfo>& ingredientMap);
	bool saveIngredient(const std::map<std::string, IngredientInfo>& ingredientMap);


private:
	DBConnector();
	~DBConnector();

private:
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	static DBConnector* instance;
};

