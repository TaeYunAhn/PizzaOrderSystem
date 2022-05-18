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
        cout << "  << " << customer << "의" << " 메뉴 >> " << endl;
        cout << "1. 주문" << endl;
        cout << "2. 주문 이력 확인" << endl;
        cout << "3. 로그아웃" << endl;
        
        cout << "선택 : ";
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