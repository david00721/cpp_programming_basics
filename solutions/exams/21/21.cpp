#include <iostream>

using namespace std;

struct IngatlanLista {
    double terulet;
    int ertek;
    IngatlanLista* next;
};

// Prototype - implement this function
IngatlanLista* beszurElejere(IngatlanLista* head, double terulet, int ertek);

// Prototype - implement this function
double totalArea(const IngatlanLista* head);

// Prototype - implement this function
double averageArea(const IngatlanLista* head);

int main() {
    IngatlanLista* list = nullptr;

    list = beszurElejere(nullptr, 10.0, 1000);
    list = beszurElejere(list, 5.0, 500);
    list = beszurElejere(list, 5.0, 500);

    cout << totalArea(list) << '\n';     // elvárt: 20
    cout << averageArea(list) << '\n';   // elvárt: 100

    // felszabadítás
    while (list) {
        IngatlanLista* tmp = list->next;
        delete list;
        list = tmp;
    }

    return 0;
}
