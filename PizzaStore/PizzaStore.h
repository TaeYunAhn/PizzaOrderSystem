#pragma once
#include <vector>
#include <string>
#include "IngredientStore.h"
#include <map>


enum EN_PizzaMenu
{
    en_Hawaiian = 1,
    en_Cheese,
    en_combi,
    en_Bulgogi,
    en_Potato,
};


struct PizzaMenu
{
    PizzaMenu(const std::string &name, const std::string &Ing, int price) : 
                Name(name), Ingredients(Ing), Price(price) {}
    ~PizzaMenu() {}
    std::string Name;
    std::string Ingredients;
    int Price;
};

class PizzaStore
{
public:
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();
    bool MainUI();

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void tryAgain();
    void ShowPizzaList();
    std::vector<PizzaMenu> GetTotalPizza();
    void noStock();

    bool ProcessOrder(EN_PizzaMenu num);

    int Money = 100000;

    

    IngredientStore *ingreStore;
    std::vector<PizzaMenu> pizzaMenuVector;
    std::map<std::string, int> pizzaSalesMap;
    //std::map<string, int> ;
    //int totalSales;

};

