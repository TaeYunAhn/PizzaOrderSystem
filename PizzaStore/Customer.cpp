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
	cout << "  <<�޴� ����>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "���� ���� : ";
	cin >> sel;

    if ( sel < HAWAIIAN_PIZZA || sel > POTATO_PIZZA )
    {
        cout << "�߸��� �Է��Դϴ�." << endl;
		Sleep(500);
		return false;
    }

	const auto selMenu = (enPizzaMenu)sel;
	Pizza* pizza = nullptr;
	if (!PiStore->ProcessOrder(selMenu, pizza))
	{
		cout << "��� �������� �ֹ��� �� �����ϴ�." << endl << endl;
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


