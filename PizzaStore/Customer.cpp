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
        cout << "  << " << __id << "의" << " 메뉴 >> " << endl;
        cout << "1. 주문" << endl;
        cout << "2. 주문 이력 확인" << endl;
        cout << "3. 로그아웃" << endl;
        
        cout << "선택 : ";
        cin >> res;
        if (res == 1)
        {
            system("cls");
            int sel;
            cout << "  <<메뉴 선택>>  " << endl;
            PiStore->ShowPizzaList();
            cout << "피자 번호 : ";
            cin >> sel;
            //여기 너무 더러운것 같습니다. 더 좋은 방법 있을까요?
            
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