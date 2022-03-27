#include "IngredientStore.h"
#include "LoginController.h"
#include "Logger.h"
#include "PizzaStore.h"

int main()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Main Start");
    while (true)
    {
        int res;
        LoginController login;
        res = login.MainUI();

        if (res == EN_PIZZA_STORE_LOGIN_SUCCESS || res == EN_INGREDIENT_STORE_LOGIN_SUCCESS)
        {
            IngredientStore ingredient;
            PizzaStore pizza(&ingredient);
            if (res == EN_PIZZA_STORE_LOGIN_SUCCESS)
                pizza.MainUI();
            else if (res == EN_INGREDIENT_STORE_LOGIN_SUCCESS)
                ingredient.SelectMenu();
        }

        
    }
    
    


    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Main End");


    //IngredientStore ingre;
    //ingre.SelectMenu();

    //PizzaStore a;
    //a.MainUI();



    //PizzaStore p;
    //p.getIngFromIngStore(TYPE_GORGONZOLA, ingre);
}

//getIngFromIngStore()
//{
//    ingre.giveIng(EN_CHEESE);
//    
//}


