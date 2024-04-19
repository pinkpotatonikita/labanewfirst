#pragma once

#include "drink.h"

namespace Bar {
    const int MAX_DRINKS = 150;

    void saveToFile(Drink* drinks, int count);
    Drink* readFromFile(int& count);
    Drink* addDrink(Drink* drinks, int& count);
    void deleteDrink(Drink* drinks, int& count);
    void editDrink(Drink* drinks, int count);
    void searchDrink(Drink* drinks, int count);
    void displayDrinks(Drink* drinks, int count);
    void menu(Drink*& drinks, int& count);
}

