#include <iostream>

// Írj függvényt, ami pointer segítségével megfordít egy egész számokat tartalmazó tömböt!
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        swap(arr[i], arr[size - i - 1]);
    }
}


// Írj függvényt, ami pointerrel megkeresi a legnagyobb és legkisebb elem különbségét egy tömbben!
int findDifference(int* arr, int size) {
    int min = *arr;
    int max = *arr;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) < min) min = *(arr + i);
        if (*(arr + i) > max) max = *(arr + i);
    }
    return max - min;
}

// Írj függvényt, ami referencia segítségével összead két számot, és az eredményt egy harmadik változóba írja!
void addNumbers(const int& a, const int& b, int& result) {
    result = a + b;
}

// Írj függvényt, ami pointerrel összehasonlít két stringet, és visszaadja, hogy azonosak-e!
bool compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2) { // mindkét string nem ért véget
        if (*str1 != *str2) return false;
        ++str1;
        ++str2;
    }
    return *str1 == *str2;
}
// Írj függvényt, ami referencia segítségével két számot oszt el egymással, és ha a nevező 0, hibaüzenetet ír ki!
bool divideNumbers(const double& numerator, const double& denominator, double& result) {
    if (denominator == 0) {
        std::cout << "Hiba: Nullával való osztás!" << std::endl;
        return false;
    }
    result = numerator / denominator;
    return true;
}

int main() {
    // Tesztelés
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " "; // Kiírja: 5 4 3 2 1
    }
    std::cout << std::endl;

    int diff = findDifference(arr, 5);
    std::cout << "Különbség: " << diff << std::endl; // Kiírja: Különbség: 4

    int sum;
    addNumbers(3, 4, sum);
    std::cout << "Összeg: " << sum << std::endl; // Kiírja: Összeg: 7

    const char* str1 = "hello";
    const char* str2 = "hello";
    bool areEqual = compareStrings(str1, str2);
    std::cout << "Azonosak-e a stringek? " << (areEqual ? "Igen" : "Nem") << std::endl; // Kiírja: Igen

    double result;
    if (divideNumbers(10.0, 2.0, result)) {
        std::cout << "Eredmény: " << result << std::endl; // Kiírja: Eredmény: 5
    }
    if (!divideNumbers(10.0, 0.0, result)) {
        // Hibaüzenet kiírva a függvényben
    }

    return 0;
}