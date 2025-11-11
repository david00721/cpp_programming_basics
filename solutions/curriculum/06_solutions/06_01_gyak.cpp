#include <iostream>

//01 - Kérj be egy n számot, foglalj dinamikus tömböt, töltsd fel véletlen páros számokkal, majd számold ki az összegüket.

// Függvény: foglalj dinamikus tömböt, töltsd fel véletlen páros számokkal
int* foglal_es_random_feltolt(const int* n) {
    int* tomb = new int[*n];
    // pointer aritmetikaval
    for (int i = 0; i < *n; i++) {
        *(tomb + i) = rand() % 100 * 2;  // Véletlen páros szám generálása
    }

    // for (int i = 0; i < *n; i++) {
    //     tomb[i] = rand() % 100 * 2;  // Véletlen páros szám generálása
    // }
    return tomb;
}

int main() {
    int n;
    std::cout << "Add meg az n erteket: ";
    std::cin >> n;

    int* tomb = foglal_es_random_feltolt(&n);

    // Összegzés
    int osszeg = 0;
    // pointer aritmetikaval
    for (int i = 0; i < n; i++) {
        osszeg += *(tomb + i);
    }

    // hagyományos ciklussal
    // for (int i = 0; i < n; i++) {
    //     osszeg += tomb[i];
    // }

    std::cout << "A tomb elemeinek osszege: " << osszeg << std::endl;

    delete[] tomb;  // Ne felejtsd el felszabadítani a dinamikus memóriát
    return 0;
}