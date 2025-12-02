#include <iostream>

// Láncolt lista struktúra egy ingatlanhoz
struct IngatlanLista
{
    double area;         // terület négyzetméterben
    long long value;     // érték forintban
    IngatlanLista *next; // következő listaelem címe
};

// Beszúrás a lista elejére
IngatlanLista *beszurElejere(IngatlanLista *head, double area, long long value)
{
    IngatlanLista *newNode = new IngatlanLista{area, value, head};
    return newNode; // az új fej
}

// Az összterület kiszámítása
double totalArea(const IngatlanLista *head)
{
    double sum = 0.0;
    const IngatlanLista *p = head;
    while (p != nullptr)
    {
        sum += p->area;
        p = p->next;
    }
    return sum;
}

// Az átlagos ingatlanérték meghatározása az összterület felhasználásával
// Itt az átlagos érték = ÖSSZÉRTÉK / ÖSSZTERÜLET (Ft / m²)
double averageArea(const IngatlanLista *head)
{
    double areaSum = 0.0;
    long long valueSum = 0;

    const IngatlanLista *p = head;
    while (p != nullptr)
    {
        areaSum += p->area;
        valueSum += p->value;
        p = p->next;
    }

    if (areaSum == 0.0)
    {
        // nincs terület, ne osszunk nullával
        return 0.0;
    }

    return static_cast<double>(valueSum) / areaSum;
}

// Lista felszabadítása
void clear(IngatlanLista *&head)
{
    while (head != nullptr)
    {
        IngatlanLista *tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Teszt a feladatban megadott példával
int main()
{
    IngatlanLista *list = nullptr;

    list = beszurElejere(nullptr, 10.0, 1000);
    list = beszurElejere(list, 5.0, 500);
    list = beszurElejere(list, 5.0, 500);

    std::cout << totalArea(list) << '\n';
    std::cout << averageArea(list) << '\n';

    clear(list);
    return 0;
}