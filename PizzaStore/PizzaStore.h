#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <array>
#include "IngredientStore.h"
#include "PizzaDef.h"

class Pizza;
class PizzaStore
{
public: 
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();

    void runPizzaStore();
    void ShowPizzaList();
    bool ProcessOrder(enPizzaMenu menu, Pizza*& pizza, std::string& Ingredient);

private:
    Pizza* makePizza(enPizzaMenu menu);
    int balance = 100000;

    IngredientStore *ingreStore;
    std::map<enPizzaMenu, int> pizzaSalesMap;
};

