#include "bar.h"

int main() {
    Drink* drinks = new Drink[Bar::MAX_DRINKS];
    int count = 0;

    Bar::menu(drinks, count);

    delete[] drinks;

    return 0;
}