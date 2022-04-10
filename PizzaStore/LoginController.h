#pragma once
#include <string>
#include <vector>


enum EN_Alarm
{
    EN_SIGNUP_SUCCESS,
    EN_LOGIN_SUCCESS,
    EN_EXIST_ALREADY,
    EN_NOT_EXIST_ACC,
    EN_WRONG_PW,
};

enum EN_Login_Result
{

    EN_PIZZA_STORE_LOGIN_SUCCESS,
    EN_INGREDIENT_STORE_LOGIN_SUCCESS,
    EN_CUSTOMER_LOGIN_SUCCESS,
};

enum EN_LOGIN_TYPE
{
    EN_PIZZA_STORE_SUC,
    EN_INGREDIENT_SUC,
    EN_CUSTOMER_SUC,
    EN_PW_FAIL,
    EN_NO_EXIST_ACC,
    EN_SHUTDOWN,
};

enum EN_LOGIN_MAIN_SEL
{
    EN_LOGIN = 1,
    EN_SIGNUP,
    EN_PIZZA_LOGIN,
    EN_INGRE_LOGIN,
    EN_SHUTDOWN,
};

struct Acc
{
    Acc() {}
    Acc(std::string _ID, std::string _PW) : ID(_ID), PW(_PW) {}
    ~Acc() {}
    std::string ID;
    std::string PW;
};


class LoginController
{
public:
    LoginController();
    ~LoginController();
    //EN_LOGIN_TYPE MainUI();
    EN_LOGIN_TYPE Login();
private:

    EN_LOGIN_TYPE GeneralLogin();
    EN_LOGIN_TYPE Signup();
    //EN_Login_Success PartnerLogin();
    EN_LOGIN_TYPE PizzaLogin();
    EN_LOGIN_TYPE IngreLogin();
    EN_LOGIN_TYPE ShutDown();

    void tryAgain();
    void LoginAlarm(EN_Alarm error);
    
    std::vector<Acc> _GenAcc;
    std::vector<Acc> _ParAcc;

};

