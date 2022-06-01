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

void CustomerHandler::run(string id)
{
    int balance = 0;// temp
    Customer cus;
    //EN_CUSTOMER_RESULT res = cus.runCustomer(id, balance);
    // ���̽� ������ �̳����� ���� �޼��� ������ �ϴ°� ���⼭ �ؾ�����, Ȥ�� customer �� doOrder���� �ؾ� ���� �𸣰ڽ��ϴ�..

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
		cout << "  << " << id << "��" << " �޴� >> " << endl;
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

					cout << "���� ���� : " << getPizzaName(e.type) << endl;
					cout << "�ֹ� Ƚ�� : " << e.Count << "��" << endl << endl;
					isOrdered = true;
				}
			}

			if (!isOrdered)
				cout << "�ֹ� ������ �����ϴ�." << endl << endl;

			bool ret = cus.goBack();
			if (ret == true)
				continue;
			break;
		}
		case 3:
		{
			int tmepbalance;
			cout << "    <<����Ʈ ����>>    " << endl;
			cout << "���� �ܾ� : " << balance << endl;
			cout << "�� �����Ͻðڽ��ϱ� :";
			cin >> tmepbalance;
			balance += tmepbalance;
			//To do 
			//����ó�� �� ��.
			
			break;
		}
		case 4:
			return;
		default:
			break;
		}
	}
}