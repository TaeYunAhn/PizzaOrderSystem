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
    EN_LOGIN = 1,
    EN_SIGNUP,
    EN_PIZZA_LOGIN,
    EN_INGRE_LOGIN,
    EN_SHUT_DOWN,
};

enum EN_LOGIN_TYPE
{
    CUSTOMER,
    PIZZA,
    INGREDIENT
};

struct Acc
{
    Acc() {}
    Acc(std::string _ID, std::string _PW, EN_LOGIN_TYPE t) : ID(_ID), PW(_PW), type(t) {}
    ~Acc() {}
    std::string ID;
    std::string PW;
    EN_LOGIN_TYPE type;
};


class LoginController
{
public:
    LoginController();
    ~LoginController();
    EN_LOGIN_RESULT login(std::string& __id);
    EN_LOGIN_RESULT PizzaLogin();
    EN_LOGIN_RESULT IngreLogin();
   
private:

    EN_LOGIN_RESULT Login(std::string& id, EN_LOGIN_TYPE type);
    bool Signup();
    

    void LoginAlarm(EN_Alarm error);
    bool retry();
    
    //std::vector<Acc> _GenAcc;
    //std::vector<Acc> _ManagerAcc;
    std::vector<Acc> accounts;

};

