

#include <iostream>

int main() {
    // 01 - Feladat közösen: Írj programot, ami kiírja egy változó címét és értékét!

    int number = 42;
    std::cout << "Value: " << number << std::endl;
    std::cout << "Address: " << &number << std::endl;

    // 02 - Írj programot, ami pointer segítségével növeli egy változó értékét 5-tel!
    int* ptr = &number;
    *ptr += 5;
    std::cout << "New Value: " << number << std::endl;

    // 03 - Írj programot, ami pointeren keresztül ad új értéket egy változónak!
    int newValue = 100;
    ptr = &newValue;
    std::cout << "Pointer now points to value: " << *ptr << std::endl;
    *ptr = 200;
    std::cout << "New value of newValue: " << newValue << std::endl;

    // 04 - Írj programot, ami pointer segítségével három változó közül a legnagyobb értéket adja vissza!
    int a = 10, b = 25, c = 15;
    int* maxPtr = &a;

    if (*maxPtr < b) {
        maxPtr = &b;
    }
    if (*maxPtr < c) {
        maxPtr = &c;
    }

    std::cout << "Maximum value: " << *maxPtr << std::endl;

    // 05 - Írj programot, ami pointer segítségével kiír egy tömb minden elemét!
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
    }

    // 06 - Írj programot, ami pointer segítségével megszámolja, hány páros elem van egy tömbben!
    int evenCount = 0;
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) % 2 == 0) {
            evenCount++;
        }
    }

    std::cout << "Number of even elements: " << evenCount << std::endl;

    // 07 - Írj programot, ami pointer aritmetikával bejárja egy tömb elemeit!  
    std::cout << "Array elements using pointer arithmetic:" << std::endl;
    for (int* p = arr; p < arr + size; ++p) {
        std::cout << *p << std::endl;
    }

    // 08 - Írj programot, ami pointer aritmetikával megkeresi a legkisebb elemet egy tömbben!
    int* minPtr = arr;
    for (int* p = arr; p < arr + size; ++p) {
        if (*p < *minPtr) {
            minPtr = p;
        }
    }

    std::cout << "Minimum value: " << *minPtr << std::endl;

    return 0;
}