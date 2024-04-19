#pragma once

#include <iostream>
#include <string>

class Drink {
private:
    std::string _name;
    double _price;
    int _alcoholContent;
public:
    Drink() : _name(""), _price(0.0), _alcoholContent(0) {}
    Drink(std::string& name, double price, int alcoholContent) : _name(name), _price(price), _alcoholContent(alcoholContent) {}
    ~Drink() {}

    std::string getName() const;
    void setName(std::string& name);
    double getPrice() const;
    void setPrice(double price);
    int getAlcoholContent() const;
    void setAlcoholContent(int alcoholContent);

    friend std::ostream& operator<<(std::ostream& out, const Drink& drink);
    friend std::istream& operator>>(std::istream& in, Drink& drink);
};