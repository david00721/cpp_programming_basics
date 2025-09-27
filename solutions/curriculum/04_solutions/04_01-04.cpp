#include <iostream>

using namespace std;

int main()
{
    // 01 - Hozz létre egy 5 elemű tömböt, töltsd fel számokkal, majd írd ki az első és utolsó elemét!
    int tomb[5] = {1, 2, 3, 4, 5};
    cout << "Az elso elem: " << tomb[0] << endl;
    cout << "Az utolso elem: " << tomb[4] << endl;

    // 02 - Hozz létre egy 10 elemű tömböt, és írd ki a középső elemet!
    int tomb2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t kozepso_index = sizeof(tomb2) / sizeof(tomb2[0]) / 2;
    cout << "A kozepső elem: " << tomb2[kozepso_index] << endl;

    // 03 - Írj programot, ami kiírja egy tömb minden elemét for ciklussal!  
    for (size_t i = 0; i < sizeof(tomb2) / sizeof(tomb2[0]); ++i) {
        cout << "A tomb " << i << ". eleme: " << tomb2[i] << endl;
    }
    // Alternatív megoldás range-based for ciklussal
    for (const auto& elem : tomb2) {
        cout << "A tomb eleme: " << elem << endl;
    }

    // 04 - Írj programot, ami kiszámolja egy tömb elemeinek összegét!
    int osszeg = 0;

    for (size_t i = 0; i < sizeof(tomb2) / sizeof(tomb2[0]); ++i) {
        osszeg += tomb2[i];
    }

    // Alternatív megoldás range-based for ciklussal
    for (const auto& elem : tomb2) {
        osszeg += elem;
    }
    cout << "A tomb elemeinek osszege: " << osszeg << endl;

    return 0;
}