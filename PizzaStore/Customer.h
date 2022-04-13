#pragma once
#include "PizzaStore.h"
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    
    bool RunCustomer(std::string& __id);

private:
    PizzaStore* PiStore;
    
};

