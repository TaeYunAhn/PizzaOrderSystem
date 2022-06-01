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

void CustomerHandler::handleCustomer(string customerId, PizzaStore* pizzaStore)
{
    Customer customer(pizzaStore);
    //EN_CUSTOMER_RESULT res = cus.runCustomer(customerId, balance);
    // 케이스 나눠서 이넘으로 에러 메세지 나오게 하는걸 여기서 해야할지, 혹은 customer 의 doOrder에서 해야 할지 모르겠습니다..

	CustomerInfo info;

    auto itr = std::find_if(accountsInfoData.begin(), accountsInfoData.end(), [&customerId] (const CustomerInfo& info) {
        return info.ID == customerId;
    });

    if ( itr == accountsInfoData.end() )
    {
        accountsInfoData.push_back(CustomerInfo(customerId, 50000));
        itr = accountsInfoData.begin();
    }

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
		cout << "현재 잔액 : " << itr->Balance << "원" << endl << endl;

		cout << "선택 : ";
		cin >> res;

		switch (res)
		{
		case 1:
            customer.doOrder(customerId, &itr->Balance);
			break;
		case 2:
            checkRecord(customerId);
			break;
		case 3:
            chargePoint(itr->Balance);
			break;
		case 4:
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
            if (e.Count == 0)
                continue;

            cout << "피자 종류 : " << getPizzaName(e.type) << endl;
            cout << "주문 횟수 : " << e.Count << "번" << endl << endl;
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
