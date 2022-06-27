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

bool Customer::doOrder(string id, int *balance, enPizzaMenu& menu, int *count)
{
	system("cls");
	int sel, num;
	cout << "  <<메뉴 선택>>  " << endl;
	PiStore->ShowPizzaList();
	cout << "피자 선택 : ";
	cin >> sel;
	cout << "갯수 입력 : ";
	cin >> num;

	count = &num;
    if ( sel < HAWAIIAN_PIZZA || sel > POTATO_PIZZA || num <= 0)
    {
        cout << "잘못된 입력입니다." << endl;
		Sleep(500);
		return false;
    }

	const auto selMenu = (enPizzaMenu)sel;
	string emptyIngredient;
	Pizza* pizza = nullptr;
	if (!PiStore->ProcessOrder(selMenu, pizza, emptyIngredient))
	{
		cout << emptyIngredient << " 부족으로 주문할 수 없습니다." << endl << endl;
		CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough Ingredient : %s", emptyIngredient);
		Sleep(500);
		return false;
	}

	if (pizza)
	{
		for (int i = 0; i < num; i++)
		{
			// To Fix : 피자 주문 갯수가 2 이상이 되면 엑세스 위반 이라고 뜹니다.. *balance 쪽 문제인것 같아요 
			*balance -= pizza->getPrice();
			delete pizza;
		}
	}

	menu = selMenu;
	cout << "주문 접수되었습니다." << endl << endl;
	//To Fix : 널 포인터에 쓰는것(엑세스 위반) 에러 잘 모르겠습니다. 
	//CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Order Success menu : %s, count : %d", selMenu, num);
	Sleep(500);
	
	return true;
}


