#include <iostream>

//01 - Kérj be egy n számot, foglalj dinamikus tömböt, töltsd fel véletlen páros számokkal, majd számold ki az összegüket.

// Függvény: foglalj dinamikus tömböt, töltsd fel véletlen páros számokkal
int* foglal_es_random_feltolt(const int* n) {
    int* tomb = new int[*n];
    // pointer aritmetikaval
    for (int i = 0; i < *n; i++) {
        *(tomb + i) = rand() % 100 * 2;  // Véletlen páros szám generálása

        // if ((rand() % 100) % 2 == 0) {
        //     *(tomb + i) = rand() % 100;
        // } else {
        //     *(tomb + i) = (rand() % 100) + 1;
        // }
    }

    // for (int i = 0; i < *n; i++) {
    //     tomb[i] = rand() % 100 * 2;  // Véletlen páros szám generálása
    // }
    return tomb;
}

void print(int* tomb, const int n) {
    // pointer aritmetikaval
    for (int i = 0; i < n; i++) {
        std::cout << *(tomb + i) << " ";
    }
    std::cout << std::endl;

    // for (int i = 0; i < n; i++) {
    //     std::cout << tomb[i] << " ";
    // }
    // std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Add meg az n erteket: ";
    std::cin >> n;

    int* tomb = foglal_es_random_feltolt(&n);

    // Kiir
    std::cout << "A tomb elemei: ";
    print(tomb, n);

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