#include "LoginController.h"
#include <string>
#include <iostream>
using namespace std;


LoginController::LoginController()
{
    //vector<Acc> data;
    //if (FileSaving::readAcc(data))
    //    emailAccounts = data;
}

LoginController::~LoginController()
{
    
}

void LoginController::MainUI()
{
    while ( true )
    {
        int res;
        cout << "  << 로그인 선택 >>  "<<endl;
        cout << "1. 로그인"<<endl;
        cout << "2. 회원가입"<<endl;
        cout << "3. 파트너 로그인"<<endl;
        cout << "선택 : ";
        cin >> res;

        if (res == 1 )
            GeneralLogin();
        else if (res == 2 )
            Signup();
        else if (res == 3 )
            PartnerLogin();
        else
            tryAgain();
    }
}

void LoginController::GeneralLogin()
{
    while ( true )
    {
        string id, pw;
        cout << "  << 로그인 >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        int i = 0;
        while (i < _GenAcc.size())
        {



            if (_GenAcc[i].ID == id && _GenAcc[i].PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                //손님 UI 로 이동
                break;
            }

            else if (_GenAcc[i].ID == id && _GenAcc[i].PW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                break;
            }

            else if (_GenAcc[i].ID != id)
            {
                i++;
                if (i == _GenAcc.size())
                {
                    LoginAlarm(EN_NOT_EXIST_ACC);
                    break;

                }
            }
            break;
            
            //if (res == EN_LOGIN_SUCCESS)
            //{
            //    //cout << "LOGIN_SUCCESS" << endl;
            //    MainController::MailStart(ID);
            //}
        }
    }
}

void LoginController::PartnerLogin()
{

    while ( true )
    {
        string id, pw;
        cout << "  << 파트너 로그인 >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        int i = 0;
        while (i < _ParAcc.size())
        {
            if (_ParAcc[i].ID == id && _ParAcc[i].PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                break;
            }

            else if (_ParAcc[i].ID == id && _ParAcc[i].PW != pw)
            {
                LoginAlarm(EN_WRONG_PW);
                break;
            }

            else if (_ParAcc[i].ID != id)
            {
                i++;
                if (i == _ParAcc.size())
                {
                    LoginAlarm(EN_NOT_EXIST_ACC);
                    break;

                }
            }
            break;
        }
    }
    
}

void LoginController::Signup()
{
    while ( true )
    {
        string id, pw;
        cout << "  << 회원가입 >>  "<<endl;
        cout << "ID : ";
        cin >> id;

        cout << "PW : ";
        cin >> pw;

        for (int i = 0; i < _GenAcc.size(); i++)
        {
            if (_GenAcc[i].ID == id)
            {
                LoginAlarm(EN_EXIST_ALREADY);
                continue;
            }
        }
        GenAcc genAcc(id, pw);
        _GenAcc.push_back(genAcc);
        //FileSave::saveAcc(_GenAcc);
        LoginAlarm(EN_SIGNUP_SUCCESS);
        break;
    }
}

void LoginController::LoginAlarm(EN_Alarm error)
{
    if (error == EN_NOT_EXIST_ACC)
    {
        cout << "NOT_EXIST_ACC" << endl
            << endl;
    }
    else if (error == EN_LOGIN_SUCCESS)
    {
        cout << "LOGIN_SUCCESS" << endl
            << endl;
    }

    else if (error == EN_WRONG_PW)
    {
        cout << "WRONG_PW" << endl
            << endl;
    }
    else if (error == EN_EXIST_ALREADY)
    {
        cout << "EXIST_ALREADY" << endl
            << endl;
    }
    else if (error == EN_SIGNUP_SUCCESS)
    {
        cout << "SIGNUP_SUCCESS" << endl
            << endl;
    }
    else
    {
        cout << "ERROR" << endl
            << endl;
    }
}

void LoginController::tryAgain()
{

}