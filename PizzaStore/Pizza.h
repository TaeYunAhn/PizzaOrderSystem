#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "PizzaDef.h"

class Pizza
{
public:
    Pizza(const enPizzaMenu& type, int price) :
        Type(type), Price(price) 
    {
        Ingredients.push_back("dough");
        Ingredients.push_back("tomato");
        Ingredients.push_back("cheese");
    }

    ~Pizza() {}

    virtual void showInfo() // 가상 함수
    {
        //std::cout << "이름: " << Name << std::endl;
        //std::cout << "재료: " << Ingredients << std::endl;
        std::cout << "가격: " << Price << std::endl;
    }

    virtual void addIngredients() = 0;  // 순수 가상 함수

    std::vector<std::string> getIngredients() { return Ingredients; }
    int getPrice() { return Price; }

    // 순수 가상 함수 = 자식에게 재정의하게끔 강제(정의를 자식에게 위임)
    // 순수 가상 함수는 반드시 자식에서 재정의 해줘야 함
    // 순수 가상 함수가 하나라도 있는 클래스(추상 클래스)는 인스턴스(객체) 생성 불가(즉, 자식을 통해서만 구현, 자식을 통해서만 생성)
    // 컴파일 언어 C++/자바/Go 스크립트 언어 JS/Python
    // virtual 키워드, 가상 함수, 순수 가상 함수, 추상 클래스, 다형성

protected:
    enPizzaMenu Type;
    std::vector<std::string> Ingredients;
    int Price;
};

class HawaiianPizza : public Pizza
{
public:
    HawaiianPizza() : Pizza(HAWAIIAN_PIZZA, 16000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("pineapple");
        Ingredients.push_back("pork");
    }
};

class BulgogiPizza : public Pizza
{
public:
    BulgogiPizza() : Pizza(BULGOGI_PIZZA, 20000)
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
    CheesePizza() : Pizza(CHEESE_PIZZA, 15000)
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
    CombiPizza() : Pizza(COMBINATION_PIZZA, 22000)
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
    PotatoPizza() : Pizza(POTATO_PIZZA, 18000)
    {
        addIngredients();
    }

    virtual void addIngredients() override
    {
        Ingredients.push_back("potato");
        Ingredients.push_back("pasli");
    }
};