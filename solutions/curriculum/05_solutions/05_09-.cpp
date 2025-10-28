#include <iostream>

// 09 - Írj függvényt, ami pointer paraméterrel módosít egy változót!
void modifyValue(int* ptr) {
    *ptr += 10;
}

// 10 - Írj függvényt, ami pointer paraméterrel négyzetre emeli a változó értékét!
void squareValue(int* ptr) {
    *ptr = (*ptr) * (*ptr);
}

// 11 - Írj programot, ami referencia segítségével módosítja egy változó értékét!
void modifyValueRef(int& ref) {
    ref += 20;
}

// 12 - Írj függvényt, ami referencia segítségével kiszámolja két szám különbségét, és visszaadja az eredményt!
int difference(int& a, int& b) {
    return a - b;
}

// 13 - Írj függvényt, ami referencia segítségével kicserél két számot!
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 14 - Írj függvényt, ami referencia segítségével három szám közül a legnagyobbat állítja be egy változóban!
void setMax(int& max, int& a, int& b, int& c) {
    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
}

// 15 - Írj függvényt, ami const referenciát kap, és kiírja a paramétert!  
void printConstRef(const int& ref) {
    std::cout << "Value: " << ref << std::endl;
}

// 16 - Írj programot, ami const pointert használ, és kiírja egy tömb első és utolsó elemét!
void printArray(const int* arr, int size) {
    if (size > 0) {
        std::cout << "First element: " << *arr << std::endl;
        std::cout << "Last element: " << *(arr + size - 1) << std::endl;
    }
}

// 17 - Írj programot, ami null pointert inicializál, majd ellenőrzi, hogy érvényes-e!  
void checkNullPointer() {
    int* ptr = nullptr;
    if (ptr == nullptr) {
        std::cout << "Pointer is null." << std::endl;
    } else {
        std::cout << "Pointer is valid." << std::endl;
    }
}
// 18 - Írj programot, ami csak akkor dereferál egy pointert, ha nem null és az értéke pozitív!
void safeDereference(int* ptr) {
    if (ptr != nullptr && *ptr > 0) {
        std::cout << "Pointer value: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer is null or value is not positive." << std::endl;
    }
}

// 19 - Írj függvényt, ami pointer segítségével visszaadja egy tömb minimumát!
int findMin(const int* arr, int size) {
    if (size <= 0) return -1; // Return -1 for empty array

    int min = *arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    return min;
}

// 20 - Írj függvényt, ami pointer segítségével megszámolja, hány magánhangzó van egy C-stílusú stringben!
int countVowels(const char* str) {
    int count = 0;
    while (*str != '\0') {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    // 09
    int num1 = 5;
    modifyValue(&num1);
    std::cout << "Modified Value: " << num1 << std::endl;
    // 10
    int num2 = 4;
    squareValue(&num2);
    std::cout << "Squared Value: " << num2 << std::endl;
    // 11
    int num3 = 15;
    modifyValueRef(num3);
    std::cout << "Modified Value (Ref): " << num3 << std::endl;

    // 12
    int a = 20, b = 10;
    int diff = difference(a, b);
    std::cout << "Difference: " << diff << std::endl;

    // 13
    int x = 7, y = 14;
    swap(x, y);
    std::cout << "Swapped Values: " << x << ", " << y << std::endl;

    // 14
    int maxVal;
    int p = 30, q = 25, r = 40;
    setMax(maxVal, p, q, r);
    std::cout << "Max Value: " << maxVal << std::endl;

    // 15
    const int constNum = 50;
    printConstRef(constNum);

    // 16
    int arr[] = {3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    // 17
    checkNullPointer();

    // 18
    int val = 10;
    safeDereference(&val);

    int* nullPtr = nullptr;
    safeDereference(nullPtr);

    // 19
    int arr2[] = {12, 3, 5, 7, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int minVal = findMin(arr2, size2);
    std::cout << "Min Value: " << minVal << std::endl;

    // 20
    const char* testStr = "Hello World!";
    int vowelCount = countVowels(testStr);
    std::cout << "Vowel Count: " << vowelCount << std::endl;

    return 0;
}