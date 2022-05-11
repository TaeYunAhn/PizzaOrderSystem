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
    bool RunPizzaStore();
    void tryAgain();
    void ShowPizzaList();
    bool ProcessOrder(EN_PizzaMenu menu/*, Pizza* out*/);
    EN_PizzaMenu getingreList(EN_PizzaMenu menu);

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void pushbackMenu();
    bool accountIngredient(std::string PizzaName);

    Pizza* makePizza(EN_PizzaMenu menu);
    
    std::vector<EN_PizzaMenu> GetTotalPizza();
    void noStock();

    int Money = 100000;

    IngredientStore *ingreStore;
    //std::vector<EN_PizzaMenu> pizzaMenuVector;
    //std::map<EN_PizzaMenu, std::vector<std::string>> pizzaIngreMap;
    //std::vector<PizzaMenu> pizzaIngreVecotr;

    std::map<EN_PizzaMenu, int> pizzaSalesMap;
    //std::array<std::vector<std::string>, en_TotalNum - 1> ingreList;
    //std::map<string, int>;
    //int totalSales;

};

