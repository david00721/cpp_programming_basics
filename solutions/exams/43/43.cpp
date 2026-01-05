#include <iostream>

// Prototype - implement this function
int* mtx2vec(int** mtx, int n)
{
    if (n <= 0 || mtx == 0) return 0;

    int* vec = new int[n * n];
    int idx = 0;

    for (int s = 0; s <= 2 * (n - 1); ++s) {
        int iMin = (s - (n - 1) > 0) ? (s - (n - 1)) : 0;
        int iMax = (s < (n - 1)) ? s : (n - 1);

        if (s % 2 == 0) {
            // even diagonal: go up-right (i decreases)
            for (int i = iMax; i >= iMin; --i) {
                int j = s - i;
                vec[idx++] = mtx[i][j];
            }
        } else {
            // odd diagonal: go down-left (i increases)
            for (int i = iMin; i <= iMax; ++i) {
                int j = s - i;
                vec[idx++] = mtx[i][j];
            }
        }
    }

    return vec;
}

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
