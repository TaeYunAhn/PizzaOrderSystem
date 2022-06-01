#pragma once
#include "PizzaDef.h"
#include "Customer.h"
#include <string>
#include <map>
#include <vector>


struct CustomerInfo
{
    CustomerInfo() {}
    CustomerInfo(std::string _ID, int _Balance) : ID(_ID), Balance(_Balance) {}
    std::string ID;
    int Balance;
};

class CustomerHandler
{

public:
    CustomerHandler();
    ~CustomerHandler();

    void HandleCustomer(std::string id, PizzaStore* pizzaStore);

private:
    void checkRecord(const std::string& customerId);
    bool chargePoint(int& balance);

private:
    std::map<std::string, std::array<AccountwithPIzza, PIZZA_TOTAL - 1>> PizzaCountData; // 피자 카운트
    std::vector<CustomerInfo> accountsInfoData; // 커스터머 인포
};
