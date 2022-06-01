#include "CustomerHandler.h"
#include <iostream>

using namespace std;


CustomerHandler::CustomerHandler()
{
    if (0 < PizzaCountData.size())
    {
        //pizzaCount.insert(PizzaCountData.begin(), PizzaCountData.end());
    } 
    // 생성자에서  복사해주고 소멸자에서 다시 데이터 받아서 관리하는쪽으로 하려 했는데 잘 안되네요
}

CustomerHandler::~CustomerHandler()
{

}

void CustomerHandler::run(string id)
{
    int balance = 0;// temp
    Customer cus;
    //EN_CUSTOMER_RESULT res = cus.runCustomer(id, balance);
    // 케이스 나눠서 이넘으로 에러 메세지 나오게 하는걸 여기서 해야할지, 혹은 customer 의 doOrder에서 해야 할지 모르겠습니다..

	Info info;
	for (auto m : accountsInfoData)
	{
		if (m.ID == id)
			balance = m.Balance;
	}
  	while (true)
	{
		system("cls");
		int res = 0;
		cout << "  << " << id << "의" << " 메뉴 >> " << endl;
		cout << "1. 주문" << endl;
		cout << "2. 주문 이력 확인" << endl;
		cout << "3. 포인트 충전" << endl;
		cout << "4. 로그아웃" << endl;
		cout << "현재 잔액 : " << balance << "원" << endl << endl;

		cout << "선택 : ";
		cin >> res;

		switch (res)
		{
		case 1:
			cus.doOrder(id, &balance);
			break;
		case 2:
		{
			bool isOrdered = false;
			for (const auto& p : PizzaCountData)
			{
				if (p.first != id)
					continue;

				for (const auto& e : p.second)
				{
					if (e.Count == 0)
						continue;

					cout << "피자 종류 : " << getPizzaName(e.type) << endl;
					cout << "주문 횟수 : " << e.Count << "번" << endl << endl;
					isOrdered = true;
				}
			}

			if (!isOrdered)
				cout << "주문 내역이 없습니다." << endl << endl;

			bool ret = cus.goBack();
			if (ret == true)
				continue;
			break;
		}
		case 3:
		{
			int tmepbalance;
			cout << "    <<포인트 충전>>    " << endl;
			cout << "현재 잔액 : " << balance << endl;
			cout << "얼마 충전하시겠습니까 :";
			cin >> tmepbalance;
			balance += tmepbalance;
			//To do 
			//예외처리 할 것.
			
			break;
		}
		case 4:
			return;
		default:
			break;
		}
	}
}