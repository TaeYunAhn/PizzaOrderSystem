#include <Windows.h>
#include <array>
#include "Logger.h"
#include "PizzaStore.h"
#include "Pizza.h"
using namespace std;


PizzaStore::PizzaStore()
{
    // ���Ͽ� �� �� ������ �ִ��� �����صΰ� ���� Ŭ���� �Ҵ� �ϸ� �о��

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
    // ���ڸ� ����� �ش� ������ ��� ����Ʈ�� ��ᰡ�Կ� �Ѱ��� 

    // ��ᰡ�Կ��� ��� ��������
    // ���ڸ����
    // ����up �� ���� ��ȯ

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

    // out ��� auto p �����ɷ� �޾Ƽ� ����ó�� �ѹ� ��? 
    //Money += out->getPrice();
    return true;

    // ����� ����ϴ� ������ ���� ���α׷����� ���� ��� ����(������)
    // ��ᰡ�Կ� ���� or ���� Ÿ���� �Ѱ��༭ ��Ḧ �����´�. �� �� ������ �Ẹ��
    // �� ���� ���丮 or �ٸ� ������ �Ἥ ������ Ȱ��
    

    
}

void PizzaStore::noStock()
{
    cout << "��� �������� ���ڸ� �ֹ� �� �� �����ϴ�." << endl;
}

bool PizzaStore::accountIngredient(string PizzaName)
{
    return true;
}


//���� �̷�������?
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
