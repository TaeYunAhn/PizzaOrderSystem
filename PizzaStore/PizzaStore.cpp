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
    cout << "  << �޴� >>  "<<endl;
    cout << "1. �޴� ����"<<endl;
    cout << "2. �޴� ����"<<endl;
    cout << "3. �޴� ����"<<endl;
    cout << "4. ���� Ȯ��"<<endl;
    cout << "���� : ";
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
    
    _pizzaMenu.push_back(PizzaMenu("��������", "�������� ġ��, ��ö�, ����", 20000, 0));
}

void PizzaStore::modifyMenu()
{

}

void PizzaStore::deleteMenu()
{

}

void PizzaStore::confirmSales()
{

    /*const EN_RESULT res = IngredientStore->getIng("�������� ġ��", 5);
    switch ( res )
    {
    default:
        break;
    }

    if ( !IngredientStore->getIng("�������� ġ��", 5) )
    {
        "��ᰡ �����ϴ�.(��������)";
    }*/
}

void PizzaStore::tryAgain()
{

}