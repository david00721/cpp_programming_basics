#include <iostream>

using namespace std;

// Prototype - implement this function
double* gp(double a1, double q, int n)
{
    if (n <= 0) return nullptr;

    double* arr = new double[n];
    arr[0] = a1;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] * q;
    }
    return arr;
}

// Segédfüggvény: tömb kiírása és felszabadítása
void printAndClear(double* arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}

int main() {
    printAndClear(gp(3, 3, 5), 5);   // 3 9 27 81 243
    printAndClear(gp(2, 0.5, 6), 6); // 2 1 0.5 0.25 0.125 0.0625
    printAndClear(gp(1, -2, 5), 5);  // 1 -2 4 -8 16

    return 0;
}