#include "MainController.h"


//class A {
//public:
//    A(int a) {}
//};
//
//class B : public A
//{
//    B() : A(3)
//    {
//        //A(3);
//    }
//};
// C++ 클래스 이니셜라이져 & ㅊ++ 상속 생성자 & 디폴트 생성자

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
        EN_LOGIN_TYPE res = loginController.Login(id);
        switch (res)
        {
        case EN_PIZZA_STORE_SUC:
        {
            system("cls");
            Pizza.RunPizzaStore();
            continue;
        }
        case EN_INGREDIENT_SUC:
        {
            system("cls");
            ingredient.RunIngredientStore();
            continue;
        }
        case EN_CUSTOMER_SUC:
        {   
            system("cls");
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


