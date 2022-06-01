#include <iostream>
#include "PizzaStore.h"
#include "Customer.h"
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

void Customer::addPizzaCount(string id, enPizzaMenu menu, int count)
{
	AccountwithPIzza AWP(menu, count);
	array<AccountwithPIzza, PIZZA_TOTAL - 1> a = { AWP };
	AWP.Count++;
	pizzaCount[id] = a;
}

void Customer::doOrder(string id, int *balance)
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
        return;
    }

	if (PiStore->ProcessOrder((enPizzaMenu)sel) == false)
	{
		cout << "재료 부족으로 주문할 수 없습니다." << endl << endl;
		Sleep(500);
	}
	*balance -= getprice(sel);
	// To Fix
	// balance 없을때 cout 띄우기?
	// processorder 의 return 을 enum 으로 바꿔야 할듯 
	// 일단 handler 부터 만들고 시작?

	
	//int count = 0;
	//AccountwithPIzza AWP((enPizzaMenu)sel, count);
	//count = AWP.Count;
	//addPizzaCount(id, (enPizzaMenu)sel, count);
	
	//AccountwithPIzza AWP;
	//AWP.type = (enPizzaMenu)(sel + 1);
	//++AWP.Count;

}

int Customer::getprice(int sel)
{
	switch (sel)
	{
	case 1: return 15000;
	case 2: return 22000;
	case 3: return 16000;
	case 4: return 18000;
	case 5: return 20000;
	default:
		break;
	}
}
