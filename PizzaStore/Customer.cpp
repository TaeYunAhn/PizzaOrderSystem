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
			for (auto itr = pizzaCount.begin(); itr != pizzaCount.end(); itr++)
			{
				cout << "피자 종류 : " << getPizzaName(itr->second) << endl;
				cout << "주문 횟수 : " << getPizzaCount(itr->second) << "번" << endl
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

/* 구조 관련..
* handler 가 있고, 컨트롤러가 있어서 핸들러를 통해서만 컨트롤러가 만들어짐.
* 컨트롤러 안에는 DAO가 있어서 데이터 관리함 
* DAO란.. data access object 
* 
* 또는 fac 구조.. 
* 
* 우리가 가진 문제가.. 
* 커스터머 별로 무얼 주문했고, 얼마나 주문했는지를 모름
* 
* 이 데이터를 커스터머 별로 쓰려고 하니 문제가 생김.
* (1번 id 에서 얼마나 주문했는지 데이터에 쓰고, 로그아웃, 2번 로그인 하면 데이터를 새로 쓰는 참사가..)
* 로그아웃 할때 데이터를 핸들러에 주는 방식으로 바꿔야 할듯?

지금 구조에선, main 에 handler 를 줘야 함
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

		cout << "이전 메뉴로 돌아가시려면 아무 키나 입력해 주세요" << endl;
		cin >> answer;
		return true;
	}
	
}


void Customer::doOrder(string id)
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
	
	//int count = 0;
	//AccountwithPIzza AWP((enPizzaMenu)sel, count);
	//count = AWP.Count;
	//addPizzaCount(id, (enPizzaMenu)sel, count);
	
	//AccountwithPIzza AWP;
	//AWP.type = (enPizzaMenu)(sel + 1);
	//++AWP.Count;

}
