#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matrix[N][N];

    cout << "Adj meg egy 3x3-as matrixot:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Add meg a [" << i + 1 << "][" << j + 1 << "] elemet: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nSorok osszege:\n";
    for (int i = 0; i < N; i++) {
        int sumRow = 0;
        for (int j = 0; j < N; j++) {
            sumRow += matrix[i][j];
        }
        cout << "Sor " << i + 1 << ": " << sumRow << endl;
    }

    cout << "\nOszlopok osszege:\n";
    for (int j = 0; j < N; j++) {
        int sumCol = 0;
        for (int i = 0; i < N; i++) {
            sumCol += matrix[i][j];
        }
        cout << "Oszlop " << j + 1 << ": " << sumCol << endl;
    }

    int total = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            total += matrix[i][j];

    cout << "\nAz osszes elem osszege: " << total << endl;
    return 0;
}