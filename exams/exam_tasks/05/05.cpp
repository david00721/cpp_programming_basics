#include <iostream>

using namespace std;

// Prototype - implement this function
void stackedBarChart(int** data, int rows, int cols);

// Segédfüggvény: mátrix létrehozása egy 1D vektorból
int** createMtx(int* vec, int rows, int cols) {
    int** mtx = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        mtx[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            mtx[i][j] = vec[i * cols + j];
        }
    }
    return mtx;
}

// Segédfüggvény: mátrix felszabadítása
void deleteMtx(int** mtx, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int main() {
    // Példa a feladat szövegéből
    int vec1[6] = {
        1, 5,
        3, 3,
        5, 3
    };
    int** data1 = createMtx(vec1, 3, 2);
    cout << "Elso diagram:" << endl;
    stackedBarChart(data1, 3, 2);
    deleteMtx(data1, 3);

    cout << endl;

    // További teszt: több oszlop, mint 5 (csak az elso 5-öt kell rajzolni)
    int vec2[4 * 7] = {
        1, 1, 1, 1, 1, 1, 1,
        0, 2, 0, 2, 0, 2, 0,
        3, 0, 3, 0, 3, 0, 3,
        2, 2, 2, 2, 2, 2, 2
    };
    int** data2 = createMtx(vec2, 4, 7);
    cout << "Masodik diagram (tobb mint 5 oszlop):" << endl;
    stackedBarChart(data2, 4, 7);
    deleteMtx(data2, 4);

    return 0;
}
