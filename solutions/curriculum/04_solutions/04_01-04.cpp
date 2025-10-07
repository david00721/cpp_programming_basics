#include <iostream>

using namespace std;

int main()
{
    // 01 - Hozz létre egy 5 elemű tömböt, töltsd fel számokkal, majd írd ki az első és utolsó elemét!
    int tomb[5] = {1, 2, 3, 4, 5};
    cout << "Az elso elem: " << tomb[0] << endl;
    cout << "Az utolso elem: " << tomb[4] << endl;

    // 02 - Hozz létre egy 10 elemű tömböt, és számold ki az elemek átlagát!
    int tomb2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    double sum = 0.0;
    const int n = sizeof(tomb2) / sizeof(tomb2[0]); // Tömb méretének kiszámítása
    for (size_t i = 0; i < n; ++i) {
        sum += tomb2[i];
    }
    double atlag = sum / n;
    cout << "A tomb elemeinek atlaga: " << atlag << endl;

    // 03 - Írj programot, ami kiírja egy tömb minden elemét for ciklussal!  
    for (size_t i = 0; i < n; ++i) {
        cout << "A tomb " << i << ". eleme: " << tomb2[i] << endl;
    }
    // Alternatív megoldás range-based for ciklussal
    for (const auto& elem : tomb2) {
        cout << "A tomb eleme: " << elem << endl;
    }

    // 04 - Írj programot, ami megszámolja, hány páratlan szám van a tömbben!
    int paratlan_szamok = 0;

    for (size_t i = 0; i < n; ++i) {
        if (tomb2[i] % 2 != 0) {
            paratlan_szamok++;
        }
    }

    cout << "A paratlan szamok szama: " << paratlan_szamok << endl;

    return 0;
}