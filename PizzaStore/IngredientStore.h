#pragma once
#include <vector>
#include <string>

enum EN_RESULT
{
    enSuccess,
    enNoIng,
    enNoStock,
};

struct ingredient
{
    ingredient(const std::string &name, int price, int stock) : Name(name), Price(price), Stock(stock) {}
    ~ingredient() {}
    std::string Name;
    int Price;
    int Stock;
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();

    void SelectMenu();

private:
    std::vector<ingredient>& GetIngredientList();
    void addIngredient();
    void ShowIngredientList();
    bool writeComponent(std::string &name, int &price, int &stock);
    void modifyIngredient();
    void deleteIngredient();

private:
    std::vector<ingredient> ingredientVector;
};

