#include "CustomerHandler.h"
#include "FileSave.h"
#include <iostream>

using namespace std;


CustomerHandler::CustomerHandler()
{
	FileSave::readOrderList(PizzaCountData);
	FileSave::readAccountInfo(accountsInfoData);
}

CustomerHandler::~CustomerHandler()
{

}

void CustomerHandler::handleCustomer(string customerId, PizzaStore* pizzaStore)
{
    Customer customer(pizzaStore);
    //EN_CUSTOMER_RESULT res = cus.runCustomer(customerId, balance);
    // 케이스 나눠서 이넘으로 에러 메세지 나오게 하는걸 여기서 해야할지, 혹은 customer 의 doOrder에서 해야 할지 모르겠습니다..

	/*CustomerInfo* info = nullptr;
    for (auto& a : accountsInfoData)
    {
        if (a.ID == customerId)
            info = &a;
    }*/


    auto itr = std::find_if(accountsInfoData.begin(), accountsInfoData.end(), [&customerId] (const CustomerInfo& info) {
        return info.ID == customerId;
    });

    if ( itr == accountsInfoData.end() )
    {
        accountsInfoData.push_back(CustomerInfo(customerId, 50000));
        itr = accountsInfoData.begin();
        FileSave::saveAccountInfo(accountsInfoData);
    }

	/*for (auto m : accountsInfoData)
	{
		if (m.ID == customerId)
			balance = m.Balance;
	}*/

  	while (true)
	{
		system("cls");
		int count, res = 0;
		cout << "  << " << customerId << "의" << " 메뉴 >> " << endl;
		cout << "1. 주문" << endl;
		cout << "2. 주문 이력 확인" << endl;
		cout << "3. 포인트 충전" << endl;
		cout << "4. 로그아웃" << endl;
		cout << "현재 잔액 : " << itr->Balance << "원" << endl << endl;

		cout << "선택 : ";
		cin >> res;

		switch (res)
		{
		case 1:
		{
			enPizzaMenu menu = PIZZA_START;
			if (customer.doOrder(customerId, &itr->Balance, menu, &count))
			{
				addPizzaCount(customerId, menu, count);
				FileSave::saveOrderList(PizzaCountData);
			}
		}
		break;
		case 2:
            checkRecord(customerId);
			break;
		case 3:
            chargePoint(itr->Balance);
			break;
		case 4:
            FileSave::saveAccountInfo(accountsInfoData);
			FileSave::saveOrderList(PizzaCountData);
			return;
		default:
			break;
		}
	}
}

void CustomerHandler::checkRecord(const string& customerId)
{
    bool isOrdered = false;
    for (const auto& p : PizzaCountData)
    {
        if (p.first != customerId)
            continue;

        for (const auto& e : p.second)
        {
            if (e.count == 0)
                continue;

            cout << "피자 종류 : " << getPizzaName(e.type) << endl;
            cout << "주문 횟수 : " << e.count << "번" << endl << endl;
            isOrdered = true;
        }
    }

    if (!isOrdered)
        cout << "주문 내역이 없습니다." << endl << endl;

    string answer;

    cout << "이전 메뉴로 돌아가시려면 아무 키나 입력해 주세요" << endl;
    cin >> answer;
}

bool CustomerHandler::chargePoint(int& balance)
{
    int tmepbalance;
    cout << "    <<포인트 충전>>    " << endl;
    cout << "현재 잔액 : " << balance << endl;
    cout << "얼마 충전하시겠습니까 :";
    cin >> tmepbalance;
    balance += tmepbalance;
    return true;
    //To do 
    //예외처리 할 것.
}

void CustomerHandler::addPizzaCount(const std::string& customerId, const enPizzaMenu menu, /*const*/ int count)
{
	for (int i = 0; i < count; i++)
	{
		if (PizzaCountData.count(customerId) > 0)
		{
			auto& vData = PizzaCountData[customerId];
			auto itr = find_if(vData.begin(), vData.end(), [&menu](const AccountwithPizza& d)
				{
					return d.type == menu;
				});

			if (itr == vData.end())
				vData.push_back(AccountwithPizza(menu, 1));
			else
				itr->count++;
		}

		else
		{
			vector<AccountwithPizza> vData;
			AccountwithPizza accountPizza(menu, 1);
			vData.push_back(accountPizza);
			PizzaCountData[customerId] = vData;
		}
	}
}