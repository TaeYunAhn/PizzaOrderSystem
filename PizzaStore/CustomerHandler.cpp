#include <iostream>
#include <vector>
#include "Windows.h"

#include "FileSave.h"
#include "DBConnector.h"
#include "CustomerHandler.h"


using namespace std;


CustomerHandler::CustomerHandler()
{
	DBConnector::getInstance()->getAllOrderList(PizzaCountData);
}

CustomerHandler::~CustomerHandler()
{

}

void CustomerHandler::handleCustomer(string customerId, PizzaStore* pizzaStore)
{
    Customer customer(pizzaStore);
   
	int balance = 0;
	vector<CustomerInfo> customerBalance;
	DBConnector::getInstance()->getAccountBalance(customerId, &balance);



    //auto itr = std::find_if(accountsInfoData.begin(), accountsInfoData.end(), [&customerId] (const CustomerInfo& info) {
    //    return info.ID == customerId;
    //});
	// 
    //if ( itr == accountsInfoData.end() )
    //{
    //    accountsInfoData.push_back(CustomerInfo(customerId, 0));
	//	itr = accountsInfoData.end() - 1;
	//
    //}

	/*for (auto m : accountsInfoData)
	{
		if (m.ID == customerId)
			balance = m.Balance;
	}*/

  	while (true)
	{
		system("cls");
		int res = 0;
		cout << "  << " << customerId << "의" << " 메뉴 >> " << endl;
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
		{
			enPizzaMenu menu = PIZZA_START;
			int count = 0;
			if (customer.doOrder(customerId, &balance, menu, count))
			{
				addPizzaCount(customerId, menu, count);
				if (!DBConnector::getInstance()->insertOrderList(customerId, (enPizzaMenu)menu, count))
				{
					//TODO: error
					//cout << ""
				}
				// TO FIX 여기서도 INSERT 인지 UPDATE 인지 확인 불가.. 
			}
		}
		break;
		case 2:
            checkRecord(customerId);
			break;
		case 3:
		{
			int b;
			chargePoint(b);
			DBConnector::getInstance()->updateAccountBalance(customerId, b);
		}
		break;
		case 4:
		
        	//DBConnector::getInstance()->saveOrderList(PizzaCountData);
			// TO FIX 여기서도 INSERT 인지 UPDATE 인지 확인 불가.. 
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

bool CustomerHandler::chargePoint(int& balance) // 현재 잔액 나타내기 위해 인자 받는걸로 수정했습니다. 
{
    int tempbalance;
    cout << "    <<포인트 충전>>    " << endl;
    cout << "현재 잔액 : " << balance << endl;
    cout << "얼마 충전하시겠습니까 :";
    cin >> tempbalance;
	if (tempbalance <= 0)
	{
		cout << "잘못된 입력입니다." << endl;
		Sleep(500);
		return false;
	}
	balance += tempbalance;
	return true;
}

void CustomerHandler::addPizzaCount(const std::string& customerId, const enPizzaMenu menu, /*const*/ int count)
{
	if (PizzaCountData.count(customerId) > 0)
	{
		auto& vData = PizzaCountData[customerId];
		auto itr = find_if(vData.begin(), vData.end(), [&menu](const AccountwithPizza& d)
			{
				return d.type == menu;
			});

		if (itr == vData.end())
			vData.push_back(AccountwithPizza(menu, count));
		//insert
		else
			itr->count += count;
		// count += count 
	}
	else
	{
		vector<AccountwithPizza> vData;
		AccountwithPizza accountPizza(menu, count);
		vData.push_back(accountPizza);
		PizzaCountData[customerId] = vData;
	}
}