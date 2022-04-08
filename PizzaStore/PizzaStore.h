#pragma once
#include <vector>
#include <string>
#include "IngredientStore.h"
#include <map>



enum EN_PizzaMenu
{
    en_Hawaiian = 1,
    en_Cheese,
    en_Combi,
    en_Bulgogi,
    en_Potato,
};



class Pizza
{
    PizzaMenu(const EN_PizzaMenu& name, int price, const std::vector<std::string>& ingredients) :
        Name(name),  Price(price), Ingredients(ingredients) {}

    //PizzaMenu(const EN_PizzaMenu &name,  int price, const std::string ...) {} // :
    //     // 이부분도 가변인자를 쓰게되면 문제가 되는데 문법적 오류를 어떻게 수정해야 할까요??
    //    //Name(name),  Price(price), Ingredients(...) {}

    ~PizzaMenu() {}
    
    std::vector<std::string> getAllIngredients();

private:
    EN_PizzaMenu Name;
    std::vector<std::string> Ingredients;
    int Price;
};


class HawaiianPizza : public Pizza
{
    HawaiianPizza()
    {
        std::vector<std::string> ingredients = { "dough", "cheese" };
        Pizza(en_Hawaiian, 13000, ingredients);
    }

};

class PizzaStore
{
public:
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();
    bool MainUI();
    void tryAgain();
    void ShowPizzaList();
    bool ProcessOrder(EN_PizzaMenu num);

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void pushbackMenu();
    bool accountIngredient(std::string PizzaName);
    
    
    std::vector<PizzaMenu> GetTotalPizza();
    void noStock();

   

    int Money = 100000;

    

    IngredientStore *ingreStore;
    std::vector<PizzaMenu> pizzaMenuVector;
    //std::map<EN_PizzaMenu, std::vector<std::string>> pizzaIngreMap;
    //std::vector<PizzaMenu> pizzaIngreVecotr;

    std::map<std::string, int> pizzaSalesMap;
    //std::map<string, int> ;
    //int totalSales;

};

