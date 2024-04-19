#include "drink.h"

std::string Drink::getName() const {
    return _name;
}

void Drink::setName(std::string& name) {
    _name = name;
}

double Drink::getPrice() const {
    return _price;
}

void Drink::setPrice(double price) {
    _price = price;
}

int Drink::getAlcoholContent() const {
    return _alcoholContent;
}

void Drink::setAlcoholContent(int alcoholContent) {
    _alcoholContent = alcoholContent;
}
