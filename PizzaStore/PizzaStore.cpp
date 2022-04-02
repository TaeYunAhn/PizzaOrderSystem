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
    // ���Ͽ� �� �� ������ �ִ��� �����صΰ� ���� Ŭ���� �Ҵ� �ϸ� �о��
    
}

PizzaStore::~PizzaStore()
{

}

PizzaStore::PizzaStore(IngredientStore *ingre)
{
     
     ingreStore = ingre;
}


bool PizzaStore::MainUI()
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
        if (res == 1)
            addMenu();
        else if (res == 2)
            modifyMenu();
        else if (res == 3)
            deleteMenu();
        else if (res == 4)
            confirmSales();
        else if (res == 5)
            return true;

        else
            tryAgain();
        
    }
    
}

void PizzaStore::addMenu()
{
    //while ( true )
    //{
    //    string Name;
    //    string Ingredients;
    //    int Price;
    //    int Sales = 0;
    //    cout << "  <<�޴� �߰�>>  "<<endl;
    //    cout << "1. �̸� :";
    //    cin >> Name;
    //    cout << "2. ��� :";
    //    cin >> Ingredients;
    //    cout << "3. ���� :";
    //    cin >> Price;
    //    cout << endl;

    //    PizzaMenu pizza(Name, Ingredients, Price);
    //    pizzaMenuVector.push_back(pizza);
    //    //���� ����

    //    cout << "�߰� �Ǿ����ϴ�."<<endl <<endl;
    //    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", Name.c_str(), Ingredients.c_str(), Price);

    //    Sleep(500);
    //    break;
    //}
    
    

    
    //_pizzaMenu.push_back(PizzaMenu("��������", "�������� ġ��, ��ö�, ����", 20000, 0));
}

void PizzaStore::modifyMenu()
{
    //while ( true )
    //{
    //    EN_PizzaMenu name;
    //    string ingredients;
    //    int price;
    //    int sales = 0;
    //    unsigned int sel;
    //    cout << "  <<�޴� ����>>  "<<endl;
    //    ShowPizzaList();
    //    cout << "��� ��ȣ ���� : ";
    //    cin >> sel;
    //    if ( sel > 0 && sel - 1 < pizzaMenuVector.size() )
    //    {
    //        cout << "���� �̸� : ";
    //        cin >> name;
    //        //��� �ߺ��Ǵ��� Ȯ��
    //        //bool find = false;
    //        //for (int i = 0 )
    //        cout << "��� ����Ʈ : ";
    //        cin >> ingredients;
    //        cout << "���� ���� : ";
    //        cin >> price;
    //        //cout << "�Ǹ� ���� : ";
    //        //cin >> sales;

    //        int num = sel - 1;
    //        pizzaMenuVector[num].Name = name;
    //        pizzaMenuVector[num].Ingredients = ingredients;
    //        pizzaMenuVector[num].Price = price;
    //        //pizzaMenuVector[num].Sales = sales;
    //        cout << "�����Ǿ����ϴ�." << endl<<endl;
    //        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", name.c_str(), ingredients.c_str(), price);
    //        //���� ����
    //        Sleep(500);
    //        break;
    //    }
    //    else
    //    {
    //        cout << "�߸� �Է��Ͽ����ϴ�." << endl;
    //        continue;
    //    }
    //}
}

void PizzaStore::deleteMenu()
{
    /*while ( true )
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
    }*/
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
    cout << "�ٽ� �õ��� �ּ���";
}


void PizzaStore::ShowPizzaList()
{
   /* const vector<PizzaMenu>& PizzaList = GetTotalPizza();

    cout << "----���� ����Ʈ---- "<<endl;
    for ( int i = 0; i < PizzaList.size(); i++ )
    {

        cout << i+1 <<"�� "<<endl;
        cout << "�̸� : " << PizzaList[i].Name  << endl;
        cout << "��� : " << PizzaList[i].Ingredients << endl;
        cout << "���� : " << PizzaList[i].Price << endl;
        }*/
}



vector<PizzaMenu> PizzaStore::GetTotalPizza()
{
    return pizzaMenuVector;
}

bool PizzaStore::ProcessOrder(EN_PizzaMenu num)
{
    bool order = false;
    //pizzaMenuVector; // ���� �̰� �ʿ� ����
    ingreStore; // ���⼭ �����ͼ� �ϳ��� ������ ���� ��� �ִ��� ���� Ȯ��

    //const vector<PizzaMenu>& PizzaList = GetTotalPizza();
    /*for (int i = 0; ingreStore->GetIngredientList().size(); i++)
    {
        if (ingreStore->GetIngredientList().begin() + i) // a,b,c,d

    }*/
    // ��� ���� for �� ���鼭 ��� ã��, 
    //ingredientVector.erase(ingredientVector.begin() + sel - 1);
    switch (num)
    {
    case en_Hawaiian:
    {
        // �ʿ��� ��� ���⿡ ����,
        // �ʿ��� ��Ḧ ingre ���� ã��
        // ��� Ȯ�εǸ� �׶� ���� ����
        string dough, tomato, cheese, pineapple, pork;
        vector<string>HawaiianIngre;
        HawaiianIngre.push_back(dough);
        HawaiianIngre.push_back(tomato);
        HawaiianIngre.push_back(cheese);
        HawaiianIngre.push_back(pineapple);
        HawaiianIngre.push_back(pork);

        // �̰� �����͸� �ѹ���(���ٿ�) ���� �� �ִ� ����� �������..
        
        
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            for (int r = 0; HawaiianIngre.size(); r++)
            {
                if (ingreStore->GetIngredientList()[i].Name == HawaiianIngre[r])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }  
        }
        order = true;
    }
        break;
    case en_Cheese:
        break;
    case en_combi:
        break;
    case en_Bulgogi:
        break;
    case en_Potato:
        break;
    default:
        break;
    }
    // ���ڰ��� �޴��� 5���� ����, �� �޴��� ���� ������ ����������, -> ��� 
}

void PizzaStore::noStock()
{
    cout << "��� �������� ���� ���ڸ� �ֹ� �� �� �����ϴ�." << endl;
}


//���� �̷�������?
//class Pizza //: public Hawaiian {
//{
//private:
//    string name;
//    string ingredient;
//    int price;
//public:
//    Pizza(string _name, string _ingredient, int _price) : name(_name), ingredient(_ingredient), price(_price) {}
//    //Pizza(string _name, string _ingredient, int _price) : Hawaiian(_name, _ingredient, _price) {}
//    void showInfo()
//    {
//        cout << "�̸�: " << name << endl;
//        cout << "���: " << ingredient << endl;
//        cout << "����: " << price << endl;
//    }
//
//};

//class Student : public Hawaiian {
//private:
//    char school[30];
//public:
//    Student(int _age, char* _name, char* _hobby, char* _school) : Hawaiian(_age, _name, _hobby)
//    {
//        strcpy(school, _school);
//    }
//    void schoolInfo()
//    {
//        showInfo();
//        cout << "�Ҽ� �б�: " << school << endl;
//    }
//};
//
//int main()
//{
//    Student stu(18, "��ö��", "���α׷���", "�ڹٰ���б�");
//
//    stu.schoolInfo();
//    stu.getup();
//    stu.eat();
//    stu.study();
//    stu.sleep();
//
//    return 0;
//}
