#include "Pizza.h"
#include "PizzaStore.h"
#include "Customer.h"
#include "Logger.h"
#include <iostream>
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

bool Customer::doOrder(string id, int *balance, enPizzaMenu& menu, int& count)
{
	system("cls");
	int sel, num;
	cout << "  <<�޴� ����>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "���� ���� : ";
	cin >> sel;
	cout << "���� �Է� : ";
	cin >> num;

	count = num;
    if ( sel < HAWAIIAN_PIZZA || sel > POTATO_PIZZA || num <= 0)
    {
        cout << "�߸��� �Է��Դϴ�." << endl;
		Sleep(500);
		return false;
    }

	const auto selMenu = (enPizzaMenu)sel;
	string emptyIngredient;
	Pizza* pizza = nullptr;
	if (!PiStore->ProcessOrder(make_pair(selMenu, num), pizza, emptyIngredient))
	{
		cout << emptyIngredient << " �������� �ֹ��� �� �����ϴ�." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough Ingredient : %s", emptyIngredient.c_str());
		Sleep(500);
		return false;
	}


	const int totalPrice = pizza->getPrice() * num;
	if (*balance < totalPrice)
	{
		cout << "�ܾ��� �����մϴ�." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough Customer's balance : %d, totalPrice : %d", *balance, totalPrice);

		if (pizza)
			delete pizza;

		Sleep(500);
		return false;
	}

	if (pizza)
		delete pizza;
	//
	*balance -= totalPrice;
	//DB->updateBalance(id, balance -= totalPrice);
	menu = selMenu;
	cout << "�ֹ� �����Ǿ����ϴ�." << endl << endl;
	 
	//CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Order Success menu : %s, count : %d", selMenu, num);
	Sleep(500);
	
	return true;
}


