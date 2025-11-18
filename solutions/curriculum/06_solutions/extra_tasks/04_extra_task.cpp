/*
4. feladat - Csigavonalban feltöltött mátrix

Definiálja azt az int** snail(int size) függvényt, amely létrehoz egy size x size méretű dinamikus mátrixot, majd a bal felső saroktól elindulva csigavonalban 1-től kezdődően növekvő számokat ír bele, amíg az összes mező ki nem töltődik!
A visszatérési érték a kitöltött mátrix (vektorokat címző mutatótömb).

*/

#include <iostream>

int** snail(int size) {
    // Create dynamic matrix
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    
    int value = 1;
    int top = 0, bottom = size - 1;
    int left = 0, right = size - 1;
    
    while (top <= bottom && left <= right) {
        // Fill top row (left to right)
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;
        
        // Fill right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;
        
        // Fill bottom row (right to left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }
        
        // Fill left column (bottom to top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
    
    return matrix;
}

int main() {
    int size = 5; // Example size
    int** matrix = snail(size);
    
    // Print the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}