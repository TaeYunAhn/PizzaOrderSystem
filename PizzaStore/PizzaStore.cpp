#include "PizzaStore.h"
#include "LoginController.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Logger.h"
using namespace std;


PizzaStore::PizzaStore()
{

}

PizzaStore::~PizzaStore()
{

}

PizzaStore::PizzaStore(IngredientStore *ingre)
{
     
     ingreStore = ingre;
}


void PizzaStore::MainUI()
{
    while ( true )
    {
        int res = 0;
        cout << "  << 피자가게 >>  "<<endl;
        cout << "1. 메뉴 생성"<<endl;
        cout << "2. 메뉴 수정"<<endl;
        cout << "3. 메뉴 삭제"<<endl;
        cout << "4. 매출 확인"<<endl;
        cout << "5. 이전 메뉴"<<endl;
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
        else if ( res == 5 )
        {
            break;
            LoginController login;
            login.MainUI();
        }

        else
            tryAgain();
        
    }
    
}

void PizzaStore::addMenu()
{
    while ( true )
    {
        string Name;
        string Ingredients;
        int Price;
        int Sales = 0;
        cout << "  <<메뉴 추가>>  "<<endl;
        cout << "1. 이름 :";
        cin >> Name;
        cout << "2. 재료 :";
        cin >> Ingredients;
        cout << "3. 가격 :";
        cin >> Price;
        cout << endl;

        PizzaMenu pizza(Name, Ingredients, Price, Sales);
        pizzaMenuVector.push_back(pizza);
        //파일 저장

        cout << "추가 되었습니다."<<endl <<endl;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", Name.c_str(), Ingredients.c_str(), Price);

        Sleep(500);
        break;
    }
    
    

    
    //_pizzaMenu.push_back(PizzaMenu("고르곤졸라", "고르곤졸라 치즈, 루꼴라, 갈릭", 20000, 0));
}

void PizzaStore::modifyMenu()
{
    while ( true )
    {
        string name;
        string ingredients;
        int price;
        int sales = 0;
        unsigned int sel;
        cout << "  <<메뉴 수정>>  "<<endl;
        ShowPizzaList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > 0 && sel - 1 < pizzaMenuVector.size() )
        {
            cout << "피자 이름 : ";
            cin >> name;
            //재고 중복되는지 확인
            //bool find = false;
            //for (int i = 0 )
            cout << "재료 리스트 : ";
            cin >> ingredients;
            cout << "피자 가격 : ";
            cin >> price;
            cout << "판매 갯수 : ";
            cin >> sales;

            int num = sel - 1;
            pizzaMenuVector[num].Name = name;
            pizzaMenuVector[num].Ingredients = ingredients;
            pizzaMenuVector[num].Price = price;
            pizzaMenuVector[num].Sales = sales;
            cout << "수정되었습니다." << endl<<endl;
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", name.c_str(), ingredients.c_str(), price);
            //파일 쓰기
            Sleep(500);
            break;
        }
        else
        {
            cout << "잘못 입력하였습니다." << endl;
            continue;
        }
    }
}

void PizzaStore::deleteMenu()
{
    while ( true )
    {
        unsigned int sel;
        cout << "  <<메뉴 삭제>>  "<<endl;
        ShowPizzaList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > 0 && sel <= pizzaMenuVector.size() )
        {
            pizzaMenuVector.erase(pizzaMenuVector.begin() + sel - 1);
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "delMenu => %d", sel);
            cout << "삭제되었습니다."<<endl<<endl;
            Sleep(500);
            break;
        }
        else
        {
            cout << "잘못 입력하였습니다." << endl;
            continue;
        }
    }
}

void PizzaStore::confirmSales()
{
    //ingreStore->getIng();
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


void PizzaStore::ShowPizzaList()
{
    const vector<PizzaMenu>& PizzaList = GetTotalPizza();

    cout << "----피자 리스트---- "<<endl;
    for ( int i = 0; i < PizzaList.size(); i++ )
    {

        cout << i+1 <<"번 "<<endl;
        cout << "이름 : " << PizzaList[i].Name  << endl;
        cout << "재료 : " << PizzaList[i].Ingredients << endl;
        cout << "가격 : " << PizzaList[i].Price << endl;
        cout << "판매량 : " << PizzaList[i].Sales << endl<<endl;;
    }
}

vector<PizzaMenu> PizzaStore::GetTotalPizza()
{
    return pizzaMenuVector;
}