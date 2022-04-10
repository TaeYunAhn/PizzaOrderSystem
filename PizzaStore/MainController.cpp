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


//EN_PIZZA_STORE_SUC,
//EN_INGREDIENT_SUC,
//EN_CUSTOMER_SUC,
//EN_FAIL,

bool MainController::run()
{
    LoginController loginController;
    int res = loginController.Login();

    switch (res)
    {
    case EN_PIZZA_STORE_SUC:
    {
        IngredientStore ingredient;
        PizzaStore pizza(&ingredient);
        pizza.MainUI();
    }
    case EN_INGREDIENT_SUC:
    {
        IngredientStore ingredient;
        ingredient.SelectMenu();
    }
    case EN_CUSTOMER_SUC:
    {
        IngredientStore ingredient;
        PizzaStore pizza(&ingredient);
        Customer customer(pizza);
        customer.start();
    }
    case EN_SHUTDOWN: return false;
    break;
    default:
        // error
        break;
    }

    
}


