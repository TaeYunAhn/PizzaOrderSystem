#pragma once
#include <vector>
#include <string>
#include "IngredientStore.h"
#include <map>
#include <iostream>



enum EN_PizzaMenu
{
    en_Hawaiian = 1,
    en_Cheese,
    en_Combi,
    en_Bulgogi,
    en_Potato,
};

class Pizza 
{
public:
    Pizza(const EN_PizzaMenu& type, int price) :
        Type(type), Price(price) {}

    ~Pizza() {}
    
    virtual void showInfo() // 가상 함수
    {
       //std::cout << "이름: " << Name << std::endl;
       //std::cout << "재료: " << Ingredients << std::endl;
        std::cout << "가격: " << Price << std::endl;
    }

    virtual void setIngredients() 
    {
        Ingredients.push_back("d");
        Ingredients.push_back("k");
        Ingredients.push_back("t");
    }
    //virtual void setIngredients() = 0;  // 순수 가상 함수

    // 순수 가상 함수는 반드시 자식에서 재정의 해줘야 함
    // 순수 가상 함수가 하나라도 있는 클래스(추상 클래스)는 인스턴스(객체) 생성 불가(즉, 자식을 통해서만 구현)
    
protected:
    EN_PizzaMenu Type;
    std::vector<std::string> Ingredients;
    int Price;
};


class Hawaiian : public Pizza
{
public:
    Hawaiian(): Pizza(en_Hawaiian, 16000) 
    {
        setIngredients();
    }
    
    virtual void setIngredients() override 
    {
        __super::setIngredients();

        Ingredients.push_back("파인애플");
        //Ingredients.assign(s.begin(), s.end());
    }
};

class Bulgogi : public Pizza
{
public:
    Bulgogi() : Pizza(en_Bulgogi, 20000) 
    {
        setIngredients();
    }

    virtual void setIngredients() override
    {
        __super::setIngredients();

        Ingredients.push_back("bulgogi");
    }
};

/*class HawaiianPizza : public PizzaMenu
{
    HawaiianPizza()
    {
        std::vector<std::string> ingredients = { "dough", "cheese" };
        PizzaMenu(en_Hawaiian, 13000, ingredients);
    }

};*/

class PizzaStore
{
public:
    PizzaStore();
    PizzaStore(IngredientStore*);
    ~PizzaStore();
    bool RunPizzaStore();
    void tryAgain();
    void ShowPizzaList();
    bool ProcessOrder(EN_PizzaMenu menu);

private:
    void addMenu();
    void modifyMenu();
    void deleteMenu();
    void confirmSales();
    void pushbackMenu();
    bool accountIngredient(std::string PizzaName);
    
    
    std::vector<EN_PizzaMenu> GetTotalPizza();
    void noStock();

   

    int Money = 100000;

    

    IngredientStore *ingreStore;
    std::vector<EN_PizzaMenu> pizzaMenuVector;
    //std::map<EN_PizzaMenu, std::vector<std::string>> pizzaIngreMap;
    //std::vector<PizzaMenu> pizzaIngreVecotr;

    std::map<std::string, int> pizzaSalesMap;
    //std::map<string, int> ;
    //int totalSales;

};

