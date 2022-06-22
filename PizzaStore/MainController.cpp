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
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Pizza Store Login Success");
            Pizza.runPizzaStore();
			break;
        case EN_INGREDIENT_SUC:
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Ingredient Store Login Success");
            ingredient.runIngredientStore();
			break;
        case EN_CUSTOMER_SUC:
        {   
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Customer Login Success");
            cHandler.run(id);
            continue;
        }
        case EN_SHUTDOWN: 
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Shutdown Main Controller"); 
            return false;
        default:
            break;
        }
    }
    return true;
}


