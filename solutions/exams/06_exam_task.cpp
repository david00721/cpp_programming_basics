#include <iostream>
#include <cmath>

using namespace std;

/*
Definiálja a double* gp(double a1, double q, int n) függvényt, mely visszatér egy n elemű tömbbel,
amelynek elemei az a1 értékű első taggal rendelkező, q kvóciensű mértani sorozat egymást követő tagjai.
*/

double* gp(double a1, double q, int n) {
    // Dinamikus tömb lefoglalása n elemre
    double* arr = new double[n];
    // Sorozat elemeinek kiszámítása: a1, a1*q, a1*q^2, ...
    for (int i = 0; i < n; ++i) {
        arr[i] = a1 * pow(q, i);
    }
    // Visszaadjuk a tömböt (a hívónak kell majd delete[]-tel felszabadítani)
    return arr;
}

void printAndClear(double* arr, int n) {
    // Kiírjuk a tömb tartalmát
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Felszabadítjuk a dinamikus tömböt, hogy ne szivárogjon memória
    delete[] arr;
}

int main()
{
    // 3 első tag, 3 kvóciens, 5 elemű sorozat: 3, 9, 27, 81, 243
    printAndClear(gp(3, 3, 5), 5);

    // 2 első tag, 2 kvóciens, 6 elemű sorozat: 2, 4, 8, 16, 32, 64
    printAndClear(gp(2, 2, 6), 6);

    // 1 első tag, 0.5 kvóciens, 4 elemű sorozat: 1, 0.5, 0.25, 0.125
    printAndClear(gp(1, 0.5, 4), 4);

    return 0; // Program vége
}
