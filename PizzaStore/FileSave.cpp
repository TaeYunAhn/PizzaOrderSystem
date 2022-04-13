#include "FileSave.h"
#include <fstream>
#include <iostream>
using namespace std;

bool FileSave::readIngredient(std::vector<ingredient>& ingredientVector)
{
    FILE* fd = fopen("IngredientStore.csv", "r");
    
    if (!fd )
       return false;
    
    char line[512];
    char *pLine;
    while ( !feof(fd) )
    {
        pLine = fgets(line, 512, fd);
        if(!pLine )
            continue;
    
      std::string name;
      int price;
      int stock;
    
        char *ptr = strtok(pLine, ",");
        name = ptr;
     
        
        ptr = strtok(NULL, ",");
        if (!ptr )  continue;
        else price = atoi(ptr);
    
        
        ptr = strtok(NULL, ",");
        if (!ptr )  continue;
        else stock = atoi(ptr);
        
        if ( !name.empty() && !price && !stock )
        {
            ingredient a(name, price, stock);
            ingredientVector.push_back(a);
        }
    }
    fclose(fd);

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
bool FileSave::saveIngredient(const std::vector<ingredient>& ingredientVector)
{
    FILE* fd = fopen("IngredientStore.csv", "w");
    
    if (!fd )
        return false;
    
    char num1[256];
    memset(num1, 0, sizeof(num1));
    
    for ( int i = 0; i < ingredientVector.size(); i++ )
    {
        sprintf(num1, "%s,%d,%d\n", ingredientVector[i].Name.c_str(), ingredientVector[i].Price, ingredientVector[i].Stock);
        //fputs((ingredientVector[i].Name + "," + itoa(ingredientVector[i].Price, num1, 10)+ "," + itoa(ingredientVector[i].Stock, num2, 10) + "\n").c_str(), fd);
        fputs(num1, fd);
    }
    
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





