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
		{
			for (map<enPizzaMenu, int>::iterator itr = pizzaCount.begin(); itr != pizzaCount.end(); itr++)
			{
				cout << "���� ���� : " << getPizzaName(itr->first) << endl;
				cout << "�ֹ� Ƚ�� : " << itr->second << "��" << endl
					<< endl;
			}
			bool ret = goBack();
			if (ret == true)
				continue;
			break;
		}
		case 3:
			return;
		default:
			break;
		}
    }
}


string Customer::getPizzaName(enPizzaMenu res) 
{
	switch (res)
	{
	case HAWAIIAN_PIZZA: return "HAWAIIAN PIZZA";	
	case CHEESE_PIZZA: return "CHEESE PIZZA";	
	case COMBINATION_PIZZA: return "COMBINATION PIZZA";	
	case BULGOGI_PIZZA: return "BULGOGI PIZZA";	
	case POTATO_PIZZA:return "POTATO PIZZA";
	case PIZZA_TOTAL: return "";	
	default: break;
	}
}


bool Customer::goBack()
{
	while (true)
	{
		string answer;

		cout << "���� �޴��� ���ư��÷��� �ƹ� Ű�� �Է��� �ּ���" << endl;
		cin >> answer;
		return true;
	}
	
}


void Customer::doOrder()
{
	system("cls");
	int sel;
	cout << "  <<�޴� ����>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "���� ���� : ";
	cin >> sel;
	/*const enPizzaMenu pizzaNum = getPizzaNum(name);
	if (pizzaNum == PIZZA_TOTAL)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}*/

	PiStore->ProcessOrder((enPizzaMenu)sel);
	++pizzaCount[(enPizzaMenu)sel];
}