#pragma once
#include "IngredientStore.h"
#include "LoginController.h"
#include "Customer.h"
#include "PizzaDef.h"


class FileSave
{
public:
    static bool readIngredient(std::map<Ingredient, int>& ingredientStockMap);
    static bool saveIngredient(const std::map<Ingredient, int>& ingredientStockMap);

    static bool readLoginData(std::vector<Acc>& GenAcc);
    static bool saveLoginData(const std::vector<Acc>& GenAcc);

    static bool readAccountInfo(std::vector<Info>& accountsInfo);
    static bool saveAccountInfo(const std::vector<Info>& accountsInfo);

    static bool readOrderList(std::map<enPizzaMenu, int>& pizzaCount);
    static bool saveOrderList(const std::map<enPizzaMenu, int>& pizzaCount);
    // 
    
};

