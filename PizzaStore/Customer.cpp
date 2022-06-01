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
	cout << "  <<�޴� ����>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "���� ���� : ";
	cin >> sel;

    if ( sel < HAWAIIAN_PIZZA || sel > POTATO_PIZZA )
    {
        cout << "�߸��� �Է��Դϴ�." << endl;
        return;
    }

	if (PiStore->ProcessOrder((enPizzaMenu)sel) == false)
	{
		cout << "��� �������� �ֹ��� �� �����ϴ�." << endl << endl;
		Sleep(500);
	}
	*balance -= getprice(sel);
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
