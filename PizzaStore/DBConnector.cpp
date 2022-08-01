#include "cppconn/resultset.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "Logger.h"
#include "LoginController.h"
#include "CustomerHandler.h"
#include "IngredientStore.h"
#include "DBConnector.h"
#include <iostream>

using namespace std;

DBConnector* DBConnector::instance = nullptr;

DBConnector::DBConnector()
{
    driver = nullptr;
    con = nullptr;
}

DBConnector::~DBConnector()
{
    if (con)
    {
        delete con;
        con = nullptr;
    }
}

bool DBConnector::connectDB()
{
    try
    {
        driver = get_driver_instance();

        /*sql::ConnectOptionsMap optionMap;
        optionMap["hostName"] = "127.0.0.1:12345";
        optionMap["userName"] = "TaeYun";
        optionMap["password"] = "aaa5591ahn";
        optionMap["schema"] = "pizzaorder";
        optionMap["OPT_RECONNECT"] = true;
        optionMap["OPT_CONNECT_TIMEOUT"] = 30;

        con = driver->connect(optionMap);*/
        con = driver->connect(sql::SQLString("localhost:12345"), sql::SQLString("TaeYun"), sql::SQLString("aaa5591ahn"));
        con->setSchema("pizzaorder");

        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "connected to db successfully");
        return true;
    }
    catch (exception e)
    {
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());
        std::cout << e.what() << std::endl;
        return false;
    }
}


bool DBConnector::getAllAccountInfo(std::vector<AccInfo>& GenAcc)
{
    GenAcc.clear();
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT * FROM accounts");

        res = stmt->executeQuery(buf);
        while (res->next()) 
        {
            const auto account = res->getString("account");
            const auto pw = res->getString("pw");
            const auto type = res->getInt("type");

            cout << "[DBConnector] account = " << account << " pw = " << pw << " type = " << type << endl;

            AccInfo accInfo(account.asStdString(), pw.asStdString(), (EN_LOGIN_TYPE)type);
            GenAcc.push_back(accInfo);
        }

        res->close();
        stmt->close();

        delete res;
        delete stmt;

        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Get All Account Info(account, pw, type) DB successfully => %s", buf);


        return !GenAcc.empty();
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }
        if (res)
        {
            res->close();
            delete res;
        }
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }
}

bool DBConnector::getAccountBalance(string customerID, int *customerBalance)
{
    //accountsBalanceData.clear();
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT * FROM accounts where account = '%s'", customerID.c_str());

        res = stmt->executeQuery(buf);
        while (res->next())
        {
            *customerBalance = res->getInt("balance");

            cout << "[DBConnector] account = " << customerID << " balance = " << customerBalance << endl;

            //CustomerInfo CustomerBalanceInfo(ID.c_str(), balance);
            //accountsBalanceData.push_back(CustomerBalanceInfo);
        }

        res->close();
        stmt->close();

        delete res;
        delete stmt;

        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Get All Account Balance DB successfully => %s", buf);


        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }
        if (res)
        {
            res->close();
            delete res;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }
}


bool DBConnector::insertAccountInfo(const AccInfo& acc)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "INSERT INTO accounts (account, pw, type, balance) VALUES ('%s', '%s', %d, %d)", 
                acc.accID.c_str(), acc.accPW.c_str(), acc.loginType, 0);

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Insert Account Info successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Insert Account Info Failed exception = %s", e.what());

        return false;
    }
}

// CRUD

bool DBConnector::getAllIngredients(std::map<std::string, IngredientInfo>& ingredientMap)
{
    ingredientMap.clear();
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT * FROM ingredientstore");

        res = stmt->executeQuery(buf);
        while (res->next())
        {
            const auto name = res->getString("name");
            const auto price = res->getInt("price");
            const auto stock = res->getInt("stock");

            cout << "[DBConnector] name = " << name.c_str() << " price = " << price << " stock = " << stock << endl;

            IngredientInfo ingredientInfo(Ingredient(name, price), stock);
            ingredientMap[name] = ingredientInfo;
        }

        res->close();
        stmt->close();

        delete res;
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Get All Ingredients DB successfully => %s", buf);

        return !ingredientMap.empty();
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Get All Ingredients DB Failed exception = %s", e.what());

        return false;
    }
}

bool DBConnector::insertIngredient(IngredientInfo &ingredientinfo)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "INSERT INTO ingredientstore (name, price, stock) VALUES ('%s', %d, %d)",
            ingredientinfo.ingredient.name.c_str(), ingredientinfo.ingredient.price, ingredientinfo.stock);

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Insert Ingredients successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Insert Ingredients Failed exception = %s", e.what());

        return false;
    }

    return false;
}

bool DBConnector::updateIngredientStock(std::string name, int stock)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "UPDATE `ingredientstore` SET stock='%d' WHERE name='%s';", stock, name.c_str());

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Update Ingredients Stock successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Update Ingredients Stock Failed exception = %s", e.what());

        return false;
    }

    return false;
}


bool DBConnector::updateIngredientPrice(string name, int price)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "UPDATE `ingredientstore` SET price='%d' WHERE name='%s';", price, name.c_str());

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Update Ingredients Price successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {

        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Update Ingredients Price Failed exception = %s", e.what());

        return false;
    }

    return false;
}
bool DBConnector::updateIngredientName(IngredientInfo& ingredientinfo, std::string name)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "UPDATE `ingredientstore` SET name='%s' WHERE name='%s';", name.c_str(), ingredientinfo.ingredient.name.c_str());

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Update Ingredients Name successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        stmt->close();

        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Update Ingredients Name Failed exception = %s", e.what());

        return false;
    }

    return false;
}

bool DBConnector::deleteIngredient(IngredientInfo& ingredientinfo)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "DELETE FROM ingredientstore where name = '%s'", ingredientinfo.ingredient.name.c_str());

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Delete Ingredients successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        stmt->close();

        if (stmt)
            delete stmt;

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Delete Ingredients Failed exception = %s", e.what());

        return false;
    }

    return false;
}

bool DBConnector::getAllOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList)
{
    orderList.clear();
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT aol.*, a.`account` as account_name FROM account_order_list as aol left join accounts as a on aol.account_id = a.id;");

        res = stmt->executeQuery(buf);
        while (res->next())
        {
            const auto accountName = res->getString("account_name");
            const auto pizzaType = res->getInt("pizza_type");
            const auto count = res->getInt("count");

            cout << "[DBConnector] account_name = " << accountName.c_str() << " pizza_type = " << pizzaType << " count = " << count << endl;

            AccountwithPizza accountwithPizza((enPizzaMenu)pizzaType, count);
            orderList[accountName].push_back(accountwithPizza);
        }

        res->close();
        stmt->close();

        delete res;
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Get All Order List DB successfully => %s", buf);

        return !orderList.empty();
    }
    catch (exception e)
    {
        res->close();
        stmt->close();

        if (res)
            delete res;

        if (stmt)
            delete stmt;

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Get All Order List DB Failed exception = %s", e.what());

        return false;
    }
}

bool DBConnector::updateOrderList(string name, int pizzaType, int count)
{
    sql::PreparedStatement* stmt = nullptr;
    

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "UPDATE account_order_list SET count = %d where account_name = '%s' and pizza_type = %d", count, name.c_str(), pizzaType);

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Update account_order_list balance successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }

    return false;
}

bool DBConnector::insertOrderList(string name, int pizzaType, int c)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };

        // 1. select -> id of name, pizza type unique
        // 2. if unique -> insert
        // 3. if not -> update

        // sub query
        // upsert
        sprintf_s(sql, 256, "INSERT INTO account_order_list(account_id, pizza_type, count) value ((SELECT id from accounts where account = '%s'), %d, %d)"
                            " ON DUPLICATE KEY UPDATE count = count + %d;",
            name.c_str(), pizzaType, c, c);

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Insert account_order_list Info successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }
}


bool DBConnector::updateAccountBalance(const string& accountID, int bal)
{
    sql::PreparedStatement* stmt = nullptr;

    try
    {
        char sql[256] = { 0, };
        sprintf_s(sql, 256, "UPDATE accounts SET balance = %d where account = '%s'", bal, accountID.c_str());

        stmt = con->prepareStatement(sql);
        stmt->executeUpdate();

        stmt->close();
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Update accounts balance successfully => %s", sql);

        return true;
    }
    catch (exception e)
    {
        if (stmt)
        {
            stmt->close();
            delete stmt;
        }

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }

    return false;
}

bool DBConnector::getAllPizzaList(std::map<std::string, int>pizzaDef)
{
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT * FROM pizza");

        res = stmt->executeQuery(buf);
        while (res->next())
        {
            const auto pizzaName = res->getString("name");
            const auto pizzaPrice = res->getInt("price");
            pizzaDef[pizzaName] = pizzaPrice;
            
        }

        res->close();
        stmt->close();

        delete res;
        delete stmt;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Get All Pizza Def List successfully = > % s", buf);

        return !pizzaDef.empty();
    }
    catch (exception e)
    {
        res->close();
        stmt->close();

        if (res)
            delete res;

        if (stmt)
            delete stmt;

        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());

        return false;
    }
}
