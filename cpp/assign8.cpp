#include <iostream>
#include <list>
#include <string>

using namespace std;

class Items {
private:
    list<int> item_code;
    list<string> item_name;
    list<int> item_quantity;
    list<int> item_cost;

public:
    void get_itemlist();
    void display_itemall();
    void searchlist();
};

void Items::get_itemlist() {
    int count;
    cout << "Enter the number of items: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        int code;
        string name;
        int quantity;
        int cost;

        cout << "Enter item code: ";
        cin >> code;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item quantity: ";
        cin >> quantity;
        cout << "Enter item cost: ";
        cin >> cost;

        item_code.push_back(code);
        item_name.push_back(name);
        item_quantity.push_back(quantity);
        item_cost.push_back(cost);
    }
}

void Items::display_itemall() {
    auto itr_code = item_code.begin();
    auto itr_name = item_name.begin();
    auto itr_quantity = item_quantity.begin();
    auto itr_cost = item_cost.begin();

    cout << "Items List:\n";
    while (itr_code != item_code.end()) {
        cout << "Code: " << *itr_code 
             << ", Name: " << *itr_name 
             << ", Quantity: " << *itr_quantity 
             << ", Cost: " << *itr_cost << endl;

        ++itr_code;
        ++itr_name;
        ++itr_quantity;
        ++itr_cost;
    }
}

void Items::searchlist() {
    int code;
    cout << "Enter item code to search: ";
    cin >> code;

    auto itr_code = item_code.begin();
    auto itr_name = item_name.begin();
    auto itr_quantity = item_quantity.begin();
    auto itr_cost = item_cost.begin();

    bool found = false;

    while (itr_code != item_code.end()) {
        if (*itr_code == code) {
            cout << "Item found: "
                 << "Code: " << *itr_code 
                 << ", Name: " << *itr_name 
                 << ", Quantity: " << *itr_quantity 
                 << ", Cost: " << *itr_cost << endl;
            found = true;
            break;
        }
        ++itr_code;
        ++itr_name;
        ++itr_quantity;
        ++itr_cost;
    }

    if (!found) {
        cout << "Item with code " << code << " not found." << endl;
    }
}

int main() {
    Items itemList;
    itemList.get_itemlist();
    itemList.display_itemall();
    itemList.searchlist();
    return 0;
}