#include "bar.h"
#include <iostream>
#include <fstream>

std::ostream& operator<<(std::ostream& out, const Drink& drink) {
    out << "Name: " << drink._name << ", Price: " << drink._price << ", Alcohol Content: " << drink._alcoholContent << "%" << std :: endl;
    return out;
}

std::istream& operator>>(std::istream& in, Drink& drink) {
    in >> drink._name >> drink._price >> drink._alcoholContent;
    return in;
}

using namespace std;

double realDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, chuchundra." << endl;
    }
    return value;
}

int realIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, chuchundra." << endl;
    }
    return value;
}

namespace Bar {
    void saveToFile(Drink* drinks, int count) {
        ofstream f("drinks.txt");
        if (!f.is_open()) {
            cerr << "Error" << endl;
            return;
        }
        f << count << endl;
        for (int i = 0; i < count; i++)
            f << drinks[i].getName() << " " << drinks[i].getPrice() << " " << drinks[i].getAlcoholContent() << " " << endl;
        cout << "Save: " << count << endl;
        f.close();
    }

    Drink* readFromFile(int& count) {
        ifstream f("drinks.txt");
        if (!f.is_open()) {
            cerr << "Error" << endl;
            return nullptr;
        }
        f >> count;
        if (count < 1) {
            cerr << "Error" << endl;
            return nullptr;
        }
        Drink* drinks_new = new Drink[count];
        for (int i = 0; i < count; i++) {
            string name;
            double price;
            int alcoholContent;
            f >> name >> price >> alcoholContent;
            drinks_new[i].setName(name);
            drinks_new[i].setPrice(price);
            drinks_new[i].setAlcoholContent(alcoholContent);
        }
        cout << "Read:" << count << endl;
        f.close();
        return drinks_new;
    }

    Drink* addDrink(Drink* drinks, int& count) {
        /*if (count < MAX_DRINKS) {
            Drink* drinks_new = new Drink[count + 1];
           for (int i = 0; i < count; i++)
                drinks_new[i] = drinks[i];

            cout << "Enter drink name:";
            string name;
            cin >> name;
            drinks_new[count].setName(name);
            cout << "Enter price:";
            double price;
            cin >> price;
            drinks_new[count].setPrice(price);
            cout << "Enter Alcohol content:";
            int alcoholContent;
            cin >> alcoholContent;
            drinks_new[count].setAlcoholContent(alcoholContent);
            count++;

            /*for (int i = 0; i < count; i++)
                drinks_new[i] = drinks[i];*/
        if (count >= MAX_DRINKS)
            return drinks;
        Drink* drinks_new = new Drink[count + 1];
        for (int i = 0; i < count; i++)
            drinks_new[i] = drinks[i];
        cout << "Enter drink name:";
        string name;
        cin >> name;
        drinks_new[count].setName(name);
        //cout << "Enter price:";
        double price = realDoubleInput("Enter price: ");
        //cin >> price;
        drinks_new[count].setPrice(price);
        //cout << "Enter Alcohol content:";
        int alcoholContent = realIntInput("Enter acohol content: ");
        //cin >> alcoholContent;
        drinks_new[count].setAlcoholContent(alcoholContent);
        count++;

            delete[] drinks;
            return drinks_new;
        /*else {
            cout << "Cannot add more drinks. Maximum limit reached." << endl;
            return drinks;
        };*/
    }

    void deleteDrink(Drink* drinks, int& count) {
        if (count == 0) {
            cout << "No drinks to delete." << endl;
            return;
        }

        cout << "Enter the index of the drink to delete (0-" << count - 1 << "): ";
        int index;
        cin >> index;

        if (index < 0 || index >= count) {
            cout << "Invalid index." << endl;
            return;
        }

        for (int i = index; i < count - 1; ++i) {
            drinks[i] = drinks[i + 1];
        }

        count--;
        cout << "Drink deleted successfully." << endl;
    }

    void editDrink(Drink* drinks, int count) {
        if (count == 0) {
            cout << "No drinks to edit." << endl;
            return;
        }

        cout << "Enter the index of the drink to edit (0-" << count - 1 << "): ";
        int index;
        cin >> index;

        if (index < 0 || index >= count) {
            cout << "Invalid index." << endl;
            return;
        }

        cout << "Enter new details for the drink:" << endl;
        cout << "Enter drink name:";
        string name;
        cin >> name;
        drinks[index].setName(name);
        //cout << "Enter price:";
        double price = realDoubleInput("Enter price: ");
        //cin >> price;
        drinks[index].setPrice(price);
        //cout << "Enter Alcohol content:";
        int alcoholContent = realIntInput("Enter acohol content: ");
        //cin >> alcoholContent;
        drinks[index].setAlcoholContent(alcoholContent);
        cout << "Drink edited successfully." << endl;
    }

    // Реализация функции поиска напитка по имени
    void searchDrink(Drink* drinks, int count) {
        if (count == 0) {
            cout << "No drinks available for searching." << endl;
            return;
        }

        cout << "Enter the name of the drink to search for: ";
        string name;
        cin >> name;

        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (drinks[i].getName() == name) {
                cout << "Drink found:" << endl;
                cout << drinks[i] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Drink not found." << endl;
        }
    }

    void displayDrinks(Drink* drinks, int count) {
        if (drinks == nullptr || count == 0) {
            cout << "No drinks available." << endl;
            return;
        }
            cout << "List of drinks:" << endl;
            for (int i = 0; i < count; i++) {
                cout << drinks[i];
            }
    }

    void menu(Drink*& drinks, int& count) {
        char choice;
        //Drink* d = nullptr;
        do {
            cout << "\nMENU:" << endl;
            cout << "1. Add drink" << endl;
            cout << "2. Delete drink" << endl;
            cout << "3. Edit drink" << endl;
            cout << "4. Search drink" << endl;
            cout << "5. Display all drinks" << endl;
            cout << "6. Save to file" << endl;
            cout << "7. Read from file" << endl;
            cout << "8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                //d = 
                drinks = addDrink(drinks, count);
                break;
            case '2':
                deleteDrink(drinks, count);
                break;
            case '3':
                editDrink(drinks, count);
                break;
            case '4':
                searchDrink(drinks, count);
                break;
            case '5':
                displayDrinks(drinks, count);
                break;
            case '6':
                saveToFile(drinks, count);
                break;
            case '7':
                delete[] drinks;
                //d = 
                drinks = readFromFile(count);
                /*if (d) {
                    delete[] drinks;
                    drinks = d;
                }*/
                break;
            case '8':
                cout << "Exiting program." << endl;
                if (drinks) {
                    delete[] drinks;
                    drinks = nullptr;
                }
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
            }
        } while (choice != '8');
    }
}