#include <iostream>

using namespace std;

struct IngatlanLista {
    double terulet;
    int ertek;
    IngatlanLista* next;
};

// Prototype - implement this function
IngatlanLista* beszurElejere(IngatlanLista* head, double terulet, int ertek)
{
    IngatlanLista* uj = new IngatlanLista;
    uj->terulet = terulet;
    uj->ertek = ertek;
    uj->next = head;
    return uj;
}

// Prototype - implement this function
double totalArea(const IngatlanLista* head)
{
    double osszTerulet = 0.0;
    const IngatlanLista* current = head;

    while (current) {
        osszTerulet += current->terulet;
        current = current->next;
    }

    return osszTerulet;
}

// Prototype - implement this function
double averageArea(const IngatlanLista* head)
{
    double areaSum = 0.0;
    long long valueSum = 0;

    const IngatlanLista *p = head;
    while (p != nullptr)
    {
        areaSum += p->terulet;
        valueSum += p->ertek;
        p = p->next;
    }

    if (areaSum == 0.0)
    {
        // nincs terület, ne osszunk nullával
        return 0.0;
    }

    return static_cast<double>(valueSum) / areaSum;
}

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
