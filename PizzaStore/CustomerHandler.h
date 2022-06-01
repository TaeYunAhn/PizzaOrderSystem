#pragma once
#include "PizzaDef.h"
#include "Customer.h"
#include <string>
#include <map>
#include <vector>


struct Info
{
    Info() {}
    Info(std::string _ID, int _Balance) : ID(_ID), Balance(_Balance) {}
    std::string ID;
    int Balance;
};

class CustomerHandler
{

public:
    CustomerHandler();
    ~CustomerHandler();

    void run(std::string id);

private:
    
    std::map<std::string, std::array<AccountwithPIzza, PIZZA_TOTAL - 1>> PizzaCountData; // ���� ī��Ʈ
    std::vector<Info> accountsInfoData; // Ŀ���͸� ����
};
