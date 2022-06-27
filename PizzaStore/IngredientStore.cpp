#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <Windows.h>
#include "FileSave.h"
#include "IngredientStore.h"
#include "Logger.h"
using namespace std;

IngredientStore::IngredientStore()
{
    if (!FileSave::readIngredient(ingredientStockMap))
    {
		cout << "��� ������ �������µ� �����߽��ϴ�." << endl;
    }
}

IngredientStore::~IngredientStore()
{
    
}

EN_STOCK_CHECK IngredientStore::checkIngredients(string ingredients, int& cost)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Check Ingredient : %s", ingredients);

    for (auto& pairElem : ingredientStockMap)
    {
        if (pairElem.first.name == ingredients)
        {
            int& stock = pairElem.second;
            if (stock <= 0)
            {

                CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not enough ingredient");
                return NOT_ENOUGH;
            }
            else
            {
                stock--;
                cost = pairElem.first.price;
                FileSave::saveIngredient(ingredientStockMap);
                CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Confirm ingredient Out, stock : %d", stock);
                return CONFIRM;
            }
        }
    }
    CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Wrong name ingredient, input name : %s", ingredients);
    return WRONG_NAME;
}

void IngredientStore::ShowIngredientList()
{
    cout << "----��� ����Ʈ---- " << endl;
    for (map<Ingredient, int>::iterator itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
        cout << "�̸� : " << itr->first.name << ", " << "���� : " << itr->first.price << ", " << "��� : " << itr->second << endl;
}

void IngredientStore::addIngredient()
{
    system("cls");
	cout << "  < ��� �߰� >  " << endl;
    string name;
    int price = 0;
    int stock = 0;
	cout << "��� �̸� : ";
	cin >> name;
	cout << "��� ���� : ";
	cin >> price;
	cout << "��� ���� : ";
	cin >> stock;

	Ingredient ingredient(name, price);
	if (ingredientStockMap.count(ingredient) > 0)
	{
		cout << "[ERROR] �̹� �ִ� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "allready Exist ingredient name, %s", name);
		Sleep(500);
		return;
	}

    ingredientStockMap[ingredient] = stock;
    FileSave::saveIngredient(ingredientStockMap);
    cout << "�߰� �Ǿ����ϴ�." << endl << endl;
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Add ingredient, %s, %d, %d", name, price, stock);
    Sleep(500);
}

void IngredientStore::modifyIngredientPrice()
{
	system("cls");
	cout << "  < ��� ���� ���� >  " << endl;
	string name;
	int price = 0;
    int tempprice = 0;
    

	cout << "��� �̸� : ";
	cin >> name;
    for (auto itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {
        if (itr->first.name == name)
            tempprice = itr->first.price;
    }
    cout << "���� ���� : " << tempprice << endl;
	cout << "�����Ϸ��� ���� : ";
	cin >> price;

	Ingredient ingredient(name, price);
	if (ingredientStockMap.count(ingredient) == 0)
	{
		cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not Exist ingredient name, %s", name);
		Sleep(500);
		return;
	}
    ingredientStockMap[ingredient] = price;
    FileSave::saveIngredient(ingredientStockMap);
	cout << "���� �Ǿ����ϴ�." << endl << endl;
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Fix ingredient price, %s, %d,", name, price);
	Sleep(500);
}

void IngredientStore::modifyIngredientStock()
{
    system("cls");
    cout << "  < ��� ��� ���� >  " << endl;
    string name;
    int stock = 0;
    int tempstock = 0;


    cout << "��� �̸� : ";
    cin >> name;
    for (auto itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {
        if (itr->first.name == name)
            tempstock = itr->second;
    }
    cout << "���� ��� : " << tempstock << endl;
    cout << "�����Ϸ��� ���� : ";
    cin >> stock;

    Ingredient ingredient(name, stock);
    if (ingredientStockMap.count(ingredient) == 0)
    {
        cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not Exist ingredient name, %s", name);
        Sleep(500);
        return;
    }

    for (auto itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
    {
        if (itr->first.name == name)
            itr->second = stock;
    }
    ingredientStockMap[ingredient] = stock;
    FileSave::saveIngredient(ingredientStockMap);
    cout << "���� �Ǿ����ϴ�." << endl << endl;
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Fix ingredient stock, %s, %d,", name, stock);
    Sleep(500);
}

void IngredientStore::deleteIngredient()
{
    system("cls");
    cout << "  < ��� ���� >  " << endl;
	string name;
    cout << "��� �̸��� �Է��ϼ��� : ";
    cin >> name;
	if (ingredientStockMap.count(Ingredient(name, 0)) == 0)
	{
		cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "not Exist ingredient name, %s", name);
		Sleep(500);
	}


    ingredientStockMap.erase(Ingredient(name, 0));
    FileSave::saveIngredient(ingredientStockMap);
    cout << "�����Ǿ����ϴ�." << endl << endl;
	Sleep(500);
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Delete ingredient, %s", name);

}


bool IngredientStore::runIngredientStore()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Run ingredient store");
    while (true)
    {
        system("cls");

        int sel = 0;
        cout << "  << ��ᰡ�� >>  " << endl;
        cout << "1. ��� �߰�" << endl;
        cout << "2. ��� ���� ����" << endl;
        cout << "3. ��� ��� ����" << endl;
        cout << "4. ��� ����" << endl;
        cout << "5. ��� Ȯ��" << endl;
        cout << "6. ���� �޴�" << endl;
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
            modifyIngredientPrice();
            break;
        case 3:
            system("cls");
            modifyIngredientStock();
        break;
        case 4:
            system("cls");
            deleteIngredient();
        break;
        case 5:
        {
            string anykey;
            system("cls");
            cout << "  < ��� Ȯ�� >  " << endl;
            ShowIngredientList();

            cout << "���� �Ŵ��� ���ư����� �ƹ�Ű�� �Է����ּ���";
            cin >> anykey;
        }
        break;
        case 6:
            return true;
        default:
            break;
        }
    }
}