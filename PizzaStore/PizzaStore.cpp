#include "PizzaStore.h"
#include <iostream>
#include <string>
using namespace std;


PizzaStore::PizzaStore()
{

}

PizzaStore::~PizzaStore()
{

}

void PizzaStore::MainUI()
{
    int res = 0;
    cout << "  << 메뉴 >>  "<<endl;
    cout << "1. 메뉴 생성"<<endl;
    cout << "2. 메뉴 수정"<<endl;
    cout << "3. 메뉴 삭제"<<endl;
    cout << "4. 매출 확인"<<endl;
    cout << "선택 : ";
    cin >> res;
    if (res == 1 )
        addMenu();
    else if (res == 2 )
        modifyMenu();
    else if (res == 3 )
        deleteMenu();
    else if (res == 4 )
        confirmSales();
    else
        tryAgain();
}

void PizzaStore::addMenu()
{
    
    _pizzaMenu.push_back(PizzaMenu("고르곤졸라", "고르곤졸라 치즈, 루꼴라, 갈릭", 20000, 0));
}

void PizzaStore::modifyMenu()
{

}

void PizzaStore::deleteMenu()
{

}

void PizzaStore::confirmSales()
{

    /*const EN_RESULT res = IngredientStore->getIng("고르곤졸라 치즈", 5);
    switch ( res )
    {
    default:
        break;
    }

    if ( !IngredientStore->getIng("고르곤졸라 치즈", 5) )
    {
        "재료가 없습니다.(고르곤졸라)";
    }*/
}

void PizzaStore::tryAgain()
{

}