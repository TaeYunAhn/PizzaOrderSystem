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
        cout << "  << 메뉴 >>  " << endl;
        cout << "1. 주문 하기" << endl;
        cout << "2. 주문 이력 확인" << endl;
        cout << "3. 프로그램 종료" << endl;
        
        cout << "선택 : ";
        cin >> res;
        if (res == 1)
        {
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

        }
        else if (res == 5)
            return true;

        else
            PiStore->tryAgain();

    }
}