#include "Customer.h"
#include <iostream>


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


bool Customer::MainUI()
{
    while (true)
    {
        int res = 0;
        cout << "  << �޴� >>  " << endl;
        cout << "1. �ֹ� �ϱ�" << endl;
        cout << "2. �ֹ� �̷� Ȯ��" << endl;
        cout << "3. ���α׷� ����" << endl;
        
        cout << "���� : ";
        cin >> res;
        if (res == 1)
        {
            int sel;
            cout << "  <<�޴� ����>>  " << endl;
            PiStore->ShowPizzaList();
            cout << "���� ��ȣ : ";
            cin >> sel;
            //���� �ʹ� ������� �����ϴ�. �� ���� ��� �������?
            
            PiStore->ProcessOrder((EN_PizzaMenu)sel);
            
        }
        else if (res == 2)
        {

        }
        else if (res == 5)
            return true;

        else
            PiStore->tryAgain();

    }
}