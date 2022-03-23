#include "LoginController.h"
#include <string>
#include <iostream>
#include "PizzaStore.h"
#include "IngredientStore.h"
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
        cout << "  << �α��� ���� >>  "<<endl;
        cout << "1. �α���"<<endl;
        cout << "2. ȸ������"<<endl;
        cout << "3. ��Ʈ�� �α���"<<endl;
        cout << "���� : ";
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
        cout << "  << �α��� >>  "<<endl;
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
                //�մ� UI �� �̵�
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
        cout << "  << ��Ʈ�� �α��� >>  "<<endl;
        cout << "ID : ";
        cin >> id;
        cout << "PW : ";
        cin >> pw;
        std::string pizzaID = "aa";
        std::string pizzaPW = "aa";
        string ingredientID = "bb";
        string ingredientPW = "bb";
        ParAcc pizzaLogin(pizzaID, pizzaPW);
        ParAcc ingredientLogin(ingredientID, ingredientPW);
        _ParAcc.push_back(pizzaLogin);
        _ParAcc.push_back(ingredientLogin);

        int i = 0;
        while ( i < _ParAcc.size() )
        {
            if (_ParAcc[i].ID == pizzaID && _ParAcc[i].PW == pizzaPW )
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                PizzaStore pizza;
                pizza.MainUI();

            }
            else if (_ParAcc[i].ID == ingredientID && _ParAcc[i].PW == ingredientPW )
            {
                LoginAlarm(EN_LOGIN_SUCCESS);
                IngredientStore ingredient;
                ingredient.SelectMenu();

            }

            else if (_ParAcc[i].ID == pizzaID && _ParAcc[i].PW != pizzaPW | _ParAcc[i].ID == ingredientID && _ParAcc[i].PW != ingredientPW )
            {
                LoginAlarm(EN_WRONG_PW);
                break;
            }

            else if (_ParAcc[i].ID != pizzaID || _ParAcc[i].ID != ingredientID)
            {

                LoginAlarm(EN_NOT_EXIST_ACC);
                break;

            }
            
            i++;
        }
            
       
    }
    
}

void LoginController::Signup()
{
    while ( true )
    {
        string id, pw;
        cout << "  << ȸ������ >>  "<<endl;
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