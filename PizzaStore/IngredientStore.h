#pragma once
#include <vector>
#include <string>
#include <map>

enum EN_RESULT
{
    SUCCESS,
    NO_INGREDIENT,
    NO_STOCK,
};

enum EN_STOCK_CHECK
{
    NOT_ENOUGH,
    CONFIRM,
    WRONG_NAME,
};

struct Ingredient
{
    Ingredient() {}
    Ingredient(const std::string &n, int p) : name(n), price(p) {}
    ~Ingredient() {}
    std::string name;
    int price;

    bool operator<(const Ingredient& rhs) const
    {
        return name < rhs.name;
    }
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();

    bool runIngredientStore();
    EN_STOCK_CHECK checkIngredients(std::string ingredients, int &cost);
    

private:
    void addIngredient();
    void ShowIngredientList();
    void modifyIngredient();
    void deleteIngredient();

private:
    std::map<Ingredient, int> ingredientStockMap;
    //std::map<std::string, std::pair<Ingredient, int>> ingredientStockMap;
};

