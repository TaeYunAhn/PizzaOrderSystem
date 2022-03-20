#pragma once
#include <vector>
#include <string>


struct PizzaMenu
{
    PizzaMenu(const std::string &name, const std::string &Ing, int price, int sales) : 
                Name(name), Price(price), Ingredients(Ing), Sales(sales) {}
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
    ~PizzaStore();
    void MainUI();

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void tryAgain();

    std::vector<PizzaMenu> _pizzaMenu;
    //std::map<string, int> ;
    //int totalSales;

};

