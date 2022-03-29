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

enum EN_Login_Success
{
    EN_PIZZA_STORE_LOGIN_SUCCESS,
    EN_INGREDIENT_STORE_LOGIN_SUCCESS,
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
    EN_Login_Success MainUI();

private:

    void GeneralLogin();
    void Signup();
    EN_Login_Success PartnerLogin();

    void tryAgain();
    void LoginAlarm(EN_Alarm error);
    
    std::vector<Acc> _GenAcc;
    std::vector<Acc> _ParAcc;

};

