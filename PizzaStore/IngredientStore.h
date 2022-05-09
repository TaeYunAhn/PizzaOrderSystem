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

struct Ingredient
{
    Ingredient() {}
    Ingredient(const std::string &n, int p) : name(n), price(p) {}
    ~Ingredient() {}
    std::string name;
    int price;
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();

    bool RunIngredientStore();
    EN_STOCK_CHECK checkIngredients(std::string ingredients, int cost);
    

private:
    void addIngredient();
    void ShowIngredientList();
    bool writeComponent(std::string &name, int &price, int &stock);
    void modifyIngredient();
    void deleteIngredient();
    void addIngredientStock();

private:
    //std::vector<Ingredient> ingredientVector;
    std::map<Ingredient, int> ingredientStockMap;
    //std::map<string, int> stocks;
};

