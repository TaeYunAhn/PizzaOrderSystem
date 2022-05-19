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
        cout << "  << " << id << "의" << " 메뉴 >> " << endl;
        cout << "1. 주문" << endl;
        cout << "2. 주문 이력 확인" << endl;
		//cout << "3. 잔액" << endl;
		// 실시간으로 잔액 나타내게 하고 싶은데 고민좀 해보겠습니다.. 
		cout << "3. 로그아웃" << endl;

        cout << "선택 : ";
        cin >> res;

		switch (res)
		{
		case 1:
			doOrder(id);
			break;
		case 2:
		{
			for (map<enPizzaMenu, int>::iterator itr = pizzaCount.begin(); itr != pizzaCount.end(); itr++)
			{
				cout << "피자 종류 : " << getPizzaName(itr->first) << endl;
				cout << "주문 횟수 : " << itr->second << "번" << endl
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
	
	AccountwithPIzza AWP(BULGOGI_PIZZA, 1);
	AccountwithPIzza AWP2(type, count);
	array<AccountwithPIzza, PIZZA_TOTAL - 1> a;

	a[AWP.type - 1] = AWP;

	pizzaCount["TW"] = a;

	pizzaCount["TW"].type = COMBINATION_PIZZA;
	pizzaCount["TW"].Count++;

	pizzaCount["TW"].type = POTATO_PIZZA;
	pizzaCount["TW"].Count++;

	/*A<double> a(5.5);
	a.power();*/
}

void Customer::addPizzaCount(string id, enPizzaMenu menu, int count)
{
	AccountwithPIzza AWP(menu, count);
	array<AccountwithPIzza, PIZZA_TOTAL - 1> a;
	a[AWP.type - 1] = AWP;

	pizzaCount[id] = AWP;
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

		cout << "이전 메뉴로 돌아가시려면 아무 키나 입력해 주세요" << endl;
		cin >> answer;
		return true;
	}
	
}


void Customer::doOrder()
{
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

	PiStore->ProcessOrder((enPizzaMenu)sel);
	++pizzaCount[(enPizzaMenu)sel];
}