#pragma once
#include "PizzaStore.h"

class Consumer
{
public:
    Consumer();
    Consumer(PizzaStore* PizzaStore);
    ~Consumer();


    PizzaStore* PizzaStore;



    bool order();

};

