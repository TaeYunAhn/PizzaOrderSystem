#include "FileSave.h"
#include <fstream>
#include <iostream>
using namespace std;

bool FileSave::readIngredient(std::map<Ingredient, int>& ingredientStockMap)
{
    ingredientStockMap.clear();
    FILE* fd = fopen("IngredientStore.csv", "r");

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
    FILE* fd = fopen("IngredientStore.csv", "w");

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

bool FileSave::readLoginData(std::vector<Acc>& GenAcc)
{
    GenAcc.clear();
    FILE* fd = fopen("LoginController.csv", "r");

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

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else acc.type = (EN_LOGIN_TYPE)atoi(ptr);

        if (!acc.ID.empty() && !acc.PW.empty())
            GenAcc.push_back(acc);
    }
    fclose(fd);
    return true;
}

bool FileSave::saveLoginData(const std::vector<Acc>& GenAcc)
{
    FILE* fd = fopen("LoginController.csv", "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    

    for (Acc m : GenAcc)
    {
        string typeName;
        if (m.type == CUSTOMER)
            typeName = "CUSTOMER";

        sprintf(num1, "%s,%s,%s\n", m.ID.c_str(), m.PW.c_str(), typeName.c_str());
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}


bool FileSave::readAccountInfo(vector<Info>& accountsInfo)
{
    accountsInfo.clear();
    FILE* fd = fopen("accountsInfo.csv", "r");

    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        Info info;
        char* ptr = strtok(pLine, ",");
        info.ID = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else info.Balance = atoi(ptr);

        
        if (!info.ID.empty() && !info.Balance)
            accountsInfo.push_back(info);
    }
    fclose(fd);
    return true;
}

bool FileSave::saveAccountInfo(const vector<Info>& accountsInfo)
{
    FILE* fd = fopen("accountsInfo.csv", "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (Info i : accountsInfo )
    {   
        sprintf(num1, "%s,%d\n", i.ID.c_str(), i.Balance);
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}


bool FileSave::readOrderList(std::map<enPizzaMenu, int>& pizzaCount)
{
    pizzaCount.clear();
    FILE* fd = fopen("pizzaCount.csv", "r");

    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        enPizzaMenu pizzamenu;
        char* ptr = strtok(pLine, ",");
        pizzamenu = (enPizzaMenu)atoi(ptr);

        int count = 0;
        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else count = atoi(ptr);


        if (!pizzamenu && !count)
            pizzaCount[pizzamenu] = count;
    }
    fclose(fd);
    return true;
}
bool FileSave::saveOrderList(const std::map<enPizzaMenu, int>& pizzaCount)
{
    FILE* fd = fopen("pizzaCount.csv", "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    // map 안의 enum 순회가 안됩니다 ㅠㅠ
    // enum to int 를 해야할거 같은데 switch 말고 더 깔끔한 방법 없을까요? 
    //for (map<enPizzaMenu, int>::iterator itr = pizzaCount.begin(); itr != pizzaCount.end(); itr++)
    //{
    //    sprintf(num1, "%s,%d\n", getPizzaName(itr->first).c_str(), itr->second);
    //    fputs(num1, fd);
    //}

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





