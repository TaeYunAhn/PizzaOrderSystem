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

	// accounts
	bool getAllAccountInfo(std::vector<AccInfo>& GenAcc);
	bool insertAccountInfo(const AccInfo& acc);
	bool getAccountBalance(std::string customerID, int *balance);
	bool updateAccountBalance(const std::string& accountID, int bal);

	// ingredientstore
	bool getAllIngredients(std::map<std::string, IngredientInfo>& ingredientMap);
	bool insertIngredient(IngredientInfo& ingredientinfo);
	bool updateIngredientStock(std::string name, int stock);
	bool updateIngredientPrice(std::string name, int price);
	bool updateIngredientName(IngredientInfo& ingredientinfo, std::string name);
	bool deleteIngredient(IngredientInfo& ingredientinfo);

	// orderlist
	bool getAllOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList);
	bool updateOrderList(std::string name, int pizzaType, int count);
	bool insertOrderList(std::string name, int pizzaType, int count);

	// pizza
	bool getAllPizzaList(std::map<std::string, int>pizzaDef);


private:
	DBConnector();
	~DBConnector();

private:
	sql::Driver* driver;
	sql::Connection* con;

	static DBConnector* instance;
};

