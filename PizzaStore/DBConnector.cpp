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

        return !GenAcc.empty();
    }
    catch (exception e)
    {
        res->close();
        stmt->close();

        if ( res)
            delete res;

        if ( stmt)
            delete stmt;

        return false;
    }
}

bool DBConnector::InsertAccountInfo(const AccInfo& acc)
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

        //TODO success logging
        return true;
    }
    catch (exception e)
    {
        stmt->close();

        if (stmt)
            delete stmt;

        //TODO fail logging
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

        return !ingredientMap.empty();
    }
    catch (exception e)
    {
        res->close();
        stmt->close();

        if (res)
            delete res;

        if (stmt)
            delete stmt;

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

        //TODO success logging
        return true;
    }
    catch (exception e)
    {
        stmt->close();

        if (stmt)
            delete stmt;

        //TODO fail logging
        return false;
    }

    return false;
}

bool DBConnector::readOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList)
{
    return false;
}

bool DBConnector::saveOrderList(const std::map<std::string, std::vector<AccountwithPizza>>& orderList)
{
    return false;
}
