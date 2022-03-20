#pragma once
#include <vector>
#include "IngredientStore.h"

class FileSave
{
public:
    static bool readIngredient(std::vector<ingredient>& ingredientVector);
    static bool saveIngredient(const std::vector<ingredient>& ingredientVector);

};

