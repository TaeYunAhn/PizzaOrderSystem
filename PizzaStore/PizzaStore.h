#pragma once
#include <vector>
#include <string>
#include "IngredientStore.h"
#include <map>
#include <iostream>



enum EN_PizzaMenu
{
    en_Hawaiian = 1,
    en_Cheese,
    en_Combi,
    en_Bulgogi,
    en_Potato,
};



//class Pizza 
//{
//public:
//    Pizza(const EN_PizzaMenu& name, int price, const std::vector<std::string>& ingredients) :
//        Name(name), Price(price), Ingredients(ingredients) {}
//
//    
//
//    ~Pizza() {}
//    
//    std::vector<std::string> getAllIngredients();
//    void showInfo()
//    {
//        std::cout << "이름: " << Name << std::endl;
//        std::cout << "재료: " << Ingredients << std::endl;
//        std::cout << "가격: " << Price << std::endl;
//    }
//
//
//
//private:
//    EN_PizzaMenu Name;
//    std::vector<std::string> Ingredients;
//    int Price;
//};

//class Hawaiian : public Pizza
//{
//private:
//    string name;
//    string ingredient;
//    int price;
//public:
//    Hawaiian(std::string _name, std::string _ingredient, int _price) : name(_name), ingredient(_ingredient), price(_price) {}
//    //Pizza(string _name, string _ingredient, int _price) : Hawaiian(_name, _ingredient, _price) {}
//    
//
//};


/*class HawaiianPizza : public PizzaMenu
{
    HawaiianPizza()
    {
        std::vector<std::string> ingredients = { "dough", "cheese" };
        PizzaMenu(en_Hawaiian, 13000, ingredients);
    }

};*/

class PizzaStore
{
public:
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();
    bool RunPizzaStore();
    void tryAgain();
    void ShowPizzaList();
    bool ProcessOrder(EN_PizzaMenu menu);

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void pushbackMenu();
    bool accountIngredient(std::string PizzaName);
    
    
    std::vector<EN_PizzaMenu> GetTotalPizza();
    void noStock();

   

    int Money = 100000;

    

    IngredientStore *ingreStore;
    std::vector<EN_PizzaMenu> pizzaMenuVector;
    //std::map<EN_PizzaMenu, std::vector<std::string>> pizzaIngreMap;
    //std::vector<PizzaMenu> pizzaIngreVecotr;

    std::map<std::string, int> pizzaSalesMap;
    //std::map<string, int> ;
    //int totalSales;

};

