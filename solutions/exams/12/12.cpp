#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    int pcs;
};

// Prototype - implement this function
void total(const Product* p, int n)
{
    for (int i = 0; i < n; ++i) {
        const string currentName = p[i].name;
        int sum = 0;

        bool alreadyProcessed = false;
        for (int j = 0; j < i; ++j) {
            if (p[j].name == currentName) {
                alreadyProcessed = true;
                break;
            }
        }
        if (alreadyProcessed) {
            continue;
        }

        for (int k = 0; k < n; ++k) {
            if (p[k].name == currentName) {
                sum += p[k].pcs;
            }
        }

        cout << currentName << " " << sum << endl;
    }
}

int main() {
    Product p[] = {
        {"alma", 3},
        {"barack", 2},
        {"alma", 4},
        {"citrom", 1},
        {"barack", 1}
    };
    int n = sizeof(p) / sizeof(Product);

    total(p, n);

    // További teszt: teljesen más elrendezés
    cout << endl;

    Product p2[] = {
        {"TV", 1},
        {"Laptop", 3},
        {"TV", 2},
        {"Eger", 5},
        {"Laptop", 1},
        {"Billentyuzet", 4}
    };
    int n2 = sizeof(p2) / sizeof(Product);

    total(p2, n2);

    return 0;
}
