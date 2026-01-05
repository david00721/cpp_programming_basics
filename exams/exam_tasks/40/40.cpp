#include <iostream>

// Prototype - implement this function
int** snail(int size)
{
    if (size <= 0) return 0;

    int** m = new int*[size];
    for (int i = 0; i < size; ++i) {
        m[i] = new int[size];
        for (int j = 0; j < size; ++j) m[i][j] = 0;
    }

    int top = 0;
    int bottom = size - 1;
    int left = 0;
    int right = size - 1;

    int val = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) m[top][j] = val++;
        top++;

        for (int i = top; i <= bottom; ++i) m[i][right] = val++;
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; --j) m[bottom][j] = val++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) m[i][left] = val++;
            left++;
        }
    }

    return m;
}

void freeMatrix(int** m, int size)
{
    if (m == 0) return;
    for (int i = 0; i < size; ++i) delete[] m[i];
    delete[] m;
}

int main()
{
    int size = 5;
    int** mat = snail(size);
    if (mat == 0) return 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    freeMatrix(mat, size);

    /*
    Expected output for size = 5:
    1	2	3	4	5
    16	17	18	19	6
    15	24	25	20	7
    14	23	22	21	8
    13	12	11	10	9
    */
    return 0;
}
