#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "PizzaDef.h"

class Pizza
{
public:
    Pizza(const EN_PizzaMenu& type, int price) :
        Type(type), Price(price) 
    {
        Ingredients.push_back("dough");
        Ingredients.push_back("tomato");
        Ingredients.push_back("cheese");
    }

    ~Pizza() {}

    virtual void showInfo() // ���� �Լ�
    {
        //std::cout << "�̸�: " << Name << std::endl;
        //std::cout << "���: " << Ingredients << std::endl;
        std::cout << "����: " << Price << std::endl;
    }

    virtual void addIngredients() = 0;  // ���� ���� �Լ�

    std::vector<std::string> getIngredients() { return Ingredients; }
    int getPrice() { return Price; }

    // ���� ���� �Լ� = �ڽĿ��� �������ϰԲ� ����(���Ǹ� �ڽĿ��� ����)
    // ���� ���� �Լ��� �ݵ�� �ڽĿ��� ������ ����� ��
    // ���� ���� �Լ��� �ϳ��� �ִ� Ŭ����(�߻� Ŭ����)�� �ν��Ͻ�(��ü) ���� �Ұ�(��, �ڽ��� ���ؼ��� ����, �ڽ��� ���ؼ��� ����)
    // ������ ��� C++/�ڹ�/Go ��ũ��Ʈ ��� JS/Python
    // virtual Ű����, ���� �Լ�, ���� ���� �Լ�, �߻� Ŭ����, ������

protected:
    EN_PizzaMenu Type;
    std::vector<std::string> Ingredients;
    int Price;
};

class HawaiianPizza : public Pizza
{
public:
    HawaiianPizza() : Pizza(en_Hawaiian, 16000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("pineapple");
        Ingredients.push_back("pork");
        //Ingredients.push_back("");
        //Ingredients.assign(s.begin(), s.end());
    }
};

class BulgogiPizza : public Pizza
{
public:
    BulgogiPizza() : Pizza(en_Bulgogi, 20000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("bulgogi");
        Ingredients.push_back("onion");
    }
};


class CheesePizza : public Pizza
{
public:
    CheesePizza() : Pizza(en_Cheese, 20000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("mozzallela");
        Ingredients.push_back("olive oil");
    }
};

class CombiPizza : public Pizza
{
public:
    CombiPizza() : Pizza(en_Combi, 20000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("ham");
        Ingredients.push_back("salami");
    }
};

class PotatoPizza : public Pizza
{
public:
    PotatoPizza() : Pizza(en_Potato, 20000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("potato");
        Ingredients.push_back("pasli");
    }
};