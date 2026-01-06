#include <iostream>

// Prototype - implement this function
int* mtx2vec(int** mtx, int n);

int** allocMatrix(int n)
{
    int** m = new int*[n];
    for (int i = 0; i < n; ++i) {
        m[i] = new int[n];
        for (int j = 0; j < n; ++j) m[i][j] = 0;
    }
    return m;
}

void freeMatrix(int** m, int n)
{
    if (m == 0) return;
    for (int i = 0; i < n; ++i) delete[] m[i];
    delete[] m;
}

int main()
{
    int n = 4;
    int** mtx = allocMatrix(n);

    // minta feltöltés 1..n*n
    int val = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mtx[i][j] = val++;
        }
    }

    int* vec = mtx2vec(mtx, n);

    // vektor kiírás
    for (int i = 0; i < n * n; ++i) {
        std::cout << vec[i] << (i + 1 == n * n ? '\n' : ' ');
    }

    delete[] vec;
    freeMatrix(mtx, n);

    /*
    MTX:
    1  2  3  4
    5  6  7  8
    9 10 11 12
    13 14 15 16

    Expected output for n=4:
    1 2 5 9 6 3 4 7 10 13 14 11 8 12 15 16
    */
    return 0;
}
