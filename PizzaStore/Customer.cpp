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
 

void Customer::runCustomer(const string &id/*, int balance*/)
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
			for (auto itr = pizzaCount.begin(); itr != pizzaCount.end(); itr++)
			{
				cout << "���� ���� : " << getPizzaName(itr->second) << endl;
				cout << "�ֹ� Ƚ�� : " << getPizzaCount(itr->second) << "��" << endl
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
	a.power();*/
}

/* ���� ����..
* handler �� �ְ�, ��Ʈ�ѷ��� �־ �ڵ鷯�� ���ؼ��� ��Ʈ�ѷ��� �������.
* ��Ʈ�ѷ� �ȿ��� DAO�� �־ ������ ������ 
* DAO��.. data access object 
* 
* �Ǵ� fac ����.. 
* 
* �츮�� ���� ������.. 
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

string Customer::getPizzaName(array<AccountwithPIzza, PIZZA_TOTAL - 1>)
{
	AccountwithPIzza AWP;
	enPizzaMenu res = AWP.type;
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

int Customer::getPizzaCount(array<AccountwithPIzza, PIZZA_TOTAL - 1>)
{
	AccountwithPIzza AWP;
	int res = AWP.Count;
	return res;
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


void Customer::doOrder(string id)
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
	
	//int count = 0;
	//AccountwithPIzza AWP((enPizzaMenu)sel, count);
	//count = AWP.Count;
	//addPizzaCount(id, (enPizzaMenu)sel, count);
	
	//AccountwithPIzza AWP;
	//AWP.type = (enPizzaMenu)(sel + 1);
	//++AWP.Count;

}
