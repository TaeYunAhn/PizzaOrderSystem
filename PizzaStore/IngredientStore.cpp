#pragma once
#include "IngredientStore.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

IngredientStore::IngredientStore()
{

}

IngredientStore::~IngredientStore()
{

}

void IngredientStore::ShowIngredientList()
{
    vector<ingredient> totalIng;
    totalIng = GetIngredientList();
    string name;
    int price;
    int stock;
    cout << "----재료 리스트---- "<<endl;
    for ( int i = 0; i < totalIng.size(); i++ )
    {

        cout << i+1 <<"번 "<<endl;
        cout << "이름 : " << totalIng[i].Name << endl;
        cout << "가격 : " << totalIng[i].Price << endl;
        cout << "재고 : " << totalIng[i].Stock << endl<<endl;;
    }
    
    
}

vector<ingredient> IngredientStore::GetIngredientList()
{
    return ingredientVector;

}

bool IngredientStore::addMenu(const string &name, const int &price, const int &stock)
{
    if (name.size() == 0 || name.size() >= 20 || !price || !stock )
        return false;

    ingredient Ingredient(name, price, stock);
    ingredientVector.push_back(Ingredient);
    return true;

}

void IngredientStore::SelectMenu()
{
    while ( true )
    {

    
    int sel = 0;
    cout << "  < MENU >  " << endl;
    cout << "1. 재료 추가" << endl;
    cout << "2. 재료 수정" << endl;
    cout << "3. 재료 삭제" << endl;
    cout << "4. 재고 확인" << endl;
    cout << "선택 : ";
    cin >> sel;
    cout << "\n";

    switch ( sel )
    {
    case 1:
    {
        string name;
        int price;
        int stock;
        bool res;

        cout << "  < 재료 추가 >  " << endl;
        cout << "재료 이름 : ";
        cin >> name;
        //재고 중복되는지 확인
        //bool find = false;
        //for (int i = 0 )
        cout << "재료 가격 : ";
        cin >> price;
        cout << "재고 갯수 : ";
        cin >> stock;
        res = addMenu(name, price, stock);
        if (res == true)
            cout << "추가 완료 되었습니다."<<endl <<endl;
        else if (res == false )
            cout << "추가 실패했습니다. 입력값을 확인하세요"<<endl <<endl;
    
    }
    break;

    case 2:
    {
        string name;
        int price;
        int stock;
        int sel = 0;
        cout << "  < 재료 수정 >  " << endl;
        ShowIngredientList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        
        cout << "재료 이름 : ";
        cin >> name;
        //다른 재료와 중복되는지 확인
        //bool find = false;
        //for (int i = 0 )
        cout << "재료 가격 : ";
        cin >> price;
        cout << "재고 갯수 : ";
        cin >> stock;
        
        if ( name.size() == 0 || name.size() >= 20 || !price || !stock )
        {
            cout << "입력값이 잘못되었습니다. 다시 확인해 주세요";
            SelectMenu();
            // 여기서 switch 2: 로 가고싶은데 어떻게 하면 될까요??
        }
        ingredientVector[sel - 1].Name = name;
        ingredientVector[sel - 1].Price = price;
        ingredientVector[sel - 1].Stock = stock;
        cout << "수정되었습니다." << endl<<endl;
   

    }
    break;

    case 3:
    {
        string name;
        int price;
        int stock;
        int sel = 0;
        cout << "  < 재료 삭제 >  " << endl;
        ShowIngredientList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > ingredientVector.size() + 1 )
        {
            cout << "없는 번호입니다. 번호를 확인해 주세요"<<endl;
            // 스위치 3을 다시 호출
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "삭제되었습니다."<<endl<<endl;


       
    }
    break;

    case 4:
    {
        cout << "  < 재고 확인 >  " << endl;
        ShowIngredientList();
    }
    break;

    default:
        break;
    }
    }
}