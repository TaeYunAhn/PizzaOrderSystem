#pragma once
#include <vector>
#include "mysql_connection.h"
#include "mysql_driver.h"

struct AccInfo;
struct IngredientInfo;
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

	bool getAllAccountInfo(std::vector<AccInfo>& GenAcc);
	bool InsertAccountInfo(const AccInfo& acc);
	bool readOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList);
	bool saveOrderList(const std::map<std::string, std::vector<AccountwithPizza>>& orderList);
	bool getAllIngredients(std::map<std::string, IngredientInfo>& ingredientMap);
	bool insertIngredient(IngredientInfo& ingredientinfo);


private:
	DBConnector();
	~DBConnector();

private:
	sql::Driver* driver;
	sql::Connection* con;

	static DBConnector* instance;
};

