#include "cppconn/resultset.h"
#include "cppconn/statement.h"

#include "Logger.h"
#include "LoginController.h"
#include "DBConnector.h"

using namespace std;

DBConnector* DBConnector::instance = nullptr;

DBConnector::DBConnector()
{
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
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost:12345", "TaeYun", "aaa5591ahn");

        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "connected to mysql successfully");
        return true;
    }
    catch (exception e)
    {
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "exception = %s", e.what());
        return false;
    }
}


bool DBConnector::readLoginData(std::vector<AccInfo>& GenAcc)
{
    GenAcc.clear();
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr;

    try
    {
        stmt = con->createStatement();

        char buf[256] = { 0, };
        sprintf_s(buf, 256, "SELECT * FROM pizzaorder.accounts");

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

bool DBConnector::saveLoginData(const std::vector<AccInfo>& GenAcc)
{
    return false;
}
