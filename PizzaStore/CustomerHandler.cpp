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
    // ���̽� ������ �̳����� ���� �޼��� ������ �ϴ°� ���⼭ �ؾ�����, Ȥ�� customer �� doOrder���� �ؾ� ���� �𸣰ڽ��ϴ�..

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
		cout << "  << " << customerId << "��" << " �޴� >> " << endl;
		cout << "1. �ֹ�" << endl;
		cout << "2. �ֹ� �̷� Ȯ��" << endl;
		cout << "3. ����Ʈ ����" << endl;
		cout << "4. �α׾ƿ�" << endl;
		cout << "���� �ܾ� : " << itr->Balance << "��" << endl << endl;

		cout << "���� : ";
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

            cout << "���� ���� : " << getPizzaName(e.type) << endl;
            cout << "�ֹ� Ƚ�� : " << e.count << "��" << endl << endl;
            isOrdered = true;
        }
    }

    if (!isOrdered)
        cout << "�ֹ� ������ �����ϴ�." << endl << endl;

    string answer;

    cout << "���� �޴��� ���ư��÷��� �ƹ� Ű�� �Է��� �ּ���" << endl;
    cin >> answer;
}

bool CustomerHandler::chargePoint(int& balance)
{
    int tmepbalance;
    cout << "    <<����Ʈ ����>>    " << endl;
    cout << "���� �ܾ� : " << balance << endl;
    cout << "�� �����Ͻðڽ��ϱ� :";
    cin >> tmepbalance;
    balance += tmepbalance;
    return true;
    //To do 
    //����ó�� �� ��.
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