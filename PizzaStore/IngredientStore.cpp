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

void IngredientStore::ShowIngredientList()
{
    const vector<ingredient>& totalIng = GetIngredientList();
    
    cout << "----��� ����Ʈ---- "<<endl;
    for ( int i = 0; i < totalIng.size(); i++ )
    {

        cout << i+1 <<"�� "<<endl;
        cout << "�̸� : " << totalIng[i].Name  << endl;
        cout << "���� : " << totalIng[i].Price << endl;
        cout << "��� : " << totalIng[i].Stock << endl<<endl;;
    }
    
    
}

vector<ingredient>& IngredientStore::GetIngredientList()
{
    return ingredientVector;

}

bool IngredientStore::writeComponent(string &name, int &price, int &stock)
{
    cout << "��� �̸� : ";
    cin >> name;
    //��� �ߺ��Ǵ��� Ȯ��
    //bool find = false;
    //for (int i = 0 )
    cout << "��� ���� : ";
    cin >> price;
    cout << "��� ���� : ";
    cin >> stock;
    return true;

    //if (*name.empty() || *name.length() >= 20 || *price == 0 || stock==0 )
    //{   
    //    cout << "�Է°��� �߸��Ǿ����ϴ�. �Է°��� Ȯ���ϼ���"<<endl <<endl;
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
        string name = "";
        int price = 0;
        int stock = 0;

        cout << "  < ��� �߰� >  " << endl;
        const bool res = writeComponent(name, price, stock);
        if (res == false )
           continue;
        ingredient Ingredient(name, price, stock);
        ingredientVector.push_back(Ingredient);
        //ingredientVector.emplace_back(name, price, stock);
        FileSave::saveIngredient(ingredientVector);
        cout << "�߰� �Ǿ����ϴ�."<<endl <<endl;
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
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        res = writeComponent(&name, &price, &stock);
        if (res = false )
            continue;
        int num = sel - 1;
        ingredientVector[num].Name = name;
        ingredientVector[num].Price = price;
        ingredientVector[num].Stock = stock;
        cout << "�����Ǿ����ϴ�." << endl<<endl;
        Sleep(500);
    }
}

void IngredientStore::deleteIngredient()
{
    while (true )
    {
        
        system("cls");
        int sel = 0;
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        if ( sel > ingredientVector.size() + 1 )
        {
            cout << "���� ��ȣ�Դϴ�. ��ȣ�� Ȯ���� �ּ���"<<endl;
            Sleep(500);
            continue;
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "�����Ǿ����ϴ�."<<endl<<endl;
        Sleep(500);
    }
}


void IngredientStore::SelectMenu()
{
    while ( true )
    {

        system("cls");

        int sel = 0;
        cout << "  < MENU >  " << endl;
        cout << "1. ��� �߰�" << endl;
        cout << "2. ��� ����" << endl;
        cout << "3. ��� ����" << endl;
        cout << "4. ��� Ȯ��" << endl;
        cout << "���� : ";
        cin >> sel;
        cout << "\n";

        switch ( sel )
        {
        case 1:
        {
        {
            addIngredient(); 
        }
        break;

        case 2:
        {
            modifyIngredient();
        }
        break;

        case 3:
        {
            deleteIngredient();
        }
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

        default:
            break;
        }
    }
}
}