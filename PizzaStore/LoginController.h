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

enum EN_LOGIN_RESULT
{
    EN_PIZZA_STORE_SUC,
    EN_INGREDIENT_SUC,
    EN_CUSTOMER_SUC,
    EN_SIGNUP_SUC,
    EN_PW_FAIL,
    EN_NO_EXIST_ACC,
    EN_SHUTDOWN,
};

enum EN_LOGIN_MAIN_SEL
{
    EN_SIGNUP = 1,
    EN_CUSTOMER_LOGIN,
    EN_PIZZA_LOGIN,
    EN_INGRE_LOGIN,
    EN_SHUT_DOWN,
};

enum EN_LOGIN_TYPE
{
    CUSTOMER,
    PIZZA,
    INGREDIENT,
};

struct AccInfo
{
    AccInfo() {}
    AccInfo(std::string _ID, std::string _PW, EN_LOGIN_TYPE t, int b = 0) : accID(_ID), accPW(_PW), loginType(t), balance(b) {}
    ~AccInfo() {}
    std::string accID;
    std::string accPW;
    EN_LOGIN_TYPE loginType;
    int balance;
};

class LoginController
{
public:
    LoginController();
    ~LoginController();
    EN_LOGIN_RESULT login(std::string& __id);
    //EN_LOGIN_RESULT PizzaLogin();
    //EN_LOGIN_RESULT IngreLogin();
   
private:

    EN_LOGIN_RESULT Login(std::string& id, EN_LOGIN_TYPE type);
    bool Signup();
    

    void LoginAlarm(EN_Alarm error);
    bool retry();
    
    std::vector<AccInfo> accounts;
};

