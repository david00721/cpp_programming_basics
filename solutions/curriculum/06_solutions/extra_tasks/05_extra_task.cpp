/*
#5. feladat - Mátrix → vektor JPEG-hez hasonló bejárással
Definiálja azt az int* mtx2vec(int** mtx, int n) függvényt, ami egy n x n négyzetes mátrix elemeit egy adott „cikk-cakk / átlós” sorrendben végigjárja (JPEG-szerű bejárás), és egy dinamikusan létrehozott, azonos elemszámú vektorba írja azokat.
Ez utóbbi címe a visszatérési érték.
*/

#include <iostream>

// Example 4x4 matrix traversal:
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
// 13 14 15 16
//
// Traversal order:
// 1
// 2 5
// 9 6 3
// 4 7 10 13
// 14 11 8
// 12 15
// 16

int* mtx2vec(int** mtx, int n) {
    int* vec = new int[n * n];
    int index = 0;

    for (int sum = 0; sum <= 2 * (n - 1); ++sum) {
        if (sum % 2 == 0) {
            for (int i = 0; i <= sum; ++i) {
                int j = sum - i;
                if (i < n && j < n) {
                    vec[index++] = mtx[i][j];
                }
            }
        } else {
            for (int j = 0; j <= sum; ++j) {
                int i = sum - j;
                if (i < n && j < n) {
                    vec[index++] = mtx[i][j];
                }
            }
        }
    }

    return vec;
}

int main() {
    int n = 4;
    int** matrix = new int*[n];
    int counter = 1;

    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = counter++;
        }
    }

    int* vector = mtx2vec(matrix, n);

    std::cout << "Matrix to Vector Traversal:" << std::endl;
    for (int i = 0; i < n * n; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;

    return 0;
}