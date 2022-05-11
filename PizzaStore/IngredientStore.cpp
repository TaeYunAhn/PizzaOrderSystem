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
        //if �� 
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
    cout << "----��� ����Ʈ---- " << endl;
    for (map<Ingredient, int>::iterator itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {

        cout << "�̸� : " << itr->first.name << endl;
        cout << "���� : " << itr->first.price << endl;
        cout << "��� : " << itr->second << endl;
    }


}



bool IngredientStore::writeComponent(string& Name, int& Price, int& Stock)
{
    //cout << "��� �̸� : ";
    //cin >> Name;
    ////��� �ߺ��Ǵ��� Ȯ��
    ////bool find = false;
    ////for (int i = 0 )
    //cout << "��� ���� : ";
    //cin >> Price;
    //cout << "��� ���� : ";
    //cin >> Stock;
    //return true;

    //if (*name.empty() || *name.length() >= 20 || *price == 0 || stock==0 )
    //{   
    //    cout << "�Է°��� �߸��Ǿ����ϴ�. �Է°��� Ȯ���ϼ���"<<endl <<endl;
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

        cout << "  < ��� �߰� >  " << endl;
        const bool res = writeComponent(Name, Price, Stock);
        if (res == false)
            continue;
        Ingredient Ingredient(Name, Price);
        ingredientVector.push_back(Ingredient);
        //ingredientVector.emplace_back(name, price, stock);
        FileSave::saveIngredient(ingredientStockMap);
        cout << "�߰� �Ǿ����ϴ�." << endl << endl;
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
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        res = writeComponent(name, price, stock);
        if (res == false)
            continue;
        int num = sel - 1;
        //ingredientVector[num].Name = name;
        //ingredientVector[num].Price = price;
        //ingredientVector[num].Stock = stock;
        cout << "�����Ǿ����ϴ�." << endl << endl;
        Sleep(500);
    }
}

void IngredientStore::deleteIngredient()
{
    while (true)
    {

        system("cls");
        int sel = 0;
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        if (sel > ingredientVector.size() + 1)
        {
            cout << "���� ��ȣ�Դϴ�. ��ȣ�� Ȯ���� �ּ���" << endl;
            Sleep(500);
            continue;
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "�����Ǿ����ϴ�." << endl << endl;

    }
}


bool IngredientStore::RunIngredientStore()
{
    while (true)
    {

        system("cls");

        int sel = 0;
        cout << "  << ��ᰡ�� >>  " << endl;
        cout << "1. ��� �߰�" << endl;
        cout << "2. ��� ����" << endl;
        cout << "3. ��� ����" << endl;
        cout << "4. ��� Ȯ��" << endl;
        cout << "5. ���� �޴�" << endl;
        cout << "���� : ";
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
            cout << "  < ��� Ȯ�� >  " << endl;
            ShowIngredientList();

            cout << "���� �Ŵ��� ���ư����� �ƹ�Ű�� �Է����ּ���";
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