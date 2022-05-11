#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <Windows.h>
#include "FileSave.h"
#include "IngredientStore.h"
using namespace std;

IngredientStore::IngredientStore()
{
    if (!FileSave::readIngredient(ingredientStockMap))
    {
    }

    addIngredientStock();
}

IngredientStore::~IngredientStore()
{

}

void IngredientStore::addIngredientStock()
{
    /*ingredientStockMap["dough"] = 10;
    ingredientStockMap["tomato"] = 10;
    ingredientStockMap["cheese"] = 10;
    ingredientStockMap["pineapple"] = 3;
    ingredientStockMap["pork"] = 5;
    ingredientStockMap["bulgogi"] = 10;
    ingredientStockMap["onion"] = 10;
    ingredientStockMap["mozzallela"] = 10;
    ingredientStockMap["olive oil"] = 10;
    ingredientStockMap["ham"] = 10;
    ingredientStockMap["salami"] = 10;
    ingredientStockMap["potato"] = 10;
    ingredientStockMap["pasli"] = 10;*/
}

EN_STOCK_CHECK IngredientStore::checkIngredients(string ingredients, int& cost)
{
    /* map<Ingredient, int>::iterator itr = std::find_if(ingredientStockMap.begin(), ingredientStockMap.end(), [&ingredients] (const pair<Ingredient, int>& e) {
         return e.first.name == ingredients;
     });

     if (itr == ingredientStockMap.end())
         return en_WrongIngreName;
     else
     {
         if (itr->second <= 0)
             return en_NotEnough;

         itr->second--;
         return en_Confirm;
     }*/

     // find 
    for (map<Ingredient, int>::iterator itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {
        //if 문 
        if (itr->first.name == ingredients)
        {
            int& stock = itr->second;
            if (stock <= 0)
            {
                return en_NotEnough;
            }
            else
            {
                stock--;
                cost = itr->first.price;
                return en_Confirm;
            }
        }

        /*int stock = ingredientStockMap[ingredients];
        if (stock <= 0)
        {
            return en_NotEnough;
        }
        else
        {
            stock--;
            return en_Confirm;
        }   */
    }
    return en_WrongIngreName;
}

void IngredientStore::ShowIngredientList()
{
    cout << "----재료 리스트---- " << endl;
    for (map<Ingredient, int>::iterator itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {

        cout << "이름 : " << itr->first.name << endl;
        cout << "가격 : " << itr->first.price << endl;
        cout << "재고 : " << itr->second << endl;
    }


}



bool IngredientStore::writeComponent(string& Name, int& Price, int& Stock)
{
    //cout << "재료 이름 : ";
    //cin >> Name;
    ////재고 중복되는지 확인
    ////bool find = false;
    ////for (int i = 0 )
    //cout << "재료 가격 : ";
    //cin >> Price;
    //cout << "재고 갯수 : ";
    //cin >> Stock;
    //return true;

    //if (*name.empty() || *name.length() >= 20 || *price == 0 || stock==0 )
    //{   
    //    cout << "입력값이 잘못되었습니다. 입력값을 확인하세요"<<endl <<endl;
    //    Sleep(500);
    //    return false;
    //}
    return true;
}


void IngredientStore::addIngredient()
{
    while (true)
    {
        system("cls");
        string Name = "";
        int Price = 0;
        int Stock = 0;

        cout << "  < 재료 추가 >  " << endl;
        const bool res = writeComponent(Name, Price, Stock);
        if (res == false)
            continue;
        Ingredient Ingredient(Name, Price);
        ingredientVector.push_back(Ingredient);
        //ingredientVector.emplace_back(name, price, stock);
        FileSave::saveIngredient(ingredientStockMap);
        cout << "추가 되었습니다." << endl << endl;
        Sleep(500);
        break;
    }
}

void IngredientStore::modifyIngredient()
{
    while (true)
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
        if (res == false)
            continue;
        int num = sel - 1;
        //ingredientVector[num].Name = name;
        //ingredientVector[num].Price = price;
        //ingredientVector[num].Stock = stock;
        cout << "수정되었습니다." << endl << endl;
        Sleep(500);
    }
}

void IngredientStore::deleteIngredient()
{
    while (true)
    {

        system("cls");
        int sel = 0;
        cout << "  < 재료 삭제 >  " << endl;
        ShowIngredientList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if (sel > ingredientVector.size() + 1)
        {
            cout << "없는 번호입니다. 번호를 확인해 주세요" << endl;
            Sleep(500);
            continue;
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "삭제되었습니다." << endl << endl;

    }
}


bool IngredientStore::RunIngredientStore()
{
    while (true)
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

        switch (sel)
        {
        case 1:
            system("cls");
            addIngredient();
        break;
        case 2:
            system("cls");
            modifyIngredient();
        break;
        case 3:
            system("cls");
            deleteIngredient();
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
            return true;
        default:
            break;
        }
    }
}