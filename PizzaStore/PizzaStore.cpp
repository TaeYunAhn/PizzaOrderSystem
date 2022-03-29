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


bool PizzaStore::MainUI()
{
    while ( true )
    {
        int res = 0;
        cout << "  << 피자가게 >>  "<<endl;
        cout << "1. 메뉴 생성"<<endl;
        cout << "2. 메뉴 수정"<<endl;
        cout << "3. 메뉴 삭제"<<endl;
        cout << "4. 매출 확인"<<endl;
        cout << "5. 이전 메뉴"<<endl;
        cout << "선택 : ";
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
    while ( true )
    {
        string Name;
        string Ingredients;
        int Price;
        int Sales = 0;
        cout << "  <<메뉴 추가>>  "<<endl;
        cout << "1. 이름 :";
        cin >> Name;
        cout << "2. 재료 :";
        cin >> Ingredients;
        cout << "3. 가격 :";
        cin >> Price;
        cout << endl;

        PizzaMenu pizza(Name, Ingredients, Price);
        pizzaMenuVector.push_back(pizza);
        //파일 저장

        cout << "추가 되었습니다."<<endl <<endl;
        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", Name.c_str(), Ingredients.c_str(), Price);

        Sleep(500);
        break;
    }
    
    

    
    //_pizzaMenu.push_back(PizzaMenu("고르곤졸라", "고르곤졸라 치즈, 루꼴라, 갈릭", 20000, 0));
}

void PizzaStore::modifyMenu()
{
    while ( true )
    {
        EN_PizzaMenu name;
        string ingredients;
        int price;
        int sales = 0;
        unsigned int sel;
        cout << "  <<메뉴 수정>>  "<<endl;
        ShowPizzaList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > 0 && sel - 1 < pizzaMenuVector.size() )
        {
            cout << "피자 이름 : ";
            cin >> name;
            //재고 중복되는지 확인
            //bool find = false;
            //for (int i = 0 )
            cout << "재료 리스트 : ";
            cin >> ingredients;
            cout << "피자 가격 : ";
            cin >> price;
            //cout << "판매 갯수 : ";
            //cin >> sales;

            int num = sel - 1;
            pizzaMenuVector[num].Name = name;
            pizzaMenuVector[num].Ingredients = ingredients;
            pizzaMenuVector[num].Price = price;
            //pizzaMenuVector[num].Sales = sales;
            cout << "수정되었습니다." << endl<<endl;
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", name.c_str(), ingredients.c_str(), price);
            //파일 쓰기
            Sleep(500);
            break;
        }
        else
        {
            cout << "잘못 입력하였습니다." << endl;
            continue;
        }
    }
}

void PizzaStore::deleteMenu()
{
    while ( true )
    {
        unsigned int sel;
        cout << "  <<메뉴 삭제>>  "<<endl;
        ShowPizzaList();
        cout << "재료 번호 선택 : ";
        cin >> sel;
        if ( sel > 0 && sel <= pizzaMenuVector.size() )
        {
            pizzaMenuVector.erase(pizzaMenuVector.begin() + sel - 1);
            CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "delMenu => %d", sel);
            cout << "삭제되었습니다."<<endl<<endl;
            Sleep(500);
            break;
        }
        else
        {
            cout << "잘못 입력하였습니다." << endl;
            continue;
        }
    }
}

void PizzaStore::confirmSales()
{
    //ingreStore->getIng();
    /*const EN_RESULT res = IngredientStore->getIng("고르곤졸라 치즈", 5);
    switch ( res )
    {
    default:
        break;
    }

    if ( !IngredientStore->getIng("고르곤졸라 치즈", 5) )
    {
        "재료가 없습니다.(고르곤졸라)";
    }*/
}

void PizzaStore::tryAgain()
{
    cout << "다시 시도해 주세요";
}


void PizzaStore::ShowPizzaList()
{
    const vector<PizzaMenu>& PizzaList = GetTotalPizza();

    cout << "----피자 리스트---- "<<endl;
    for ( int i = 0; i < PizzaList.size(); i++ )
    {

        cout << i+1 <<"번 "<<endl;
        cout << "이름 : " << PizzaList[i].Name  << endl;
        cout << "재료 : " << PizzaList[i].Ingredients << endl;
        cout << "가격 : " << PizzaList[i].Price << endl;
        }
}



vector<PizzaMenu> PizzaStore::GetTotalPizza()
{
    return pizzaMenuVector;
}

bool PizzaStore::ProcessOrder(EN_PizzaMenu num)
{
    bool order = false;
    pizzaMenuVector;
    //const vector<PizzaMenu>& PizzaList = GetTotalPizza();
    /*for (int i = 0; ingreStore->GetIngredientList().size(); i++)
    {
        if (ingreStore->GetIngredientList().begin() + i) // a,b,c,d

    }*/
    // 비긴 부터 for 문 돌면서 재료 찾고, 
    //ingredientVector.erase(ingredientVector.begin() + sel - 1);
    switch (num)
    {
    case en_Hawaiian:
    {
        
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
    // 피자가게 메뉴는 5개로 제한, 각 메뉴의 재료와 가격은 정해져있음, -> 상속 
}



class Pizza {
private:
    string name;
    vector<string>ingredient;
    int price;
public:
    Pizza(string _name, vector<string> _ingredient, int _price) : name(_name), ingredient(_ingredient), price(_price) {}
    void getup()
    {
        cout << "기상!" << endl;
    }
    void sleep()
    {
        cout << "취침!" << endl;
    }
    void eat()
    {
        cout << "식사!" << endl;
    }
    void study()
    {
        cout << "공부!" << endl;
    }
    void showInfo()
    {
        cout << "이름: " << name << endl;
        cout << "재료: " << ingredient << endl;
        cout << "가격: " << price << endl;
    }
};

class Student : public Hawaiian {
private:
    char school[30];
public:
    Student(int _age, char* _name, char* _hobby, char* _school) : Hawaiian(_age, _name, _hobby)
    {
        strcpy(school, _school);
    }
    void schoolInfo()
    {
        showInfo();
        cout << "소속 학교: " << school << endl;
    }
};

int main()
{
    Student stu(18, "김철수", "프로그래밍", "자바고등학교");

    stu.schoolInfo();
    stu.getup();
    stu.eat();
    stu.study();
    stu.sleep();

    return 0;
}
