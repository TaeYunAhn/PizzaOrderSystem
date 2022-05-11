#include <iostream>
#include "PizzaStore.h"
#include "Customer.h"
using namespace std;

Customer::Customer()
{
}

Customer::Customer(PizzaStore* Pizza)
{
    PiStore = Pizza;
}

Customer::~Customer()
{
}

void Customer::runCustomer(const string &customer)
{
    while (true)
    {
		system("cls");
		int res = 0;
        cout << "  << " << customer << "의" << " 메뉴 >> " << endl;
        cout << "1. 주문" << endl;
        cout << "2. 주문 이력 확인" << endl;
        cout << "3. 로그아웃" << endl;
        
        cout << "선택 : ";
        cin >> res;

		switch (res)
		{
		case 1:
			doOrder();
			break;
		case 2:
			// ?
			break;
		case 3:
			return;
		default:
			break;
		}
    }
}

void Customer::doOrder()
{
	system("cls");
	string name;
	cout << "  <<메뉴 선택>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "피자 이름 : ";
	cin >> name;
	const enPizzaMenu pizzaNum = getPizzaNum(name);
	if (pizzaNum == PIZZA_TOTAL)
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	PiStore->ProcessOrder(pizzaNum);
}