#include "Customer.h"
#include "CustomerHandler.h"
#include "DBConnector.h"
#include "MainController.h"
#include "Logger.h"

MainController::MainController()
{
}

MainController::~MainController()
{
}

bool MainController::run()
{
    if (!DBConnector::getInstance()->connectDB())
    {
        std::cout << "Failed to connect db" << std::endl;
        
        CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Failed to connect db");

        return false;
    }

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
            customerHandler.handleCustomer(userId, &Pizza);
            break;
        case EN_SHUTDOWN: return false;
        default:
            break;
        }
    }
    return true;
}


