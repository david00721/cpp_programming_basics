#include <iostream>

// Függvény: Foglaljon le rows × cols méretű mátrixot és adja vissza a legnagyobb elem helyét.

int** lefoglal(const int* rows, const int* cols) {
    int** matrix = new int*[*rows];
    for (int i = 0; i < *rows; i++) {
        matrix[i] = new int[*cols];
    }
    return matrix;
}

void felszabadit(int** matrix, const int* rows) {
    for (int i = 0; i < *rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// legnagyobb elem helye
int* legnagyobb_elem_helye(int** matrix, const int* rows, const int* cols) {
    int* maxPos = new int[2];  // [sor, oszlop]
    maxPos[0] = 0;
    maxPos[1] = 0;
    int maxVal = matrix[0][0];

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxPos[0] = i;
                maxPos[1] = j;
            }
        }
    }
    return maxPos;
}

void print(int** matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    int** myMatrix = lefoglal(&rows, &cols);

    // Mátrix feltöltése random számokkal
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            myMatrix[i][j] = rand() % 100;  // Véletlen szám generálása
        }
    }
    std::cout << "A matrix elemei:" << std::endl;
    print(myMatrix, rows, cols);

    int* maxPos = legnagyobb_elem_helye(myMatrix, &rows, &cols);
    std::cout << "A legnagyobb elem helye: (" << maxPos[0] << ", " << maxPos[1] << ")" << std::endl;
    std::cout << "A legnagyobb elem: " << myMatrix[maxPos[0]][maxPos[1]] << std::endl;
    delete[] maxPos;

    felszabadit(myMatrix, &rows);
    return 0;
}