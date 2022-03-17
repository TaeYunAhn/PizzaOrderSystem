#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ingredient
{
    ingredient(string name, int price, int stock) : Name(name), Price(price), Stock(stock) {}
    ~ingredient() {}
    string Name;
    int Price;
    int Stock;
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();
    vector<ingredient> GetIngredientList();
    void ShowIngredientList();
    void SelectMenu();
    bool addMenu(const string &name, const int &price, const int &stock);

private:
    vector<ingredient> ingredientVector;
};

