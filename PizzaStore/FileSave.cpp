#include "FileSave.h"
#include <fstream>
#include <iostream>
using namespace std;

bool FileSave::readIngredient(std::map<Ingredient, int>& ingredientStockMap)
{
    ingredientStockMap.clear();
    FILE* fd = fopen("IngredientStore.csv", "r");

    if (!fd)
        return false;

    char line[512];
    char* pLine;
    while (!feof(fd))
    {
        pLine = fgets(line, 512, fd);
        if (!pLine)
            continue;

        Ingredient ingre;
        int stock = 0;

        char* ptr = strtok(pLine, ",");
        ingre.name = ptr;

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else ingre.price = atoi(ptr);

        ptr = strtok(NULL, ",");
        if (!ptr)  continue;
        else stock = atoi(ptr);

        ingredientStockMap[ingre] = stock;

    }
    fclose(fd);
    return true;
}

bool FileSave::saveIngredient(const std::map<Ingredient, int>& ingredientStockMap)
{
    FILE* fd = fopen("IngredientStore.csv", "w");

    if (!fd)
        return false;

    char num1[256];
    memset(num1, 0, sizeof(num1));

    for (pair<Ingredient, int> m : ingredientStockMap)
    {
        sprintf(num1, "%s,%d,%d\n", m.first.name.c_str(), m.first.price, m.second);
        fputs(num1, fd);
    }

    fclose(fd);
    return true;
}





