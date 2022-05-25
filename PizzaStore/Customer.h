#pragma once
#include <map>
#include <string>
#include <array>
#include "PizzaDef.h"


struct AccountwithPIzza
{
    AccountwithPIzza() {}
    AccountwithPIzza(enPizzaMenu p, int count ) : type(p), Count(count){}
    ~AccountwithPIzza() {}
    enPizzaMenu type;
    int Count;
};

//AccountwithPIzza arr[10];
//array<AccountwithPIzza, 10> a;

//template<typename T>
//class A
//{
//public:
//    A(T num) { a = num; }
//    T power()
//    {
//        return a * a;
//    }
//
//    T a;
//};






class PizzaStore;
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    void runCustomer(const std::string& customer/*, int balance*/);
	void doOrder(std::string id);
    bool goBack();
    void addPizzaCount(std::string id, enPizzaMenu menu, int count);


private:
    PizzaStore* PiStore;
    std::map<std::string, std::array<AccountwithPIzza, PIZZA_TOTAL-1>> pizzaCount;  
};

