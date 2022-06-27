#include "FileSave.h"
#include <fstream>
#include <iostream>
#include "CustomerHandler.h"
#include "Logger.h"
using namespace std;

bool FileSave::readIngredient(std::map<Ingredient, int>& ingredientStockMap)
{
    ingredientStockMap.clear();
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\IngredientStore.csv").c_str(), "r");

    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        Ingredient ingre;
        int stock = 0;

        char* ptr = strtok(pLine, ",");
        ingre.name = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else ingre.price = atoi(ptr);

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else stock = atoi(ptr);

        ingredientStockMap[ingre] = stock;

    }
    fclose(fd);
    return true;
}

bool FileSave::saveIngredient(const std::map<Ingredient, int>& ingredientStockMap)
{
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\IngredientStore.csv").c_str(), "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (pair<Ingredient, int> m : ingredientStockMap)
    {
        sprintf(num1, "%s,%d,%d\n", m.first.name.c_str(), m.first.price, m.second);
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}

bool FileSave::readLoginData(std::vector<AccInfo>& GenAcc)
{
    GenAcc.clear();
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\LoginController.csv").c_str(), "r");
	
    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        AccInfo info;
        char* ptr = strtok(pLine, ",");
        info.accID = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else info.accPW = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        info.loginType = (EN_LOGIN_TYPE)atoi(ptr);

        if (!info.accID.empty() && !info.accPW.empty())
            GenAcc.push_back(info);
    }

    fclose(fd);
    return true;
}

bool FileSave::saveLoginData(const std::vector<AccInfo>& GenAcc)
{
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\LoginController.csv").c_str(), "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (const auto& a : GenAcc)
    {
        sprintf(num1, "%s,%s,%d\n", a.accID.c_str(), a.accPW.c_str(), (int)a.loginType);
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}


bool FileSave::readAccountInfo(vector<CustomerInfo>& accountsInfoData)
{
    accountsInfoData.clear();
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\accountsInfo.csv").c_str(), "r");
	
    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        CustomerInfo info;
        char* ptr = strtok(pLine, ",");
        info.ID = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else info.Balance = atoi(ptr);

        
        if (!info.ID.empty() && info.Balance > 0)
            accountsInfoData.push_back(info);
    }
    fclose(fd);
    return true;
}

bool FileSave::saveAccountInfo(const vector<CustomerInfo>& accountsInfoData)
{
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\accountsInfo.csv").c_str(), "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (CustomerInfo i : accountsInfoData)
    {   
        sprintf(num1, "%s,%d\n", i.ID.c_str(), i.Balance);
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}


bool FileSave::readOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList)
{
	orderList.clear();
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\pizzaCount.csv").c_str(), "r");
	
    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        
        char* ptr = strtok(pLine, ",");
		const string customerId = ptr;
        
        ptr = strtok(NULL, ",");
        if (!ptr) 
			continue;
        
		const enPizzaMenu type = (enPizzaMenu)atoi(ptr);

		ptr = strtok(NULL, ",");
		if (!ptr)
			continue;

		const int count = atoi(ptr);

		if (customerId.empty() || type >= PIZZA_TOTAL || type <= PIZZA_START)
		{
			CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "wrong data(id = %s, type = %d)", customerId.c_str(), type);
			continue;
		}
		

		AccountwithPizza accountPizza(type, count);
		if ( orderList.count(customerId) > 0 )
			orderList[customerId].push_back(accountPizza);
		else
		{
			vector<AccountwithPizza> vData;
			vData.push_back(accountPizza);
			orderList[customerId] = vData;
		}

    }
    fclose(fd);
    return true;
}

bool FileSave::saveOrderList(const std::map<std::string, std::vector<AccountwithPizza>>& orderList)
{
    FILE* fd = fopen(string(DATA_SOURCE_PATH + "\\pizzaCount.csv").c_str(), "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

	for (const auto& orderPair : orderList)
	{
		for (const auto& accPizza : orderPair.second)
			sprintf(num1, "%s,%d,%d\n", orderPair.first.c_str(), accPizza.type, accPizza.count);
	}
		
    fclose(fd); 
    return true;
}

/*bool FileSave::readManagerLoginData(std::vector<Acc>& ManagerAcc)
{
    ManagerAcc.clear();
    FILE* fd = fopen("ManagerLoginController.csv", "r");

    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        Acc acc;
        char* ptr = strtok(pLine, ",");
        acc.ID = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else acc.PW = ptr;
        if (!acc.ID.empty() && !acc.PW.empty())
            ManagerAcc.push_back(acc);

    }
    fclose(fd);
    return true;
}

bool FileSave::saveManagerLoginData(const std::vector<Acc>& ManagerAcc)
{
    FILE* fd = fopen("ManagerLoginController.csv", "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (Acc m : ManagerAcc)
    {
        sprintf(num1, "%s,%s", m.ID.c_str(), m.PW.c_str());
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}*/





