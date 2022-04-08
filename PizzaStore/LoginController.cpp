#include "LoginController.h"
#include <string>
#include <iostream>
#include "PizzaStore.h"
#include "IngredientStore.h"
#include "Logger.h"
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



EN_LOGIN_TYPE LoginController::MainUI()
{
    bool bExit = false;
    while ( !bExit )
    {
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
        case EN_LOGIN:  return GeneralLogin(); 
        case EN_SIGNUP: return Signup(); 
        case EN_PIZZA_LOGIN: return PizzaLogin();
        case EN_INGRE_LOGIN: return IngreLogin();
        case EN_SHUTDOWN: return ShutDown();

        default:
            break;
        }

        if (res == EN_LOGIN)
            GeneralLogin();
        else if (res == 2)
            Signup();
        else if (res == 3)
        {

            int en_num;
            en_num = PartnerLogin();
            if (en_num == EN_PIZZA_STORE_LOGIN_SUCCESS)
                return EN_PIZZA_STORE_LOGIN_SUCCESS;

            else if (en_num == EN_INGREDIENT_STORE_LOGIN_SUCCESS)
                return EN_INGREDIENT_STORE_LOGIN_SUCCESS;
        }

        else if (res == 4)
        {
            bExit = true;
            break;

        }
            
        else
            tryAgain();
    }
}

void LoginController::GeneralLogin()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "GeneralLogin Start");

    while ( true )
    {
        string id, pw;
        cout << "  << 로그인 >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;

        for (const Acc& acc : _GenAcc)
        {
            if (acc.ID == id && acc.PW == pw)
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                //손님 UI 로 이동
                break;
            }
        }

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

EN_LOGIN_TYPE LoginController::PartnerLogin()
{
    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "PartnerLogin Start");
    


    

    //while ( true )
    {
        string id, pw;
        cout << "  << 파트너 로그인 >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;
        

        //for( const ParAcc& acc : _ParAcc ) // For Each, 범위 기반 for
        //{
            if (id == "aa" && pw == "aa" )
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                return EN_PIZZA_STORE_LOGIN_SUCCESS;
               

            }
            else if (id == "bb" && pw == "bb" )
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                return EN_INGREDIENT_STORE_LOGIN_SUCCESS;
                

            }

            else if (id == "aa" && pw != "aa" || id == "bb" && pw != "bb" )
            {
                LoginAlarm(EN_WRONG_PW);
                //break;
            }

            else if (id != "aa" || id != "bb")
            {

                LoginAlarm(EN_NOT_EXIST_ACC);
                //break;

            }
        //}
            
       
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
        Acc genAcc(id, pw);
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