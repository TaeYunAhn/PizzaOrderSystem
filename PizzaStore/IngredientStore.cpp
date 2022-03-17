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
    cout << "----��� ����Ʈ---- "<<endl;
    for ( int i = 0; i < totalIng.size(); i++ )
    {

        cout << i+1 <<"�� "<<endl;
        cout << "�̸� : " << totalIng[i].Name << endl;
        cout << "���� : " << totalIng[i].Price << endl;
        cout << "��� : " << totalIng[i].Stock << endl<<endl;;
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
        string name;
        int price;
        int stock;
        bool res;

        cout << "  < ��� �߰� >  " << endl;
        cout << "��� �̸� : ";
        cin >> name;
        //��� �ߺ��Ǵ��� Ȯ��
        //bool find = false;
        //for (int i = 0 )
        cout << "��� ���� : ";
        cin >> price;
        cout << "��� ���� : ";
        cin >> stock;
        res = addMenu(name, price, stock);
        if (res == true)
            cout << "�߰� �Ϸ� �Ǿ����ϴ�."<<endl <<endl;
        else if (res == false )
            cout << "�߰� �����߽��ϴ�. �Է°��� Ȯ���ϼ���"<<endl <<endl;
    
    }
    break;

    case 2:
    {
        string name;
        int price;
        int stock;
        int sel = 0;
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        
        cout << "��� �̸� : ";
        cin >> name;
        //�ٸ� ���� �ߺ��Ǵ��� Ȯ��
        //bool find = false;
        //for (int i = 0 )
        cout << "��� ���� : ";
        cin >> price;
        cout << "��� ���� : ";
        cin >> stock;
        
        if ( name.size() == 0 || name.size() >= 20 || !price || !stock )
        {
            cout << "�Է°��� �߸��Ǿ����ϴ�. �ٽ� Ȯ���� �ּ���";
            SelectMenu();
            // ���⼭ switch 2: �� ��������� ��� �ϸ� �ɱ��??
        }
        ingredientVector[sel - 1].Name = name;
        ingredientVector[sel - 1].Price = price;
        ingredientVector[sel - 1].Stock = stock;
        cout << "�����Ǿ����ϴ�." << endl<<endl;
   

    }
    break;

    case 3:
    {
        string name;
        int price;
        int stock;
        int sel = 0;
        cout << "  < ��� ���� >  " << endl;
        ShowIngredientList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        if ( sel > ingredientVector.size() + 1 )
        {
            cout << "���� ��ȣ�Դϴ�. ��ȣ�� Ȯ���� �ּ���"<<endl;
            // ����ġ 3�� �ٽ� ȣ��
        }
        ingredientVector.erase(ingredientVector.begin() + sel - 1);
        //v.erase(v.begin() + i);
        cout << "�����Ǿ����ϴ�."<<endl<<endl;


       
    }
    break;

    case 4:
    {
        cout << "  < ��� Ȯ�� >  " << endl;
        ShowIngredientList();
    }
    break;

    default:
        break;
    }
    }
}