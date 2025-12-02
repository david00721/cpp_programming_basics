// Készíts Product structot name (string), price (int), quantity (int) mezőkkel. Tárolj egy tömbben 5 terméket, és írd ki a teljes raktárértéket (összesen mennyi pénzt ér a készlet).

#include <iostream>
#include <string>

struct Product {
    std::string name;
    int price;
    int quantity;
};

int calculateInventoryValue(const Product products[], int size) {
    int totalValue = 0;
    for (int i = 0; i < size; ++i) {
        totalValue += products[i].price * products[i].quantity;
    }
    return totalValue;
}

int main() {
    Product products[5] = {
        {"Apple", 100, 50},
        {"Banana", 50, 100},
        {"Orange", 80, 70},
        {"Grapes", 200, 30},
        {"Mango", 150, 40}
    };

    std::cout << "Total inventory value: " << calculateInventoryValue(products, 5) << " HUF" << std::endl;

    return 0;
}