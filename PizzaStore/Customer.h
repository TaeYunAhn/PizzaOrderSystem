#pragma once
#include <map>
#include <string>
#include <array>
#include "PizzaDef.h"


struct AccountwithPizza
{
	AccountwithPizza() {}
	AccountwithPizza(enPizzaMenu p, int c) : type(p), count(c){}
    ~AccountwithPizza() {}
    enPizzaMenu type;
    int count;
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

enum EN_CUSTOMER_RESULT // 변수명 짓는게 가장 어려운거 같습니다.. 좋은 이름 있으면 추천해주세욥..
{
    EN_ORDER_SUC,
    EN_NOT_ENOUGH_BALANCE,
    EN_NOT_ENOUGH_INGRE,
    error,
};

class PizzaStore;
class Customer
{
public:

    Customer();
    Customer(PizzaStore* Pizza);
    ~Customer();

    //EN_CUSTOMER_RESULT runCustomer(const std::string& customer, int balance);
	bool doOrder(std::string id, int *balance, enPizzaMenu& menu, int*& count);

private:
    PizzaStore* PiStore;
};

