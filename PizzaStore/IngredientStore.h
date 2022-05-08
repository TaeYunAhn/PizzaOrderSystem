#pragma once
#include <vector>
#include <string>
#include <map>
#include "PizzaDef.h"

enum EN_RESULT
{
    enSuccess,
    enNoIng,
    enNoStock,
};

enum EN_STOCK_CHECK
{
    en_NotEnough,
    en_Confirm,
    en_WrongIngreName,
};

struct ingredient
{
    ingredient(const std::string &name, int price) : Name(name), Price(price) {}
    ~ingredient() {}
    std::string Name;
    int Price;
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();

    bool RunIngredientStore();
    std::vector<ingredient>& GetIngredientList();
    EN_STOCK_CHECK checkIngredients(vector<string> ingredients, int cost);
    

private:
    void addIngredient();
    void ShowIngredientList();
    bool writeComponent(std::string &name, int &price, int &stock);
    void modifyIngredient();
    void deleteIngredient();
    void addIngredientStock();

private:
    std::vector<ingredient> ingredientVector;
    std::map<ingredient, int> ingredientStockMap;
    //std::map<string, int> stocks;
};

