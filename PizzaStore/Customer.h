#pragma once
class PizzaStore;
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    void runCustomer(const std::string& customer);
	void doOrder();
private:
    PizzaStore* PiStore;
    
};

