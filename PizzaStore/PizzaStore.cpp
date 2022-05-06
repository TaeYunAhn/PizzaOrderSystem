#include <Windows.h>
#include <array>
#include "Logger.h"
#include "PizzaStore.h"
#include "Pizza.h"
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
{

    array<string, en_TotalNum> pizzaName = { "", "cheese", "combi", "hawaiian", "potato", "bulgogi" };
    for (int i = 1; i < en_TotalNum; i++)
    {
            cout << i << ". " << pizzaName[i]<< endl;
    }
}



//vector<EN_PizzaMenu> PizzaStore::GetTotalPizza()
//{
//    return pizzaMenuVector;
//}


Pizza* PizzaStore::makePizza(EN_PizzaMenu menu)
{
    switch (menu)
    {
    case en_Hawaiian: return new HawaiianPizza;

    case en_Cheese: return new CheesePizza;
        
    case en_Combi: return new CombiPizza;

    case en_Bulgogi: return new BulgogiPizza;

    case en_Potato: return new PotatoPizza;

    case en_TotalNum: return nullptr;
       
    default: return nullptr;
    }
}

EN_PizzaMenu PizzaStore::getingreList(EN_PizzaMenu menu)
{
    return en_Hawaiian;
    /*switch (menu)
    {
    case en_Hawaiian: return;

    case en_Cheese: return;

    case en_Combi: return;

    case en_Bulgogi: return;

    case en_Potato: return;

    case en_TotalNum: return;

    default: return;
    }*/
}


bool PizzaStore::ProcessOrder(EN_PizzaMenu menu/*, Pizza* out*/ )
{
    // 피자를 만들고 해당 피자의 재료 리스트를 재료가게에 넘겨줌 

    // 재료가게에서 재료 가져오기
    // 피자만들기
    // 매출up 및 피자 반환

    int cost = 0;
    Pizza* pizza = makePizza(menu);
    if (!ingreStore->checkIngredients(pizza->getIngredients(), cost))
    {
        return false;
    }

    Money -= cost;
    Money += pizza->getPrice();

    auto itr = pizzaSalesMap.find(menu);
    if (itr == pizzaSalesMap.end())
    {
        //pizzaSalesMap[menu] = pizza->getPrice();
        pizzaSalesMap.insert(make_pair(menu, pizza->getPrice()));
    }
    else
    {
       itr->second += pizza->getPrice();
    }

    //if (pizzaSalesMap.count(menu) == 0)
    //{
    //    //error
    //    return false;
    //}

    pizzaSalesMap[menu] += pizza->getPrice();

    //pizzaSalesMap.insert(make_pair(menu, pizza->getPrice()));

    // out 대신 auto p 같은걸로 받아서 예외처리 한번 더? 
    //Money += out->getPrice();
    return true;

    // 상속을 써야하는 이유는 패턴 프로그래밍이 들어가는 경우 부터(다형성)
    // 재료가게에 피자 or 피자 타입을 넘겨줘서 재료를 가져온다. 이 때 다형성 써보자
    // 그 이후 팩토리 or 다른 패턴을 써서 다형성 활용
    

    
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
