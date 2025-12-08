#include <iostream>

using namespace std;

// Prototype - implement this function
double conv(double** kernel, double** img, int k_w, int k_h, int x, int y) {
    double sum = 0.0;

    int half_w = k_w / 2;
    int half_h = k_h / 2;

    for (int i = 0; i < k_w; i++) {
        for (int j = 0; j < k_h; j++) {

            // az img megfelelő elemének pozíciója
            int img_x = x + (i - half_w);
            int img_y = y + (j - half_h);

            sum += kernel[i][j] * img[img_x][img_y];
        }
    }

    return sum;
}

// Segédfüggvény: 2D tömb létrehozása és feltöltése egy 1D tömbből
double** createMtx(double* src, int w, int h) {
    double** m = new double*[w];
    for (int i = 0; i < w; ++i) {
        m[i] = new double[h];
        for (int j = 0; j < h; ++j) {
            m[i][j] = src[i * h + j];
        }
    }
    return m;
}

// Segédfüggvény: 2D tömb felszabadítása
void deleteMtx(double** m, int w) {
    for (int i = 0; i < w; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

int main() {
    // 3x3-as kernel (pl. egyszerű minta)
    double kernelData[9] = {
        0,  1, 0,
        1, -4, 1,
        0,  1, 0
    };
    int k_w = 3;
    int k_h = 3;
    double** kernel = createMtx(kernelData, k_w, k_h);

    // 5x5-ös "kép"
    double imgData[25] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11,12,13,14,15,
        16,17,18,19,20,
        21,22,23,24,25
    };
    int img_w = 5;
    int img_h = 5;
    double** img = createMtx(imgData, img_w, img_h);

    // Konvolúció a (2,2) középpont körül (a 5x5-ös mátrix közepe)
    double result = conv(kernel, img, k_w, k_h, 2, 2);
    cout << result << endl;

    deleteMtx(kernel, k_w);
    deleteMtx(img, img_w);

    return 0;
}
