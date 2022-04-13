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
    // 파일에 돈 얼마 가지고 있는지 저장해두고 피자 클래스 할당 하면 읽어옴

    //pushbackMenu();
    
}

PizzaStore::~PizzaStore()
{

}

PizzaStore::PizzaStore(IngredientStore *ingre)
{
     
     ingreStore = ingre;
}

void PizzaStore::pushbackMenu()
{

}


bool PizzaStore::RunPizzaStore()
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
    //while ( true )
    //{
    //    string Name;
    //    string Ingredients;
    //    int Price;
    //    int Sales = 0;
    //    cout << "  <<메뉴 추가>>  "<<endl;
    //    cout << "1. 이름 :";
    //    cin >> Name;
    //    cout << "2. 재료 :";
    //    cin >> Ingredients;
    //    cout << "3. 가격 :";
    //    cin >> Price;
    //    cout << endl;

    //    PizzaMenu pizza(Name, Ingredients, Price);
    //    pizzaMenuVector.push_back(pizza);
    //    //파일 저장

    //    cout << "추가 되었습니다."<<endl <<endl;
    //    CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", Name.c_str(), Ingredients.c_str(), Price);

    //    Sleep(500);
    //    break;
    //}
    
    

    
    //_pizzaMenu.push_back(PizzaMenu("고르곤졸라", "고르곤졸라 치즈, 루꼴라, 갈릭", 20000, 0));
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
    //    cout << "  <<메뉴 수정>>  "<<endl;
    //    ShowPizzaList();
    //    cout << "재료 번호 선택 : ";
    //    cin >> sel;
    //    if ( sel > 0 && sel - 1 < pizzaMenuVector.size() )
    //    {
    //        cout << "피자 이름 : ";
    //        cin >> name;
    //        //재고 중복되는지 확인
    //        //bool find = false;
    //        //for (int i = 0 )
    //        cout << "재료 리스트 : ";
    //        cin >> ingredients;
    //        cout << "피자 가격 : ";
    //        cin >> price;
    //        //cout << "판매 갯수 : ";
    //        //cin >> sales;

    //        int num = sel - 1;
    //        pizzaMenuVector[num].Name = name;
    //        pizzaMenuVector[num].Ingredients = ingredients;
    //        pizzaMenuVector[num].Price = price;
    //        //pizzaMenuVector[num].Sales = sales;
    //        cout << "수정되었습니다." << endl<<endl;
    //        CLogger::getInstance()->write(enInfo, __LINE__, __FUNCTION__, "addMenu => name(%s) Ingre(%s), Price(%d)", name.c_str(), ingredients.c_str(), price);
    //        //파일 쓰기
    //        Sleep(500);
    //        break;
    //    }
    //    else
    //    {
    //        cout << "잘못 입력하였습니다." << endl;
    //        continue;
    //    }
    //}
}

void PizzaStore::deleteMenu()
{
    /*while ( true )
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
    }*/
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
{/*
    const vector<EN_PizzaMenu>& PizzaList = GetTotalPizza();

    cout << "----피자 리스트---- "<<endl;
    for ( int i = 0; i < PizzaList.size(); i++ )
    {

        cout << i+1 <<"번 "<<endl;
        cout << "이름 : " <<  
        cout << "재료 : " << PizzaList[i].Ingredients << endl;
        cout << "가격 : " << PizzaList[i].Price << endl;
    }*/
}



vector<EN_PizzaMenu> PizzaStore::GetTotalPizza()
{
    return pizzaMenuVector;
}

bool PizzaStore::ProcessOrder(EN_PizzaMenu menu)
{
    return true;

    //bool order = false;
    ////pizzaMenuVector; // 이제 이건 필요 없음
    //ingreStore; // 여기서 가져와서 하나씩 대조해 보고 재료 있는지 여부 확인
    //return true;
    //
    //std::vector<std::string> hawaiianIng = { "...", "..." };
    //Pizza* p = new Hawaiian("Hawaiian", hawaiianIng, 17000);
    //
    //P->showInfo();
    //
    //p = new Bulgogi();
    //P->showInfo();
    //
    ////Pizza p1 = getPizzaInstance(num);
    //Pizza p1 = Factory::getPizzaInstance(num);
    //auto res = ingreStore->GetIngredient(p1);
    //if (!res)
    //{
    //    // error 
    //    return false;
    //}
    //
    ////  success
    //return true;
    //
    //if (num == en_Hawaiian)
    //{
    //    Hawaiian h("Hawaiian", hawaiianIng, 17000);
    //    p1 = (Pizza)h;
    //}
    //else if (num == = )
    //{
    //
    //}
    //else if (num == = )
    //{
    //
    //}
    //else if (num == = )
    //{
    //
    //}




    //ingreStore->GetIngredient(p1);

    //const vector<PizzaMenu>& PizzaList = GetTotalPizza();
    /*for (int i = 0; ingreStore->GetIngredientList().size(); i++)
    {
        if (ingreStore->GetIngredientList().begin() + i) // a,b,c,d

    }*/
    // 비긴 부터 for 문 돌면서 재료 찾고, 
    //ingredientVector.erase(ingredientVector.begin() + sel - 1);
/*
    string dough, tomato, cheese, pineapple, pork, olive, beef, potato, bacon;

    Pizza pizza = Factory::MakePizza(num);
    bool bIng = true;
    for (const string& in : pizza.getAllIngredients())
    {
        if (!ingreStore->GetIngredient(in))
        {
            bIng = false;
            break;
        }
    }

    if (!bIng)
    {
        // error 재료가 없습니다
        //return
    }
*/
    // 매출 업 
    //myMoney += pizza.getPrice();
    
    
/*
    PizzaMenu Cheese(en_Cheese, 13000, dough, tomato, cheese);
    pizzaMenuVector.push_back(Cheese);

    PizzaMenu Combi(en_Combi, 13000, dough, tomato, cheese, pork, olive);
    pizzaMenuVector.push_back(Combi);

    PizzaMenu Bulgogi(en_Bulgogi, 13000, dough, tomato, cheese, olive, beef);
    pizzaMenuVector.push_back(Bulgogi);

    PizzaMenu Potato(en_Potato, 13000, dough, tomato, cheese, potato, bacon);
    pizzaMenuVector.push_back(Potato);
    */
    /*
    switch (num)
    {
    case en_Hawaiian:
    {
        // 필요한 재료 여기에 쓰고,
        // 필요한 재료를 ingre 에서 찾고
        // 모두 확인되면 그때 컨펌 해줘
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            //현재 가변인자 때문에 Hawaiian.Ingredients[j] 여기가 비어있음..
            for (int j = 0; Hawaiian.Ingredients[j]; j++)
            {
                if (ingreStore->GetIngredientList()[i].Name == Hawaiian.Ingredients[j])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    //Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }  
        }
        */

        // 상속 사용하는 부분
        /*bool bIng = true;
        for (const string& in : hawaiian.getAllIngredients())
        {
            if (!ingreStore->GetIngredient(in))
            {
                bIng = false;
                break;
            }
        }

        if (!bIng)
        {
            // error 재료가 없습니다
            //return
        }*/

        // 매출 업 
        //myMoney += hawaiianPizza.getPrice();
/*
        order = true;
    }
        break;
    case en_Cheese:
    {
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            //현재 가변인자 때문에 Hawaiian.Ingredients[j] 여기가 비어있음..
            for (int j = 0; Cheese.Ingredients[j]; j++)
            {
                if (ingreStore->GetIngredientList()[i].Name == Cheese.Ingredients[j])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    //Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }
        }
        order = true;
    }
        
        break;
    case en_Combi:
    {
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            //현재 가변인자 때문에 Hawaiian.Ingredients[j] 여기가 비어있음..
            for (int j = 0; Combi.Ingredients[j]; j++)
            {
                if (ingreStore->GetIngredientList()[i].Name == Combi.Ingredients[j])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    //Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }
        }
    }
        
        order = true;
        break;
    case en_Bulgogi:
    {
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            //현재 가변인자 때문에 Hawaiian.Ingredients[j] 여기가 비어있음..
            for (int j = 0; Bulgogi.Ingredients[j]; j++)
            {
                if (ingreStore->GetIngredientList()[i].Name == Bulgogi.Ingredients[j])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    //Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }
        }
        order = true;
    }
        break;
    case en_Potato:
    {
        for (int i = 0; ingreStore->GetIngredientList().size(); i++)
        {
            //현재 가변인자 때문에 Hawaiian.Ingredients[j] 여기가 비어있음..
            for (int j = 0; Potato.Ingredients[j]; j++)
            {
                if (ingreStore->GetIngredientList()[i].Name == Potato.Ingredients[j])
                {
                    if (ingreStore->GetIngredientList()[i].Stock <= 0)
                        noStock();
                    ingreStore->GetIngredientList()[i].Stock--;
                    //Money -= ingreStore->GetIngredientList()[i].Price;
                }
            }

        }
        order = true;
    }
        break;
    default:
        tryAgain();
        break;
    }
    // 피자가게 메뉴는 5개로 제한, 각 메뉴의 재료와 가격은 정해져있음, -> 상속 
    */
}

void PizzaStore::noStock()
{
    cout << "재료 부족으로 피자를 주문 할 수 없습니다." << endl;
}

bool PizzaStore::accountIngredient(string PizzaName)
{
    return true;
}


//대충 이런식으로?
//class Hawaiian : public Pizza
//{
//private:
//    string name;
//    string ingredient;
//    int price;
//public:
//    Hawaiian(string _name, string _ingredient, int _price) : name(_name), ingredient(_ingredient), price(_price) { Pizza()}
//    //Pizza(string _name, string _ingredient, int _price) : Hawaiian(_name, _ingredient, _price) {}
//    void showInfo()
//    {
//        cout << "이름: " << name << endl;
//        cout << "재료: " << ingredient << endl;
//        cout << "가격: " << price << endl;
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
//        cout << "소속 학교: " << school << endl;
//    }
//};
//
//int main()
//{
//    Student stu(18, "김철수", "프로그래밍", "자바고등학교");
//
//    stu.schoolInfo();
//    stu.getup();
//    stu.eat();
//    stu.study();
//    stu.sleep();
//
//    return 0;
//}
