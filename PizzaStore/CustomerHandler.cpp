#include "CustomerHandler.h"
#include <iostream>

using namespace std;


CustomerHandler::CustomerHandler()
{
    if (0 < PizzaCountData.size())
    {
        //pizzaCount.insert(PizzaCountData.begin(), PizzaCountData.end());
    } 
    // �����ڿ���  �������ְ� �Ҹ��ڿ��� �ٽ� ������ �޾Ƽ� �����ϴ������� �Ϸ� �ߴµ� �� �ȵǳ׿�
}

CustomerHandler::~CustomerHandler()
{

}

void CustomerHandler::handleCustomer(string customerId, PizzaStore* pizzaStore)
{
    Customer customer(pizzaStore);
    //EN_CUSTOMER_RESULT res = cus.runCustomer(customerId, balance);
    // ���̽� ������ �̳����� ���� �޼��� ������ �ϴ°� ���⼭ �ؾ�����, Ȥ�� customer �� doOrder���� �ؾ� ���� �𸣰ڽ��ϴ�..

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

            cout << "���� ���� : " << getPizzaName(e.type) << endl;
            cout << "�ֹ� Ƚ�� : " << e.Count << "��" << endl << endl;
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
