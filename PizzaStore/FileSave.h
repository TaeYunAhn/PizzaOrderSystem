#pragma once
#include "IngredientStore.h"
#include "LoginController.h"


class FileSave
{
public:
    static bool readIngredient(std::map<Ingredient, int>& ingredientStockMap);
    static bool saveIngredient(const std::map<Ingredient, int>& ingredientStockMap);

    static bool readLoginData(std::vector<Acc>& GenAcc);
    static bool saveLoginData(const std::vector<Acc>& GenAcc);

    static bool readAccountInfo(std::vector<Info>& accountsInfo);
    static bool saveAccountInfo(const std::vector<Info>& accountsInfo);
};

