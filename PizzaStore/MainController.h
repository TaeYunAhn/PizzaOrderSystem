#pragma once
#include "LoginController.h"
#include "IngredientStore.h"
#include "PizzaStore.h"
#include "Customer.h"

class MainController
{
public:
    MainController();
    ~MainController();
    bool run();

    void init();

private:
    LoginController loginController;
    IngredientStore ingredient;
    PizzaStore Pizza;
};

