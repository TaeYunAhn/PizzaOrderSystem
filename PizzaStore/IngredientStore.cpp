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
		cout << "재료 정보를 가져오는데 실패했습니다." << endl;
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
    cout << "----재료 리스트---- " << endl;
    for (map<Ingredient, int>::iterator itr = ingredientStockMap.begin(); itr != ingredientStockMap.end(); itr++)
        cout << "이름 : " << itr->first.name << ", " << "가격 : " << itr->first.price << ", " << "재고 : " << itr->second << endl;
}

void IngredientStore::addIngredient()
{
    system("cls");
	cout << "  < 재료 추가 >  " << endl;
    string name;
    int price = 0;
    int stock = 0;
	cout << "재료 이름 : ";
	cin >> name;
	cout << "재료 가격 : ";
	cin >> price;
	cout << "재고 갯수 : ";
	cin >> stock;

	Ingredient ingredient(name, price);
	if (ingredientStockMap.count(ingredient) > 0)
	{
		cout << "[ERROR] 이미 있는 재료입니다.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "allready Exist ingredient name, %s", name);
		Sleep(500);
		return;
	}

    ingredientStockMap[ingredient] = stock;
    FileSave::saveIngredient(ingredientStockMap);
    cout << "추가 되었습니다." << endl << endl;
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Add ingredient, %s, %d, %d", name, price, stock);
    Sleep(500);
}

void IngredientStore::modifyIngredient()
{
	system("cls");
	cout << "  < 재료 수정 >  " << endl;
	string name;
	int price = 0;
	int stock = 0;
	cout << "재료 이름 : ";
	cin >> name;
	cout << "재료 가격 : ";
	cin >> price;
	cout << "재고 갯수 : ";
	cin >> stock;

	Ingredient ingredient(name, price);
	if (ingredientStockMap.count(ingredient) == 0)
	{
		cout << "[ERROR] 없는 재료입니다.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Not Exist ingredient name, %s", name);
		Sleep(500);
		return;
	}

    ingredientStockMap[ingredient] = stock;
    FileSave::saveIngredient(ingredientStockMap);
	cout << "수정 되었습니다." << endl << endl;
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Fix ingredient, %s, %d, %d", name, price, stock);
	Sleep(500);
}

void IngredientStore::deleteIngredient()
{
    system("cls");
    cout << "  < 재료 삭제 >  " << endl;
	string name;
    cout << "재료 이름을 입력하세요 : ";
    cin >> name;
	if (ingredientStockMap.count(Ingredient(name, 0)) == 0)
	{
		cout << "[ERROR] 없는 재료입니다.(" + name + ")" << endl;
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "not Exist ingredient name, %s", name);
		Sleep(500);
	}


    ingredientStockMap.erase(Ingredient(name, 0));
    FileSave::saveIngredient(ingredientStockMap);
    cout << "삭제되었습니다." << endl << endl;
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