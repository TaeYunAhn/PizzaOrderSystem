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
    LoginController loginController;
    int res = loginController.login();

    switch (res)
    {
    case EN_PIZZA_STORE_LOGIN_SUCCESS:
    {
        IngredientStore ingredient;
        PizzaStore pizza(&ingredient);
        pizza.MainUI();
    }
    case EN_INGREDIENT_STORE_LOGIN_SUCCESS:
    {
        IngredientStore ingredient;
        ingredient.SelectMenu();
    }
    case EN_CUSTOMER_LOGIN_SUCCESS:
    {
        IngredientStore ingredient;
        PizzaStore pizza(&ingredient);
        Customer customer(pizza);
        customer.start();
    }
    break;
    default:
        // error
        break;
    }

    IngredientStore ingredient;
    PizzaStore pizza(&ingredient);

    if (res == EN_PIZZA_STORE_LOGIN_SUCCESS || res == EN_INGREDIENT_STORE_LOGIN_SUCCESS)
    {
        IngredientStore ingredient;
        PizzaStore pizza(&ingredient);
        if (res == EN_PIZZA_STORE_LOGIN_SUCCESS)
            pizza.MainUI();
        else if (res == EN_INGREDIENT_STORE_LOGIN_SUCCESS)
            ingredient.SelectMenu();
    }
    else if (res == EN_CUSTOMER_LOGIN_SUCCESS)
    {

        Customer c();
    }
    else
    {

    }
}


