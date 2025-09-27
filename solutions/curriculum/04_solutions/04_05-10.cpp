#include <iostream>

using namespace std;

// 05 - Írj függvényt, ami kiírja egy tömb elemeit!
void kiir_tomb(const int tomb[], size_t meret)
{
    for (size_t i = 0; i < meret; ++i) {
        cout << "A tomb " << i << ". eleme: " << tomb[i] << endl;
    }
}

// 06 - Írj függvényt, ami megszámolja, hány páros szám van egy tömbben!
int paros_szamok_szama(const int tomb[], size_t meret)
{
    int db = 0;
    for (size_t i = 0; i < meret; ++i) {
        if (tomb[i] % 2 == 0) {
            ++db;
        }
    }
    return db;
}

// 07 - Írj egy függvényt, ami megkeresi egy tömb legnagyobb elemét!  
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

// Swap függvény a két érték helycseréjéhez
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 08 - Írj egy függvényt, ami rendezi egy tömb elemeit növekvő sorrendbe!
void rendezes_novekvo(int tomb[], size_t meret)
{
    for (size_t i = 0; i < meret - 1; ++i) {
        for (size_t j = i + 1; j < meret; ++j) {
            if (tomb[i] > tomb[j]) {
                swap(tomb[i], tomb[j]);
            }
        }
    }
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

// 10 - Írj függvényt, ami kiszámolja egy 3×3-as mátrix főátlójának összegét!
int foatlo_osszeg(const int matrix[3][3])
{
    int osszeg = 0;
    for (size_t i = 0; i < 3; ++i) {
        osszeg += matrix[i][i];
    }
    return osszeg;
}

int main()
{
    int tomb[5] = {10, 20, 30, 40, 50};
    kiir_tomb(tomb, sizeof(tomb) / sizeof(tomb[0]));

    cout << "A paros szamok szama: " << paros_szamok_szama(tomb, sizeof(tomb) / sizeof(tomb[0])) << endl;

    int tomb2[6] = {3, 1, 4, 1, 5, 9};
    cout << "A tomb legnagyobb eleme: " << legnagyobb_elem(tomb2, sizeof(tomb2) / sizeof(tomb2[0])) << endl;
    rendezes_novekvo(tomb2, sizeof(tomb2) / sizeof(tomb2[0]));
    cout << "A tomb rendezve: " << endl;
    kiir_tomb(tomb2, sizeof(tomb2) / sizeof(tomb2[0]));

    int matrix2x3[2][3] = {{1, 2, 3}, {4, 5, 6}};
    kiir_matrix(matrix2x3);
    int matrix3x3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "A 3x3-as matrix foatlajanak osszege: " << foatlo_osszeg(matrix3x3) << endl;

    return 0;
}