#pragma once
#include <vector>
#include <string>
#include "IngredientStore.h"


struct PizzaMenu
{
    PizzaMenu(const std::string &name, const std::string &Ing, int price, int sales) : 
                Name(name),  Ingredients(Ing), Price(price), Sales(sales) {}
    ~PizzaMenu() {}
    std::string Name;
    std::string Ingredients;
    int Price;
    int Sales;
    
};

class PizzaStore
{
public:
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();
    void MainUI();

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void tryAgain();
    void ShowPizzaList();
    std::vector<PizzaMenu> GetTotalPizza();

    IngredientStore *ingreStore;
    std::vector<PizzaMenu> pizzaMenuVector;
    //std::map<string, int> ;
    //int totalSales;

};

