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
/*
EN_CUSTOMER_RESULT Customer::runCustomer(const string &id, int balance)
{
    while (true)
    {
		system("cls");
		int res = 0;
        cout << "  << " << id << "��" << " �޴� >> " << endl;
        cout << "1. �ֹ�" << endl;
        cout << "2. �ֹ� �̷� Ȯ��" << endl;
		//cout << "3. �ܾ�" << endl;
		// �ǽð����� �ܾ� ��Ÿ���� �ϰ� ������ ����� �غ��ڽ��ϴ�.. 
		cout << "3. �α׾ƿ�" << endl;

        cout << "���� : ";
        cin >> res;

		switch (res)
		{
		case 1:
			doOrder(id);
			break;
		case 2:
		{
			bool isOrdered = false;
			for ( const auto& p : pizzaCount)
			{
				if (p.first != id)
					continue;

				for (const auto& e : p.second)
				{
					if (e.Count == 0)
						continue;

					cout << "���� ���� : " << getPizzaName(e.type) << endl;
					cout << "�ֹ� Ƚ�� : " << e.Count << "��" << endl << endl;
					isOrdered = true;
				}
			}

			if ( !isOrdered )
				cout << "�ֹ� ������ �����ϴ�." << endl << endl;

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
	//std::map<string, array<AccountwithPIzza, 10>> pizzaCount;
	
	//AccountwithPIzza AWP(BULGOGI_PIZZA, 1);
	//AccountwithPIzza AWP2(type, count);
	//array<AccountwithPIzza, PIZZA_TOTAL - 1> a;
	//
	//a[AWP.type - 1] = AWP;
	//
	//pizzaCount["TW"] = a;
	//
	//pizzaCount["TW"].type = COMBINATION_PIZZA;
	//pizzaCount["TW"].Count++;
	//
	//pizzaCount["TW"].type = POTATO_PIZZA;
	//pizzaCount["TW"].Count++;

	/*A<double> a(5.5);
	a.power();
}
*/

/* ���� ����..
* handler �� �ְ�, ��Ʈ�ѷ��� �־ �ڵ鷯�� ���ؼ��� ��Ʈ�ѷ��� �������.
* ��Ʈ�ѷ� �ȿ��� DAO�� �־ ������ ������ 
* DAO��.. data access object 
* 
* �Ǵ� fac ����.. 
* 
* �� �ڵ尡 ���� ������.. 
* Ŀ���͸� ���� ���� �ֹ��߰�, �󸶳� �ֹ��ߴ����� ��
* 
* �� �����͸� Ŀ���͸� ���� ������ �ϴ� ������ ����.
* (1�� id ���� �󸶳� �ֹ��ߴ��� �����Ϳ� ����, �α׾ƿ�, 2�� �α��� �ϸ� �����͸� ���� ���� ���簡..)
* �α׾ƿ� �Ҷ� �����͸� �ڵ鷯�� �ִ� ������� �ٲ�� �ҵ�?

���� ��������, main �� handler �� ��� ��
*/

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

		cout << "���� �޴��� ���ư��÷��� �ƹ� Ű�� �Է��� �ּ���" << endl;
		cin >> answer;
		return true;
	}
}

void Customer::doOrder(string userId, int *balance)
{
	CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Order START, id : %s, balance : %d", userId, balance); 

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

	if (PiStore->ProcessOrder((enPizzaMenu)sel) == false)
	{
		cout << "��� �������� �ֹ��� �� �����ϴ�." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough balance : %d", balance); 
		Sleep(500);
	}
	*balance -= getprice(sel);
	CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "balance : %d",balance); 

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
