#include <Windows.h>
#include <array>
#include "Logger.h"
#include "PizzaStore.h"
#include "Pizza.h"
using namespace std;


PizzaStore::PizzaStore()
{
    // 파일에 돈 얼마 가지고 있는지 저장해두고 피자 클래스 할당 하면 읽어옴
    //pushbackMenu();
}

PizzaStore::~PizzaStore()
{
}

PizzaStore::PizzaStore(IngredientStore *ingre)
{
     ingreStore = ingre;
}

void PizzaStore::runPizzaStore()
{
    while ( true )
    {
		system("cls");
        int res = 0;
        cout << "  << 피자가게 >>  "<<endl;
        cout << "1. 메뉴 생성"<<endl;
        cout << "2. 메뉴 수정"<<endl;
        cout << "3. 메뉴 삭제"<<endl;
		cout << "4. 메뉴 조회" << endl;
        cout << "5. 이전 메뉴"<<endl;
        cout << "선택 : ";
        cin >> res;

		switch (res)
		{
		case 1:
		case 2:
		case 3:
			cout << "준비중입니다." << endl;
			Sleep(500);
			break;
		case 4:
			ShowPizzaList();
			break;
		case 5:
			return;
		default:
			cout << "잘못된 선택입니다. 다시 시도해 주세요" << endl;
			Sleep(500);
			break;
		}
    }
}

void PizzaStore::ShowPizzaList()
{
    array<string, PIZZA_TOTAL> pizzaName = { "", "hawaiian", "cheese", "combi", "bulgogi", "potato" };
    for (int i = 1; i < PIZZA_TOTAL; i++)
    {
        cout << i << ". " << pizzaName[i]<< endl;
    }
}

Pizza* PizzaStore::makePizza(enPizzaMenu menu)
{
    switch (menu)
    {
    case HAWAIIAN_PIZZA: return new HawaiianPizza;
    case CHEESE_PIZZA: return new CheesePizza;
    case COMBINATION_PIZZA: return new CombiPizza;
    case BULGOGI_PIZZA: return new BulgogiPizza;
    case POTATO_PIZZA: return new PotatoPizza;
    default:
		cout << "잘못된 선택입니다." << endl;
		return nullptr;
    }
}


bool PizzaStore::ProcessOrder(const pair<enPizzaMenu, unsigned int>& menu, Pizza*& outPizza, string& Ingredient)
{
	Ingredient.clear();
    CLogger* logger = CLogger::getInstance();
    logger->write(enInfo, __LINE__, __FUNCTION__, "START, menu: %d", (int)menu.first);
    string emptyIngredient;
    int cost = 0;
    Pizza* pizza = makePizza(menu.first);

	bool bFailed = false;
    for (const auto& strIngredient : pizza->getIngredients())
    {
		int partialCost = 0;
		if (!ingreStore->checkIngredients(make_pair(strIngredient, menu.second), emptyIngredient, partialCost))
        {
            Ingredient += Ingredient.empty() ? emptyIngredient : (", " + emptyIngredient);
			bFailed = true;
			continue;
        }
        
		cost += partialCost;
		logger->write(enInfo, __LINE__, __FUNCTION__, "Pizza type: %d, ingre_name: %s", (int)menu.first, strIngredient.c_str());
    }
    
	if (bFailed)
	{
		logger->write(enError, __LINE__, __FUNCTION__, "Failed to check Ingredients(%s)", Ingredient.c_str());
		return false;
	}

	if (balance < cost)
	{
		logger->write(enError, __LINE__, __FUNCTION__, "not enough pizza store's money(balance = %d, cost = %d)", balance, cost);
		return false;
	}

	// CHECKING INGREDIENT IS SUCCESS
	for (const auto& strIngredient : pizza->getIngredients())
	{
		ingreStore->grepIngredients(make_pair(strIngredient, menu.second));
		logger->write(enInfo, __LINE__, __FUNCTION__, "Pizza type: %d, ingre_name: %s", (int)menu.first, strIngredient.c_str());
	}

    logger->write(enInfo, __LINE__, __FUNCTION__, "Total cost: %d", cost);

    balance -= cost;
    balance += pizza->getPrice();

    logger->write(enInfo, __LINE__, __FUNCTION__, "balance: %d", balance);

    auto itr = pizzaSalesMap.find(menu.first);
    if (itr == pizzaSalesMap.end())
    {
        pizzaSalesMap.insert(make_pair(menu.first, pizza->getPrice()));
    }
    else
    {
       itr->second += ( pizza->getPrice() * menu.second );
    }

    logger->write(enInfo, __LINE__, __FUNCTION__, "Pizza Sales(%d, %d)", (int)menu.first, pizzaSalesMap[menu.first]);
    pizzaSalesMap[menu.first] += pizza->getPrice();
    logger->write(enInfo, __LINE__, __FUNCTION__, "END");
    outPizza = pizza;
    return true;
}

//int bb = 10;
//
//void a(int* val)
//{
//    val = &bb;
//}
//
//int aa = 4;
//a(&aa);
//aa

