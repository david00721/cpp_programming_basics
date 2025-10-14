#include <iostream>

using namespace std;

/*
1. feladat – Mátrix beolvasása és kiíratása
Kérd be a felhasználótól egy 3x3-as egész mátrix elemeit, majd írd ki a mátrixot formázottan a képernyőre.
*/

void readMatrix(int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Kerem a(z) " << i + 1 << ". sor " << j + 1 << ". elemet: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
2. feladat - Mátrix fő és mellék átlóinak összege
Használd a korábbi mátrixot, és számold ki a főátló és a mellékátló elemeinek összegét. 
*/

int calculateMainDiagonalSum(const int matrix[][3], int rows) {
    int mainDiagonalSum = 0;
    for (int i = 0; i < rows; i++) {
        mainDiagonalSum += matrix[i][i];
    }
    return mainDiagonalSum;
}

int calculateSecondaryDiagonalSum(const int matrix[][3], int rows) {
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < rows; i++) {
        secondaryDiagonalSum += matrix[i][rows - 1 - i];
        // alternate: secondaryDiagonalSum += matrix[i][2 - i];
    }
    return secondaryDiagonalSum;
}

/*
3. feladat - Soronkénti és oszloponkénti összeg
Számold ki minden sor és minden oszlop összegét, majd írd ki őket külön-külön.
*/

void calculateRowSum(const int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += matrix[i][j];
        }
        cout << "A(z) " << i + 1 << ". sor osszege: " << rowSum << endl;
    }
}

void calculateColumnSum(const int matrix[][3], int rows) {
    for (int i = 0; i < 3; i++) {
        int colSum = 0;
        for (int j = 0; j < rows; j++) {
            colSum += matrix[j][i];
        }
        cout << "A(z) " << i + 1 << ". oszlop osszege: " << colSum << endl;
    }
}

/*
4. feladat - Mátrix transzponálása
Készíts egy függvényt, amely a egy bemeneti mátrixot transzponál (sorok és oszlopok megcserélése).
*/

void transposeMatrix(const int matrix[][3], int output[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            output[j][i] = matrix[i][j];
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void transposeMatrix2(int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

/*
5. feladat - Két mátrix szorzása
Deklarálj egy 3×3-as mátrixot, majd szorozd őket össze (klasszikus mátrixszorzás), és írd ki az eredményt.
Deklarálj egy 2x3-as mátrixot és egy 3x2-es mátrixot, majd szorozd őket össze (klasszikus mátrixszorzás), és írd ki az eredményt.
*/

int main() {

    // Mátrix elemeinek beolvasása

    // int matrix[3][3];
    // readMatrix(matrix, rows);
    
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = sizeof(matrix) / sizeof(matrix[0]);

    // Mátrix kiíratása
    printMatrix(matrix, rows);

    int mainDiagonalSum = calculateMainDiagonalSum(matrix, rows);
    int secondaryDiagonalSum = calculateSecondaryDiagonalSum(matrix, rows);

    cout << "Foatlo osszege: " << mainDiagonalSum << endl;
    cout << "Mellekatlo osszege: " << secondaryDiagonalSum << endl;

    calculateRowSum(matrix, 3);
    calculateColumnSum(matrix, 3);

    int transposed[3][3];
    transposeMatrix(matrix, transposed, rows);
    cout << "Transzponalt matrix:" << endl;
    printMatrix(transposed, 3);

    int transposed2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    transposeMatrix2(transposed2, 3);
    cout << "Helyben transzponalt matrix:" << endl;
    printMatrix(transposed2, rows);

    return 0;
}