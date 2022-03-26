#include "IngredientStore.h"
#include "LoginController.h"
#include "Logger.h"
#include "PizzaStore.h"

int main()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Main Start");

    LoginController login;
    login.MainUI();

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


