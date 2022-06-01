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

EN_LOGIN_RESULT LoginController::login(string& userId)
{
    while ( true )
    {
		system("CLS");
		int res;
        cout << "  << �α��� ���� >>  "<<endl;
        cout << "1. ȸ������"<<endl;
        cout << "2. �մ� �α���"<<endl;
        cout << "3. ���ڰ��� �α���" << endl;
        cout << "4. ��ᰡ�� �α���" << endl;
        cout << "5. ���α׷� ����" << endl;
        cout << "���� : ";
        cin >> res;

        switch (res)
        {
        case EN_CUSTOMER_LOGIN:  
            return Login(userId, CUSTOMER);
        case EN_SIGNUP:
            Signup();
            break;
        case EN_PIZZA_LOGIN: 
            return Login(userId, PIZZA);
        case EN_INGRE_LOGIN: 
            return Login(userId, INGREDIENT);
        case EN_SHUT_DOWN: 
            return EN_SHUTDOWN;
        default:
            break;
        }
    }
}

EN_LOGIN_RESULT LoginController::Login(std::string& userId, EN_LOGIN_TYPE type)
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "GeneralLogin Start");
    
    while ( true )
    {
		system("CLS");
		string id, pw;
        cout << "  << �α��� >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        for (const AccInfo& a : accounts)
        {
            if (a.loginType != type)
                continue;

            if (a.accID == id && a.accPW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                userId = id;
                Sleep(500);
                
                if (a.loginType == CUSTOMER)
                    return EN_CUSTOMER_SUC;
                else if (a.loginType == PIZZA)
                    return EN_PIZZA_STORE_SUC;
                if (a.loginType == INGREDIENT)
                    return EN_INGREDIENT_SUC;
            }
            else if (a.accID == id && a.accPW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                Sleep(500);
                system("CLS");
                //TODO: fix 
                break;
            }
        }

        // TODO: fix
        //LoginAlarm(EN_NOT_EXIST_ACC);
        
        if (retry())
            continue;
        else
            return EN_PW_FAIL;
    }
    return EN_SHUTDOWN;
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

    if ( std::count_if(accounts.begin(), accounts.end(), [&id] (const AccInfo& a) {
        return a.accID == id && a.loginType == CUSTOMER;
    }) > 0 )
    {
        LoginAlarm(EN_EXIST_ALREADY);
        Sleep(500);
        return false;
    }

    AccInfo info(id, pw, CUSTOMER);
    accounts.push_back(info);

    LoginAlarm(EN_SIGNUP_SUCCESS);
    FileSave::saveLoginData(accounts);
	Sleep(500);

    return true;
}

void LoginController::LoginAlarm(EN_Alarm type)
{
    if (type == EN_NOT_EXIST_ACC)
        cout << "NOT_EXIST_ACC" << endl << endl;
    else if (type == EN_LOGIN_SUCCESS)
        cout << "LOGIN_SUCCESS" << endl << endl;
    else if (type == EN_WRONG_PW)
        cout << "WRONG_PW" << endl << endl;
    else if (type == EN_EXIST_ALREADY)
        cout << "EXIST_ALREADY" << endl << endl;
	else if (type == EN_SIGNUP_SUCCESS)
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