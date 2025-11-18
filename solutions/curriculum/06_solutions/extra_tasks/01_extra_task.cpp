/*

1. feladat – Mértani sorozat

Definiálja a double* gp(double a1, double q, int n) függvényt, mely visszatér egy n elemű tömbbel, amelynek elemei az a1 értékű első taggal rendelkező, q kvóciensű mértani sorozat egymást követő tagjai.
*/

#include <iostream>

// Mértani sorozat generálása
// a1: első tag, q: kvóciens, n: sorozat hossza
// Visszatér egy n elemű tömbbel, amely a mértani sorozat elemeit tartalmazza
// Képlet: an = a1 * q^(n-1)
// Példa: gp(2, 3, 4) -> {2, 6, 18, 54}

double* gp(double a1, double q, int n) {
    double* series = new double[n];
    for (int i = 0; i < n; ++i) {
        // #include <cmath> használata esetén:
        // series[i] = a1 * pow(q, i);

        series[i] = a1;
        for (int j = 0; j < i; ++j) {
            series[i] *= q;
        }
    }

    /*
    series[0] = a1;
    for (int i = 1; i < n; ++i) {
        series[i] = series[i - 1] * q;
    }
    */
    return series;
}

int main() {
    int n;
    double a1, q;

    std::cout << "Adja meg az első tagot (a1): ";
    std::cin >> a1;
    std::cout << "Adja meg a kvóciens értékét (q): ";
    std::cin >> q;
    std::cout << "Adja meg a sorozat hosszát (n): ";
    std::cin >> n;

    double* series = gp(a1, q, n);

    std::cout << "A mértani sorozat elemei: ";
    for (int i = 0; i < n; ++i) {
        std::cout << series[i] << " ";
    }
    std::cout << std::endl;

    delete[] series;
    return 0;
}
