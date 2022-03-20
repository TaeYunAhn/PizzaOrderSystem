#include "FileSave.h"

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
    }
    fclose(fd);



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
        fputs(num1, stdin);
    }

    fclose(fd);
    return true;
}
