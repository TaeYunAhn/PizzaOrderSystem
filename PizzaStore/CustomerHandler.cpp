#include "CustomerHandler.h"
#include "Logger.h"
#include <iostream>

using namespace std;


CustomerHandler::CustomerHandler()
{

}

CustomerHandler::~CustomerHandler()
{

}

void CustomerHandler::run(string userId)
{
	CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "START, id : %s", userId); // balance �� ����

    int balance = 0;// temp
    Customer cus;
    //EN_CUSTOMER_RESULT res = cus.runCustomer(id, balance);
    // ���̽� ������ �̳����� ���� �޼��� ������ �ϴ°� ���⼭ �ؾ�����, Ȥ�� customer �� doOrder���� �ؾ� ���� �𸣰ڽ��ϴ�..

	Info info;
	for (auto m : accountsInfoData)
	{
		if (m.ID == userId)
			balance = m.Balance;
	}
  	while (true)
	{
		system("cls");
		int res = 0;
		cout << "  << " << userId << "��" << " �޴� >> " << endl;
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
			cus.doOrder(userId, &balance);
			break;
		case 2:
		{
			bool isOrdered = false;
			for (const auto& p : PizzaCountData)
			{
				if (p.first != userId)
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