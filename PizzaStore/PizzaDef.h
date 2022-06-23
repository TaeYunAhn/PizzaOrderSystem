#pragma once
#include <array>
#include <string>
enum enPizzaMenu
{
	PIZZA_START,
    HAWAIIAN_PIZZA,
    CHEESE_PIZZA,
    COMBINATION_PIZZA,
    BULGOGI_PIZZA,
    POTATO_PIZZA,
    PIZZA_TOTAL,
};

static enPizzaMenu getPizzaNum(const std::string& name)
{
	std::array<std::string, PIZZA_TOTAL> pizzaName = { "", "cheese", "combi", "hawaiian", "potato", "bulgogi" };
	for (int i = 1; i < PIZZA_TOTAL; i++)
	{
		if (pizzaName[i] == name)
			return enPizzaMenu(i);
	}

	return PIZZA_TOTAL;
};

static std::string getPizzaName(enPizzaMenu menu)
{
	std::array<std::string, PIZZA_TOTAL> pizzaName = { "", "cheese", "combi", "hawaiian", "potato", "bulgogi" };
	return pizzaName[menu];
};
