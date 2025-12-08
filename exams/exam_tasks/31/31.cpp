#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const int ROWS = 5;
const int COLS = 3;

// Prototype - implement this function
double** sinTetel(string fbe);

int main() {
    // 1. helyes fájlnévvel teszt
    double** szkb = sinTetel("Bfk_alfa.txt");
    if (szkb) {
        for (int i = 0; i < ROWS; i++) {
            cout << szkb[i][0] << " " << szkb[i][1] << " " << szkb[i][2] << endl;
        }
        for (int i = 0; i < ROWS; i++) {
            delete[] szkb[i];
        }
        delete[] szkb;
        szkb = 0;
    }

    cout << endl;

    // 2. hibás fájlnévvel teszt
    double** szkb2 = sinTetel("NoBfk_alfa.txt");
    if (szkb2) {
        for (int i = 0; i < ROWS; i++) {
            cout << szkb2[i][0] << " " << szkb2[i][1] << " " << szkb2[i][2] << endl;
        }
        for (int i = 0; i < ROWS; i++) {
            delete[] szkb2[i];
        }
        delete[] szkb2;
        szkb2 = 0;
    }

    return 0;
}
