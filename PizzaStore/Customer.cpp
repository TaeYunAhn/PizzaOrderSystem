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


bool Customer::RunCustomer(string &__id)
{
    while (true)
    {
        int res = 0;
        cout << "  << " << __id << "��" << " �޴� >> " << endl;
        cout << "1. �ֹ�" << endl;
        cout << "2. �ֹ� �̷� Ȯ��" << endl;
        cout << "3. �α׾ƿ�" << endl;
        
        cout << "���� : ";
        cin >> res;
        if (res == 1)
        {
            system("cls");
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
            system("cls");

        }
        else if (res == 3)
            break;

        else
            PiStore->tryAgain();

    }
    return false;
}