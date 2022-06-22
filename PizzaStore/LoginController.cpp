#include "LoginController.h"
#include "PizzaStore.h"
#include "IngredientStore.h"
#include "Logger.h"
#include "FileSave.h"
#include "Logger.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;


LoginController::LoginController()
{
    FileSave::readLoginData(accounts);
}

LoginController::~LoginController()
{
    
}

EN_LOGIN_RESULT LoginController::login(string& __id)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Login Controller Start");

    while ( true )
    {
		system("CLS");
		int res;
        cout << "  << 로그인 선택 >>  "<<endl;
        cout << "1. 손님 로그인"<<endl;
        cout << "2. 회원가입"<<endl;
        cout << "3. 피자가게 로그인" << endl;
        cout << "4. 재료가게 로그인" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택 : ";
        cin >> res;

        switch (res)
        {
        case EN_LOGIN:  
            return Login(__id, CUSTOMER);
        case EN_SIGNUP:
            Signup();
            break;
        case EN_PIZZA_LOGIN: 
            return Login(__id, PIZZA);
        case EN_INGRE_LOGIN: 
            return Login(__id, INGREDIENT);
        case EN_SHUT_DOWN: 
            return EN_SHUTDOWN;
        default:
            break;
        }
    }
}

EN_LOGIN_RESULT LoginController::Login(std::string& __id, EN_LOGIN_TYPE type)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "type %d Login Start", (int)type);
    
    while ( true )
    {
		system("CLS");
		string id, pw;
        cout << "  << 로그인 >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        //if (accounts.empty())
        //    return EN_SHUTDOWN;

        for (int i = 0; i != accounts.size(); i++)
        {
            if (accounts[i].type != type)
                continue;

            if (accounts[i].ID == id && accounts[i].PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "type %d Login Success", (int)type);

                __id = id;
                Sleep(500);
                
                if (accounts[i].type == CUSTOMER)
                    return EN_CUSTOMER_SUC;
                else if (accounts[i].type == PIZZA)
                    return EN_PIZZA_STORE_SUC;
                if (accounts[i].type == INGREDIENT)
                    return EN_INGREDIENT_SUC;
            }
            else if (accounts[i].ID == id && accounts[i].PW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Wrong PassWord");
                Sleep(500);
                system("CLS");
                //TODO: fix 
                break;
            }
        }
        // TODO: fix
        //LoginAlarm(EN_NOT_EXIST_ACC);
        
        bool ret = retry();
        if (ret == true)
        {
            continue;
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Login Retry");
        }
        else
            return EN_PW_FAIL;
    }
    return EN_SHUTDOWN;
}



bool LoginController::Signup()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "START, Signup");

	system("CLS");
	string id, pw;
    int balance;
    cout << "  << 회원가입 >>  "<<endl;
    cout << "ID : ";
    cin >> id;
    cout << "PW : ";
    cin >> pw;
    //cout << "balcane : ";
    //cin >> balance;


    for (int i = 0; i != accounts.size(); i++)
    {
        if (accounts[i].ID == id && accounts[i].type == CUSTOMER)
        {
            CLogger::getInstance()->write(enError, __LINE__, __FUNCTION__, "Exist ID : %s", id);
            LoginAlarm(EN_EXIST_ALREADY);
			Sleep(500);
			return false;
        }
    }

    Acc acc(id, pw, CUSTOMER);
    //Info info(id, balance);
    accounts.push_back(acc); //insert(pair(id, balance))
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "SignUp and Push_Back Success, id : %s", acc.ID);

    //accountsInfo.push_back(info);
    LoginAlarm(EN_SIGNUP_SUCCESS);

    FileSave::saveLoginData(accounts);
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "Save LoginData, id : %s", acc.ID);
    //FileSave::saveAccountInfo(accountsInfo);
	Sleep(500);
    return true;
}

void LoginController::LoginAlarm(EN_Alarm error)
{
    if (error == EN_NOT_EXIST_ACC)
        cout << "NOT_EXIST_ACC" << endl << endl;
    else if (error == EN_LOGIN_SUCCESS)
        cout << "LOGIN_SUCCESS" << endl << endl;
    else if (error == EN_WRONG_PW)
        cout << "WRONG_PW" << endl << endl;
    else if (error == EN_EXIST_ALREADY)
        cout << "EXIST_ALREADY" << endl << endl;
	else if (error == EN_SIGNUP_SUCCESS)
		cout << "SIGNUP_SUCCESS" << endl << endl;
    else
        cout << "ERROR" << endl << endl;

}

bool LoginController::retry()
{
    while (true)
    {
        string answer;
        cout << "잘못된 ID 또는 PW 입니다." << endl;
        cout << "다시 시도하시겠습니까? [y/n]" << endl;
        cin >> answer;
        if (answer == "y")
            return true;
        else if (answer == "n")
            return false;
        else
            continue;
    }
}