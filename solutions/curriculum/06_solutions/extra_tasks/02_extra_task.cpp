/*
2. feladat - Szélső elemek körbetolása mátrixon

Készítsen double **shift(double **mtx, int w, int h) függvényt, ahol mtx egy kétdimenziós tömb, w az első, h a második dimenzió hossza. A függvény visszatérési értéke legyen mtx tömbbel megegyező méretű tömb.
A kimeneti tömb az mtx értékeit tartalmazza, azzal a különbséggel, hogy a tömb szélein (első/utolsó sor, első/utolsó oszlop) található elemeket az óramutató járásával megegyező irányba eggyel arrébb mozgatja.

*/

#include <iostream>

// 4x4 example:
// Original matrix:         Result matrix:
// 1  2  3  4               5  1  2  3
// 5  6  7  8        -->    9  6  7  4
// 9 10 11 12               13 10 11  8
//13 14 15 16               14 15 16 12

double **shift(double **mtx, int w, int h) {
    // Create result matrix
    double **result = new double*[h];

    // Copy original matrix to result
    for (int i = 0; i < h; ++i) {
        result[i] = new double[w];
        for (int j = 0; j < w; ++j) {
            result[i][j] = mtx[i][j];
        }
    }

    // Shift top row
    for (int j = 0; j < w - 1; ++j) {
        result[0][j + 1] = mtx[0][j];
    }
    // Shift right column
    for (int i = 0; i < h - 1; ++i) {
        result[i + 1][w - 1] = mtx[i][w - 1];
    }
    // Shift bottom row
    for (int j = w - 1; j > 0; --j) {
        result[h - 1][j - 1] = mtx[h - 1][j];
    }
    // Shift left column
    for (int i = h - 1; i > 0; --i) {
        result[i - 1][0] = mtx[i][0];
    }

    return result;
}

int main() {
    const int w = 4;
    const int h = 4;

    // Create and fill original matrix
    double **mtx = new double*[h];
    int value = 1;
    for (int i = 0; i < h; ++i) {
        mtx[i] = new double[w];
        for (int j = 0; j < w; ++j) {
            mtx[i][j] = value++;
        }
    }

    // Shift the matrix
    double **shiftedMtx = shift(mtx, w, h);

    // Print the result
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << shiftedMtx[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < h; ++i) {
        delete[] mtx[i];
        delete[] shiftedMtx[i];
    }
    delete[] mtx;
    delete[] shiftedMtx;

    return 0;
}