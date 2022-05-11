#include "MainController.h"

MainController::MainController()
{
}

MainController::~MainController()
{
}

bool MainController::run()
{
    std::string id;
    LoginController loginController;
    IngredientStore ingredient;
    PizzaStore Pizza(&ingredient);

    while (true)
    {
        EN_LOGIN_TYPE res = loginController.login(id);
        switch (res)
        {
        case EN_PIZZA_STORE_SUC:
            Pizza.runPizzaStore();
			break;
        case EN_INGREDIENT_SUC:
            ingredient.runIngredientStore();
			break;
        case EN_CUSTOMER_SUC:
        {   
            Customer customer(&Pizza);
            customer.runCustomer(id);
            continue;
        }
        case EN_SHUTDOWN: return false;
        default:
            break;
        }
    }
    return true;
}


