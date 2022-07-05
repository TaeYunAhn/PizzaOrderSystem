#pragma once
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

struct IngredientInfo
{
<<<<<<< HEAD
    Ingredient ingredient;
    int stock;

    IngredientInfo() {}
    IngredientInfo(const Ingredient& ing, const int st) : ingredient(ing), stock(st) {}
=======
	Ingredient ingredient;
	int stock;

	IngredientInfo() {}
	IngredientInfo(const Ingredient& ing, const int st) : ingredient(ing), stock(st) {}
>>>>>>> 9c097001d049a3154d68183a4b053da6c3345866
};

class IngredientStore
{
public:
    IngredientStore();
    ~IngredientStore();

    bool runIngredientStore();
	EN_STOCK_CHECK checkIngredients(const std::pair<std::string, unsigned int>& pairIngre, std::string &emptyIngredient, int &cost);
	bool grepIngredients(const std::pair<std::string, unsigned int>& pairIngre);
    

private:
    void addIngredient();
    void ShowIngredientList();
    void modifyIngredientPrice();
    void modifyIngredientStock();
    void deleteIngredient();

private:
<<<<<<< HEAD
    std::map<std::string, IngredientInfo> ingredientMap;
=======
	//std::map<Ingredient, int> ingredientStockMap;
	std::map<std::string, IngredientInfo> ingredientMap;
	

>>>>>>> 9c097001d049a3154d68183a4b053da6c3345866
    //std::map<std::string, std::pair<Ingredient, int>> ingredientStockMap;
};

