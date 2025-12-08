#include <iostream>

using namespace std;

struct Number {
    double value;
    Number* next;
    Number* prev;
};

// Segédfüggvény: kiírás előre, majd visszafelé, végül felszabadítás
void printForwardReverseFree(Number* head) {
    if (!head) return;

    Number* p = head;

    // előre kiírás
    while (p) {
        cout << p->value << " ";
        if (p->next == nullptr) break;
        p = p->next;
    }

    // visszafelé kiírás
    while (p) {
        cout << p->value << " ";
        p = p->prev;
    }

    cout << endl;

    // felszabadítás
    p = head;
    while (p) {
        Number* tmp = p->next;
        delete p;
        p = tmp;
    }
}

// Prototype - implement this function
Number* arithmeticProgression(double a1, double d, int n)
{
    if (n <= 0) return nullptr;

    Number* head = new Number{a1, nullptr, nullptr};
    Number* current = head;

    for (int i = 1; i < n; i++) {
        double value = a1 + i * d;
        Number* node = new Number{value, nullptr, nullptr};

        current->next = node;   // összeláncolás előre
        node->prev = current;   // összeláncolás vissza

        current = node;         // lépünk tovább
    }

    return head;
}

int main() {
    printForwardReverseFree(arithmeticProgression(1, 2, 3));
    // elvárt: 1 3 5 3 1

    printForwardReverseFree(arithmeticProgression(10, -1, 5));
    // elvárt: 10 9 8 7 6 7 8 9 10

    return 0;
}
