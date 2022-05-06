#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include "FileSave.h"
#include "IngredientStore.h"
using namespace std;

IngredientStore::IngredientStore()
{
    vector<ingredient> data;
    if (FileSave::readIngredient(data ))
        ingredientVector = data;
}

IngredientStore::~IngredientStore()
{

}

bool IngredientStore::checkIngredients(vector<string> ingredients, int cost)
{
    for (int i = 0; i < ingredients.size(); ++i)
    {
        vector<string>::iterator itr = ingredientMap[ingredients[i]].find();
    }
    
}

void IngredientStore::ShowIngredientList()
{
    const vector<ingredient>& totalIng = GetIngredientList();
    
    cout << "----재료 리스트---- "<<endl;
    for ( int i = 0; i < totalIng.size(); i++ )
    {

        cout << i+1 <<"번 "<<endl;
        cout << "이름 : " << totalIng[i].Name  << endl;
        cout << "가격 : " << totalIng[i].Price << endl;
        cout << "재고 : " << totalIng[i].Stock << endl<<endl;;
    }
    
    
}

vector<ingredient>& IngredientStore::GetIngredientList()
{
    return ingredientVector;

}

bool IngredientStore::writeComponent(string &Name, int &Price, int &Stock)
{
    cout << "재료 이름 : ";
    cin >> Name;
    //재고 중복되는지 확인
    //bool find = false;
    //for (int i = 0 )
    cout << "재료 가격 : ";
    cin >> Price;
    cout << "재고 갯수 : ";
    cin >> Stock;
    return true;

    //if (*name.empty() || *name.length() >= 20 || *price == 0 || stock==0 )
    //{   
    //    cout << "입력값이 잘못되었습니다. 입력값을 확인하세요"<<endl <<endl;
    //    Sleep(500);
    //    return false;
    //}
    //return true;
}


void IngredientStore::addIngredient()
{
    while(true )
    {
        system("cls");
        string Name = "";
        int Price = 0;
        int Stock = 0;

        cout << "  < 재료 추가 >  " << endl;
        const bool res = writeComponent(Name, Price, Stock);
        if (res == false )
           continue;
        ingredient Ingredient(Name, Price, Stock);
        ingredientVector.push_back(Ingredient);
        //ingredientVector.emplace_back(name, price, stock);
        FileSave::saveIngredient(ingredientVector);
        cout << "추가 되었습니다."<<endl <<endl;
        Sleep(500);
        break;
    }
}

void IngredientStore::modifyIngredient()
{
    while (true )
    {
        system("cls");
        string name;
        int price;
        int stock;
        int sel = 0;
        bool res;
        cout << "  < 재료 수정 >  " << endl;
        ShowIngredientList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        res = writeComponent(name, price, stock);
        if (res == false )
            continue;
        int num = sel - 1;
        ingredientVector[num].Name = name;
        ingredientVector[num].Price = price;
        ingredientVector[num].Stock = stock;
        cout << "수정되었습니다." << endl<<endl;
        Sleep(500);
    }
}

void IngredientStore::deleteIngredient()
{
    while (true )
    {
        
        system("cls");
        int sel = 0;
        cout << "  < 재료 삭제 >  " << endl;
        ShowIngredientList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > ingredientVector.size() + 1 )
        {
            cout << "없는 번호입니다. 번호를 확인해 주세요"<<endl;
            Sleep(500);
            continue;
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "삭제되었습니다."<<endl<<endl;
        
    }
}


bool IngredientStore::RunIngredientStore()
{
    while ( true )
    {

        system("cls");

        int sel = 0;
        cout << "  << 재료가게 >>  " << endl;
        cout << "1. 재료 추가" << endl;
        cout << "2. 재료 수정" << endl;
        cout << "3. 재료 삭제" << endl;
        cout << "4. 재고 확인" << endl;
        cout << "5. 이전 메뉴" << endl;
        cout << "선택 : ";
        cin >> sel;
        cout << "\n";

        switch ( sel )
        {
        case 1:
        {
        {
                system("cls");
            addIngredient(); 
        }
        break;

        case 2:
        {
            system("cls");
            modifyIngredient();
        }
        break;

        case 3:
        {
            system("cls");
            deleteIngredient();
        }
        break;

        case 4:
        {
            string anykey;
            system("cls");
            cout << "  < 재고 확인 >  " << endl;
            ShowIngredientList();
            
            cout << "메인 매뉴로 돌아가려면 아무키나 입력해주세요";
            cin >> anykey;

        }
        break;

        case 5:
        {
            return true;
        }
        break;
        
        default:
            break;
        }
        
    }
}
}