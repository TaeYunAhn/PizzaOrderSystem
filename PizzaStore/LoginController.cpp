#include "LoginController.h"
#include <string>
#include <iostream>
#include "PizzaStore.h"
#include "IngredientStore.h"
#include "Logger.h"
#include "FileSave.h"
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
    while ( true )
    {
		system("CLS");
		int res;
        cout << "  << �α��� ���� >>  "<<endl;
        cout << "1. �մ� �α���"<<endl;
        cout << "2. ȸ������"<<endl;
        cout << "3. ���ڰ��� �α���" << endl;
        cout << "4. ��ᰡ�� �α���" << endl;
        cout << "5. ���α׷� ����" << endl;
        cout << "���� : ";
        cin >> res;

        switch (res)
        {
        case EN_LOGIN:  
            return CustomerLogin(__id);
        case EN_SIGNUP:
            Signup();
            break;
        case EN_PIZZA_LOGIN: 
            return PizzaLogin();
        case EN_INGRE_LOGIN: 
            return IngreLogin();
        case EN_SHUT_DOWN: 
            return EN_SHUTDOWN;
        default:
            break;
        }
    }
}

EN_LOGIN_RESULT LoginController::CustomerLogin(std::string& __id)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "GeneralLogin Start");

    //�ϴ� ������� for ���� ���� ���� _GenAcc�� ������ ���� �־���� �ұ��.
    
    while ( true )
    {
		system("CLS");
		string id, pw;
        cout << "  << �α��� >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        if (accounts.empty())
            return EN_SHUTDOWN;

        for (int i = 0; i != accounts.size(); i++)
        {
            if (accounts[i].type != CUSTOMER)
                continue;

            if (accounts[i].ID == id && accounts[i].PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                __id = id;
                Sleep(500);
                return EN_CUSTOMER_SUC;
            }
            else if (accounts[i].ID == id && accounts[i].PW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                Sleep(500);
                system("CLS");
                
                //TODO: fix 
                bool ret = retry();
                if (ret == true)
                    continue;
                else
                    return EN_PW_FAIL;
            }
        }

        LoginAlarm(EN_NOT_EXIST_ACC);
        //Sleep(500);
        //system("CLS");
        bool ret = retry();
        if (ret == true)
            continue;
        else
            return EN_PW_FAIL;

    }
    return EN_SHUTDOWN;;
}

EN_LOGIN_RESULT LoginController::PizzaLogin()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "PizzaStoreLogin Start");

    system("CLS");

    while ( true )
    {
        string id, pw;
        cout << "  << PizzaStore Login >>  " << endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        for (int i = 0; i != accounts.size(); i++)
        {
            const Acc& account = accounts[i];

            if (accounts[i].type != PIZZA)
                continue;

            if (account.ID == id && account.PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                Sleep(500);
                system("CLS");
                return EN_PIZZA_STORE_SUC;
            }
            else if (account.ID == id && account.PW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                Sleep(500);
                system("CLS");
                return EN_PW_FAIL;
            }
        }  

        LoginAlarm(EN_NOT_EXIST_ACC);
        //Sleep(500);
        //system("CLS");
        bool ret = retry();
        if (ret == true)
            continue;
        else
            return EN_PW_FAIL;
    }
}

EN_LOGIN_RESULT LoginController::IngreLogin()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "IngreLogin Start");
    
    system("CLS");

    while ( true )
    {
        string id, pw;
        cout << "  << Ingredient Store Login >>  " << endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        for (int i = 0; i != accounts.size(); i++)
        {
            const auto& account = accounts[i];

            if (accounts[i].type != PIZZA)
                continue;

            if (id == account.ID && pw == account.PW)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                Sleep(500);
                system("CLS");
                return EN_INGREDIENT_SUC;
            }

            else if (id == account.ID && pw != account.PW)
            {
                LoginAlarm(EN_WRONG_PW);
                Sleep(500);
                system("CLS");
                return EN_PW_FAIL;
            }
        }

        LoginAlarm(EN_NOT_EXIST_ACC);
        //Sleep(500);
        //system("CLS");
        bool ret = retry();
        if (ret == true)
            continue;
        else
            return EN_PW_FAIL;
    }
}

bool LoginController::Signup()
{
	system("CLS");
	string id, pw;
    cout << "  << ȸ������ >>  "<<endl;
    cout << "ID : ";
    cin >> id;

    cout << "PW : ";
    cin >> pw;

    for (int i = 0; i != accounts.size(); i++)
    {
        if (accounts[i].ID == id && accounts[i].type == CUSTOMER)
        {
            LoginAlarm(EN_EXIST_ALREADY);
			Sleep(500);
			return false;
        }
    }

    Acc acc(id, pw, CUSTOMER);
    accounts.push_back(acc);
    LoginAlarm(EN_SIGNUP_SUCCESS);
    FileSave::saveLoginData(accounts);
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
        cout << "�߸��� ID �Ǵ� PW �Դϴ�." << endl;
        cout << "�ٽ� �õ��Ͻðڽ��ϱ�? [y/n]" << endl;
        cin >> answer;
        if (answer == "y")
            return true;
        else if (answer == "n")
            return false;
        else
            continue;
    }
    

}