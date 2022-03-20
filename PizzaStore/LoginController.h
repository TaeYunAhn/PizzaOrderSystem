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

struct GenAcc
{
    GenAcc() {}
    GenAcc(std::string _ID, std::string _PW) : ID(_ID), PW(_PW) {}
    ~GenAcc() {}
    std::string ID;
    std::string PW;
};

struct ParAcc
{
    ParAcc() {}
    ParAcc(std::string _ID, std::string _PW) : ID(_ID), PW(_PW) {}
    ~ParAcc() {}
    std::string ID;
    std::string PW;
};

class LoginController
{
public:
    LoginController();
    ~LoginController();
    void MainUI();

private:

    void GeneralLogin();
    void Signup();
    void PartnerLogin();
    void tryAgain();
    void LoginAlarm(EN_Alarm error);
    
    std::vector<GenAcc> _GenAcc;
    std::vector<ParAcc> _ParAcc;

};

