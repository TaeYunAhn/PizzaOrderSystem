#include <iostream>
#include "Pizza.h"
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

bool Customer::doOrder(string id, int *balance)
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

	Pizza* pizza = nullptr;
	if (!PiStore->ProcessOrder((enPizzaMenu)sel, pizza))
	{
		cout << "��� �������� �ֹ��� �� �����ϴ�." << endl << endl;
		Sleep(500);
		return false;
	}

	if (pizza)
	{
		*balance -= pizza->getPrice();
		delete pizza;
	}

	// To Fix
	// balance ������ cout ����?
	// processorder �� return �� enum ���� �ٲ�� �ҵ� 
	// �ϴ� handler ���� ����� ����?

	
	//int count = 0;
	//AccountwithPIzza AWP((enPizzaMenu)sel, count);
	//count = AWP.Count;
	//addPizzaCount(id, (enPizzaMenu)sel, count);
	
	//AccountwithPIzza AWP;
	//AWP.type = (enPizzaMenu)(sel + 1);
	//++AWP.Count;

}


