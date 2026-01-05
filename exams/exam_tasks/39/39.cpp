#include <iostream>

const int COLS = 5;

// Prototype - implement this function
void manhattan(int mtx[][COLS], int rows);

int main()
{
    const int ROWS = 4;
    int matrix[ROWS][COLS];

    manhattan(matrix, ROWS);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*
    Expected output:
    0 1 2 3 4 
    1 2 3 4 5 
    2 3 4 5 6 
    3 4 5 6 7
    */

    return 0;
}
