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

struct ingredient
{
    ingredient(const std::string &name, int price, int stock) : Name(name), Price(price) {}
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
    bool checkIngredients(vector<string> ingredients, int cost);
    

private:
    void addIngredient();
    void ShowIngredientList();
    bool writeComponent(std::string &name, int &price, int &stock);
    void modifyIngredient();
    void deleteIngredient();

private:
    std::vector<ingredient> ingredientVector;
    std::map<ingredient, int> ingredientMap;
    //std::map<string, int> stocks;
};

