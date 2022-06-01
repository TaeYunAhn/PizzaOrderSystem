#include "MainController.h"

MainController::MainController()
{
}

MainController::~MainController()
{
}

bool MainController::run()
{
    LoginController loginController;
    IngredientStore ingredient;
    PizzaStore Pizza(&ingredient);
    CustomerHandler customerHandler;

    while (true)
    {
        std::string userId;
        EN_LOGIN_RESULT res = loginController.login(userId);
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
            customerHandler.HandleCustomer(userId, &Pizza);
            continue;
        }
        case EN_SHUTDOWN: return false;
        default:
            break;
        }
    }
    return true;
}


