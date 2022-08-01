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
		cout << "  << " << customerId << "��" << " �޴� >> " << endl;
		cout << "1. �ֹ�" << endl;
		cout << "2. �ֹ� �̷� Ȯ��" << endl;
		cout << "3. ����Ʈ ����" << endl;
		cout << "4. �α׾ƿ�" << endl;
		cout << "���� �ܾ� : " << balance << "��" << endl << endl;

		cout << "���� : ";
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
				// TO FIX ���⼭�� INSERT ���� UPDATE ���� Ȯ�� �Ұ�.. 
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
			// TO FIX ���⼭�� INSERT ���� UPDATE ���� Ȯ�� �Ұ�.. 
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

bool CustomerHandler::chargePoint(int& balance) // ���� �ܾ� ��Ÿ���� ���� ���� �޴°ɷ� �����߽��ϴ�. 
{
    int tempbalance;
    cout << "    <<����Ʈ ����>>    " << endl;
    cout << "���� �ܾ� : " << balance << endl;
    cout << "�� �����Ͻðڽ��ϱ� :";
    cin >> tempbalance;
	if (tempbalance <= 0)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
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