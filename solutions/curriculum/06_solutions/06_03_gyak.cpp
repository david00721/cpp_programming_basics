#include <iostream>

// Függvény: Fűzz össze két dinamikusan foglalt integer tömböt egy harmadikba.
int* fuzze_ossze(int* arr1, int* arr2, int size1, int size2) {
    int* result = new int[size1 + size2];
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
    return result;
}

int main() {
    int size1 = 5;
    int size2 = 3;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    for (int i = 0; i < size1; i++) {
        arr1[i] = i; // 0 to size1-1
    }

    for (int i = 0; i < size2; i++) {
        arr2[i] = size1 + i; // size1 to size1+size2-1
    }

    int* merged = fuzze_ossze(arr1, arr2, size1, size2);
    for (int i = 0; i < size1 + size2; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged;
    return 0;
}
