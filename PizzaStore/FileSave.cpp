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

        /*if (!name.empty())
        {
            Ingredient a(name, price);
            ingredientVector.push_back(a);
        }*/
    }
    fclose(fd);
    return true;

    //read File

   //string filePath = "IngredientStore.csv";
   //ifstream openFile(filePath.data());
   //if( openFile.is_open() )
   //{
   //    string line;    
   //    getline(openFile, line);
   //    line.c_str();
   //    char *ptr = strtok(line, ",");
   //    name = ptr;
   //
   //
   //    openFile.close();
   //    return true;
   //}
   //return false;



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

    //for (int i = ; i < ingredientStockMap.size(); i++)
    //{
    //    Ingredient ingre;
    //    sprintf(num1, "%s,%d,%d\n", ingredientVector[i].name.c_str(), ingredientVector[i].price);
    //    //fputs((ingredientVector[i].Name + "," + itoa(ingredientVector[i].Price, num1, 10)+ "," + itoa(ingredientVector[i].Stock, num2, 10) + "\n").c_str(), fd);
    //    fputs(num1, fd);
    //}

    fclose(fd);
    return true;

    //string filePath = "IngredientStore.csv";

   // // write File
   // ofstream writeFile(filePath.data());
   // if( writeFile.is_open() )
   // {
   //     for ( int i = 0; i < ingredientVector.size(); i++ )
   //     {
   //
   //         writeFile << ingredientVector[i].Name;
   //         writeFile << ",";
   //         writeFile << ingredientVector[i].Price;
   //         writeFile << ",";
   //         writeFile << ingredientVector[i].Stock;
   //         
   //         writeFile.close();
   //     }
   //     return true;
   // }
   // else
   //     return false;



}





