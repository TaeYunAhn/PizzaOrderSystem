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
    
    virtual void showInfo() // ���� �Լ�
    {
       //std::cout << "�̸�: " << Name << std::endl;
       //std::cout << "���: " << Ingredients << std::endl;
        std::cout << "����: " << Price << std::endl;
    }

    virtual void setIngredients() 
    {
        Ingredients.push_back("d");
        Ingredients.push_back("k");
        Ingredients.push_back("t");
    }
    //virtual void setIngredients() = 0;  // ���� ���� �Լ�

    // ���� ���� �Լ��� �ݵ�� �ڽĿ��� ������ ����� ��
    // ���� ���� �Լ��� �ϳ��� �ִ� Ŭ����(�߻� Ŭ����)�� �ν��Ͻ�(��ü) ���� �Ұ�(��, �ڽ��� ���ؼ��� ����)
    
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

        Ingredients.push_back("���ξ���");
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

