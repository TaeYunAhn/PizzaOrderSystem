#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"
#include "Customer.h"
#include "Logger.h"
#include <iostream>
#include <Windows.h>

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

bool Customer::doOrder(string id, int *balance, enPizzaMenu& menu)
{
	system("cls");
	int sel;
	cout << "  <<메뉴 선택>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "피자 선택 : ";
	cin >> sel;

    if ( sel < HAWAIIAN_PIZZA || sel > POTATO_PIZZA )
    {
        cout << "잘못된 입력입니다." << endl;
		Sleep(500);
		return false;
    }

	const auto selMenu = (enPizzaMenu)sel;
	Pizza* pizza = nullptr;
	if (!PiStore->ProcessOrder(selMenu, pizza))
	{
		cout << "재료 부족으로 주문할 수 없습니다." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough balance : %d", balance); 
		Sleep(500);
		return false;
	}

	if (pizza)
	{
		*balance -= pizza->getPrice();
		delete pizza;
	}

	menu = selMenu;

	return true;
}


