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
    Customer customer(&Pizza);
    CustomerHandler cHandler;

    while (true)
    {
        EN_LOGIN_RESULT res = loginController.login(id);
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
            cHandler.run(id);
            //customer.runCustomer(id/*, info.balance*/);
            continue;
        }
        case EN_SHUTDOWN: return false;
        default:
            break;
        }
    }
    return true;
}


