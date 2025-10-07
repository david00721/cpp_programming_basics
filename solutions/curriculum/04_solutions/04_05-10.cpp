#include <iostream>

using namespace std;

// 05 - Írj függvényt, ami kiírja egy tömb elemeit!
void kiir_tomb(const int tomb[], size_t meret)
{
    for (size_t i = 0; i < meret; ++i) {
        cout << "A tomb " << i << ". eleme: " << tomb[i] << endl;
    }
}

// 06 - Írj függvényt, ami visszaadja a tömb elemeinek átlagát (double típussal)!
double atlag(const int tomb[], size_t meret)
{
    double sum = 0.0;
    for (size_t i = 0; i < meret; ++i) {
        sum += tomb[i];
    }
    return sum / meret;
}

// 07 - Írj programot, ami megkeresi egy tömb legnagyobb elemét!
int legnagyobb_elem(const int tomb[], size_t meret)
{
    int max = tomb[0];
    for (size_t i = 1; i < meret; ++i) {
        if (tomb[i] > max) {
            max = tomb[i];
        }
    }
    return max;
}

// 08 - Írj programot, ami megszámolja, hányszor fordul elő egy adott szám a tömbben!
int fordul_e(const int tomb[], size_t meret, int szam)
{
    int count = 0;
    for (size_t i = 0; i < meret; ++i) {
        if (tomb[i] == szam) {
            count++;
        }
    }
    return count;
}

// 09 - Írj függvényt, ami kiírja egy 2×3-as mátrix minden elemét!  
void kiir_matrix(const int matrix[2][3])
{
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            cout << "A matrix [" << i << "][" << j << "] eleme: " << matrix[i][j] << endl;
        }
    }
}

// 10 - Írj programot, ami kiszámolja egy 3×3-as mátrix mellékátlójának (jobbról-balra) összegét!
int mellekatlo_osszeg(const int matrix[3][3])
{
    int összeg = 0;
    for (size_t i = 0; i < 3; ++i) {
        összeg += matrix[i][2 - i];
    }
    return összeg;
}

int main()
{
    // 05 - Írj függvényt, ami kiírja egy tömb elemeit!
    int tomb[5] = {10, 20, 30, 40, 50};
    kiir_tomb(tomb, sizeof(tomb) / sizeof(tomb[0]));

    // 06 - Írj függvényt, ami visszaadja a tömb elemeinek átlagát (double típussal)!
    double atlag_ertek = atlag(tomb, sizeof(tomb) / sizeof(tomb[0]));
    cout << "A tomb elemeinek atlaga: " << atlag_ertek << endl;

    // 07 - Írj programot, ami megkeresi egy tömb legnagyobb elemét!
    int max_elem = legnagyobb_elem(tomb, sizeof(tomb) / sizeof(tomb[0]));
    cout << "A tomb legnagyobb eleme: " << max_elem << endl;

    // 08 - Írj programot, ami megszámolja, hányszor fordul elő egy adott szám a tömbben!
    int szam = 20;
    int elofordulasok = fordul_e(tomb, sizeof(tomb) / sizeof(tomb[0]), szam);
    cout << "A " << szam << " szam " << elofordulasok << " alkalommal fordul elo a tombben." << endl;

    // 09 - Írj függvényt, ami kiírja egy 2×3-as mátrix minden elemét!  
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    kiir_matrix(matrix);

    // 10 - Írj programot, ami kiszámolja egy 3×3-as mátrix mellékátlójának (jobbról-balra) összegét!
    int matrix3x3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mellekatlo_osszeg_ertek = mellekatlo_osszeg(matrix3x3);
    cout << "A matrix mellekatlojanak osszege: " << mellekatlo_osszeg_ertek << endl;

    return 0;
}