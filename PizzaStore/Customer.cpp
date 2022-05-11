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
        cout << "  << " << customer << "��" << " �޴� >> " << endl;
        cout << "1. �ֹ�" << endl;
        cout << "2. �ֹ� �̷� Ȯ��" << endl;
        cout << "3. �α׾ƿ�" << endl;
        
        cout << "���� : ";
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
	cout << "  <<�޴� ����>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "���� �̸� : ";
	cin >> name;
	const enPizzaMenu pizzaNum = getPizzaNum(name);
	if (pizzaNum == PIZZA_TOTAL)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}

	PiStore->ProcessOrder(pizzaNum);
}