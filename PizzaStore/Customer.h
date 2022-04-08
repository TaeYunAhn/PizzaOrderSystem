#pragma once
#include "PizzaStore.h"
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    PizzaStore *PiStore;

private:
    bool MainUI();

    
};

