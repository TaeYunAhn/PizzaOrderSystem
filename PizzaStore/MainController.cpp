#include "MainController.h"
#include "LoginController.h"
#include "IngredientStore.h"
#include "PizzaStore.h"
#include "Customer.h"



MainController::MainController()
{

}

MainController::~MainController()
{

}


bool MainController::run()
{
    while (true)
    {
        std::string id;
        LoginController loginController;
        EN_LOGIN_TYPE res = loginController.Login(id);

        switch (res)
        {
        case EN_PIZZA_STORE_SUC:
        {
            system("cls");
            IngredientStore ingredient;
            PizzaStore pizza(&ingredient);
            pizza.RunPizzaStore();
            continue;
        }
        case EN_INGREDIENT_SUC:
        {
            system("cls");
            IngredientStore ingredient;
            ingredient.RunIngredientStore();
            continue;
        }
        case EN_CUSTOMER_SUC:
        {   
            
            system("cls");
            IngredientStore ingredient;
            PizzaStore Pizza(&ingredient);
            Customer customer(&Pizza);
            customer.RunCustomer(id);
            continue;
        }
        //case EN_SIGNUP_SUC:
           
        case EN_SHUTDOWN: return false;
        default:
            // error
            break;
        }
        
    }
    return true;

    
}


