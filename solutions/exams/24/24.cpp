#include <iostream>

using namespace std;

// Prototype - implement this function
double** shift(double** mtx, int w, int h)
{
    double** result = new double*[w];
    for (int i = 0; i < w; i++) {
        result[i] = new double[h];
        for (int j = 0; j < h; j++) {
            result[i][j] = mtx[i][j]; // Alapértelmezett érték
        }
    }

    // Felső sor
    for (int j = 0; j < h - 1; j++) {
        result[0][j + 1] = mtx[0][j];
    }
    // Jobb oszlop
    for (int i = 0; i < w - 1; i++) {
        result[i + 1][h - 1] = mtx[i][h - 1];
    }
    // Alsó sor
    for (int j = h - 1; j > 0; j--) {
        result[w - 1][j - 1] = mtx[w - 1][j];
    }
    // Bal oszlop
    for (int i = w - 1; i > 0; i--) {
        result[i - 1][0] = mtx[i][0];
    }

    return result;
}

// Segédfüggvény: 2D tömb létrehozása 1D tömbből
double** createMtx(double* src, int w, int h) {
    double** m = new double*[w];
    for (int i = 0; i < w; i++) {
        m[i] = new double[h];
        for (int j = 0; j < h; j++) {
            m[i][j] = src[i * h + j];
        }
    }
    return m;
}

// Segédfüggvény: 2D tömb felszabadítása
void deleteMtx(double** m, int w) {
    for (int i = 0; i < w; i++)
        delete[] m[i];
    delete[] m;
}

// Segédfüggvény: mátrix kiírása
void printMtx(double** m, int w, int h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double data[16] = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12,
        13,14, 15, 16
    };

    int w = 4;
    int h = 4;

    double** mtx = createMtx(data, w, h);

    cout << "Eredeti mátrix:" << endl;
    printMtx(mtx, w, h);

    double** shifted = shift(mtx, w, h);

    cout << "\nEltolva (perem óramutató járásával megegyezően):" << endl;
    printMtx(shifted, w, h);

    deleteMtx(mtx, w);
    deleteMtx(shifted, w);

    return 0;
}
