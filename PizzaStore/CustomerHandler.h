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

    void handleCustomer(std::string id, PizzaStore* pizzaStore);

private:
    void checkRecord(const std::string& customerId);
    bool chargePoint(int& balance);
	void addPizzaCount(const std::string& customerId, const enPizzaMenu menu);

private:
    std::map<std::string, std::vector<AccountwithPizza>> PizzaCountData; // 피자 카운트
    std::vector<CustomerInfo> accountsInfoData; // 커스터머 인포
};
