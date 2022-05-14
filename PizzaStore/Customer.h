#pragma once
#include <map>
#include <string>

class PizzaStore;
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    void runCustomer(const std::string& customer);
	void doOrder();
    bool goBack();
    std::string getPizzaName(enPizzaMenu res);
private:
    PizzaStore* PiStore;
    std::map<enPizzaMenu, int> pizzaCount;
    
};

