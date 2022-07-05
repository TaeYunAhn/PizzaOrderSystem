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
    if (!FileSave::readIngredient(ingredientMap))
    {
		cout << "��� ������ �������µ� �����߽��ϴ�." << endl;
    }
}

IngredientStore::~IngredientStore()
{
}

EN_STOCK_CHECK IngredientStore::checkIngredients(const std::pair<std::string, unsigned int>& pairIngre, string &emptyIngredient, int &cost)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Check Ingredient : %s", pairIngre.first.c_str());

    for (auto& pairElem : ingredientMap)
    {
        if (pairElem.first == pairIngre.first)
        {
            const int& stock = pairElem.second.stock;
            if (stock < pairIngre.second)
            {
                emptyIngredient = pairIngre.first;
                CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, 
									"Not enough ingredient, Name : %s count : %u", pairIngre.first.c_str(), pairIngre.second);
                return NOT_ENOUGH;
            }
            else
            {
                cost = pairElem.second.ingredient.price;
                CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Confirm ingredient Out, stock(%s) : %d", pairElem.first.c_str(), stock);
                return CONFIRM;
            }
        }
    }
    CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Wrong name ingredient, input name : %s", pairIngre.first.c_str());
    return WRONG_NAME;
}

bool IngredientStore::grepIngredients(const std::pair<std::string, unsigned int>& pairIngre)
{
    for (auto& pairElem : ingredientMap)
	{
        if (pairElem.first == pairIngre.first)
		{
            int& stock = pairElem.second.stock;
			if (stock < pairIngre.second)
			{
				CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__,
					"Not enough ingredient, Name : %s count : %u", pairIngre.first.c_str(), pairIngre.second);
				
				return false;
			}
			else
			{
				stock -= pairIngre.second;
                FileSave::saveIngredient(ingredientMap);
				return true;
			}
		}
	}
	return false;
}

void IngredientStore::ShowIngredientList()
{
    cout << "----��� ����Ʈ---- " << endl;
    for (map<string, IngredientInfo>::iterator itr = ingredientMap.begin(); itr != ingredientMap.end(); itr++)
        cout << "�̸� : " << itr->first << ", " << "���� : " << itr->second.ingredient.price << ", " << "��� : " << itr->second.stock << endl;
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

    if (ingredientMap.count(name) > 0)
	{
		cout << "[ERROR] �̹� �ִ� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "allready Exist ingredient name, %s", name);
		Sleep(500);
		return;
	}

    ingredientMap[name] = IngredientInfo(Ingredient(name, price), stock);
    FileSave::saveIngredient(ingredientMap);
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
    int stock = 0;

	cout << "��� �̸� : ";
	cin >> name;
    for (auto itr = ingredientMap.begin(); itr != ingredientMap.end(); itr++)
    {
        if (itr->first == name)
        {
            tempprice = itr->second.ingredient.price;
            stock = itr->second.stock;
            continue;
        }
            
        else if (itr == ingredientMap.end())
        {
            cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
            CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not Exist ingredient name, %s", name);
            Sleep(500);
            return;
        }
    }
    cout << "���� ���� : " << tempprice << endl;
	cout << "�����Ϸ��� ���� : ";
	cin >> price;
    ingredientMap[name].ingredient.price = price;
    FileSave::saveIngredient(ingredientMap);
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
    if (ingredientMap.count(name) == 0)
    {
        cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not Exist ingredient name, %s", name);
        Sleep(500);
        return;
    }
    for (auto itr = ingredientMap.begin(); itr != ingredientMap.end(); itr++) 
    {
        if (itr->first == name)
            tempstock = itr->second.stock;
    }
    cout << "���� ��� : " << tempstock << endl;
    cout << "�����Ϸ��� ���� : ";
    cin >> stock;

    for (auto itr = ingredientMap.begin(); itr != ingredientMap.end(); itr++)
    {
        if (itr->first == name)
            itr->second.stock = stock;
    }
    ingredientMap[name].stock = stock;
    FileSave::saveIngredient(ingredientMap);
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
    if (ingredientMap.count(name) == 0)
	{
		cout << "[ERROR] ���� ����Դϴ�.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "not Exist ingredient name, %s", name);
		Sleep(500);
	}

    ingredientMap.erase(name);
    FileSave::saveIngredient(ingredientMap);
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