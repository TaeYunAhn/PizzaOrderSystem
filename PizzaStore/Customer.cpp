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

void Customer::addPizzaCount(string id, enPizzaMenu menu, int count)
{
	AccountwithPIzza AWP(menu, count);
	array<AccountwithPIzza, PIZZA_TOTAL - 1> a = { AWP };
	AWP.Count++;
	pizzaCount[id] = a;
}

bool Customer::goBack()
{
	while (true)
	{
		string answer;

		cout << "이전 메뉴로 돌아가시려면 아무 키나 입력해 주세요" << endl;
		cin >> answer;
		return true;
	}
}

void Customer::doOrder(string userId, int *balance)
{
	CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Order START, id : %s, balance : %d", userId, balance); 

	system("cls");
	int sel;
	cout << "  <<메뉴 선택>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "피자 선택 : ";
	cin >> sel;
	/*const enPizzaMenu pizzaNum = getPizzaNum(name);
	if (pizzaNum == PIZZA_TOTAL)
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}*/

	if (PiStore->ProcessOrder((enPizzaMenu)sel) == false)
	{
		cout << "재료 부족으로 주문할 수 없습니다." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough balance : %d", balance); 
		Sleep(500);
	}
	*balance -= getprice(sel);
	CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "balance : %d",balance); 



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
