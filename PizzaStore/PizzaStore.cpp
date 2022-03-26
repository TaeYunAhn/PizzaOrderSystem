#include "PizzaStore.h"
#include "LoginController.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Logger.h"
using namespace std;


PizzaStore::PizzaStore()
{

}

PizzaStore::~PizzaStore()
{

}

PizzaStore::PizzaStore(IngredientStore *ingre)
{
     
     ingreStore = ingre;
}


void PizzaStore::MainUI()
{
    while ( true )
    {
        int res = 0;
        cout << "  << ���ڰ��� >>  "<<endl;
        cout << "1. �޴� ����"<<endl;
        cout << "2. �޴� ����"<<endl;
        cout << "3. �޴� ����"<<endl;
        cout << "4. ���� Ȯ��"<<endl;
        cout << "5. ���� �޴�"<<endl;
        cout << "���� : ";
        cin >> res;
        if (res == 1 )
            addMenu();
        else if (res == 2 )
            modifyMenu();
        else if (res == 3 )
            deleteMenu();
        else if (res == 4 )
            confirmSales();
        else if ( res == 5 )
        {
            break;
            LoginController login;
            login.MainUI();
        }

        else
            tryAgain();
        
    }
    
}

void PizzaStore::addMenu()
{
    while ( true )
    {
        string Name;
        string Ingredients;
        int Price;
        int Sales = 0;
        cout << "  <<�޴� �߰�>>  "<<endl;
        cout << "1. �̸� :";
        cin >> Name;
        cout << "2. ��� :";
        cin >> Ingredients;
        cout << "3. ���� :";
        cin >> Price;
        cout << endl;

        PizzaMenu pizza(Name, Ingredients, Price, Sales);
        pizzaMenuVector.push_back(pizza);
        //���� ����

        cout << "�߰� �Ǿ����ϴ�."<<endl <<endl;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", Name.c_str(), Ingredients.c_str(), Price);

        Sleep(500);
        break;
    }
    
    

    
    //_pizzaMenu.push_back(PizzaMenu("��������", "�������� ġ��, ��ö�, ����", 20000, 0));
}

void PizzaStore::modifyMenu()
{
    while ( true )
    {
        string name;
        string ingredients;
        int price;
        int sales = 0;
        unsigned int sel;
        cout << "  <<�޴� ����>>  "<<endl;
        ShowPizzaList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        if ( sel > 0 && sel - 1 < pizzaMenuVector.size() )
        {
            cout << "���� �̸� : ";
            cin >> name;
            //��� �ߺ��Ǵ��� Ȯ��
            //bool find = false;
            //for (int i = 0 )
            cout << "��� ����Ʈ : ";
            cin >> ingredients;
            cout << "���� ���� : ";
            cin >> price;
            cout << "�Ǹ� ���� : ";
            cin >> sales;

            int num = sel - 1;
            pizzaMenuVector[num].Name = name;
            pizzaMenuVector[num].Ingredients = ingredients;
            pizzaMenuVector[num].Price = price;
            pizzaMenuVector[num].Sales = sales;
            cout << "�����Ǿ����ϴ�." << endl<<endl;
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", name.c_str(), ingredients.c_str(), price);
            //���� ����
            Sleep(500);
            break;
        }
        else
        {
            cout << "�߸� �Է��Ͽ����ϴ�." << endl;
            continue;
        }
    }
}

void PizzaStore::deleteMenu()
{
    while ( true )
    {
        unsigned int sel;
        cout << "  <<�޴� ����>>  "<<endl;
        ShowPizzaList();
        cout << "��� ��ȣ ���� : ";
        cin >> sel;
        if ( sel > 0 && sel <= pizzaMenuVector.size() )
        {
            pizzaMenuVector.erase(pizzaMenuVector.begin() + sel - 1);
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "delMenu => %d", sel);
            cout << "�����Ǿ����ϴ�."<<endl<<endl;
            Sleep(500);
            break;
        }
        else
        {
            cout << "�߸� �Է��Ͽ����ϴ�." << endl;
            continue;
        }
    }
}

void PizzaStore::confirmSales()
{
    //ingreStore->getIng();
    /*const EN_RESULT res = IngredientStore->getIng("�������� ġ��", 5);
    switch ( res )
    {
    default:
        break;
    }

    if ( !IngredientStore->getIng("�������� ġ��", 5) )
    {
        "��ᰡ �����ϴ�.(��������)";
    }*/
}

void PizzaStore::tryAgain()
{

}


void PizzaStore::ShowPizzaList()
{
    const vector<PizzaMenu>& PizzaList = GetTotalPizza();

    cout << "----���� ����Ʈ---- "<<endl;
    for ( int i = 0; i < PizzaList.size(); i++ )
    {

        cout << i+1 <<"�� "<<endl;
        cout << "�̸� : " << PizzaList[i].Name  << endl;
        cout << "��� : " << PizzaList[i].Ingredients << endl;
        cout << "���� : " << PizzaList[i].Price << endl;
        cout << "�Ǹŷ� : " << PizzaList[i].Sales << endl<<endl;;
    }
}

vector<PizzaMenu> PizzaStore::GetTotalPizza()
{
    return pizzaMenuVector;
}