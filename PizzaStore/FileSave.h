#pragma once
#include "IngredientStore.h"
#include "LoginController.h"
#include "Customer.h"
#include "PizzaDef.h"

const std::string DATA_SOURCE_PATH = "C:\\PSData\\info";

struct CustomerInfo;
class FileSave
{
public:
    static bool readIngredient(std::map<Ingredient, int>& ingredientStockMap);
    static bool saveIngredient(const std::map<Ingredient, int>& ingredientStockMap);

    static bool readLoginData(std::vector<AccInfo>& GenAcc);
    static bool saveLoginData(const std::vector<AccInfo>& GenAcc);

    static bool readAccountInfo(std::vector<CustomerInfo>& accountsInfoData);
    static bool saveAccountInfo(const std::vector<CustomerInfo>& accountsInfoData);

    static bool readOrderList(std::map<std::string, std::vector<AccountwithPizza>>& orderList);
    static bool saveOrderList(const std::map<std::string, std::vector<AccountwithPizza>>& orderList);
};

