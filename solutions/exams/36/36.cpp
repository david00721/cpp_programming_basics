#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

const int ROWS = 5;
const int COLS = 3;

double** allocMatrix(int r, int c)
{
    double** m = new double*[r];
    for (int i = 0; i < r; ++i) {
        m[i] = new double[c];
        for (int j = 0; j < c; ++j) m[i][j] = 0.0;
    }
    return m;
}

void freeMatrix(double** m, int r)
{
    if (m == 0) return;
    for (int i = 0; i < r; ++i) delete[] m[i];
    delete[] m;
}

// Prototype - implement this function
double** cosTetel(std::string fbe)
{
    std::ifstream fin(fbe.c_str());
    if (!fin.is_open()) {
        std::cout << "Sikertelen file-nyitás!" << std::endl;
        return 0;
    }

    double** in = allocMatrix(ROWS, COLS);
    double** out = allocMatrix(ROWS, COLS);

    // beolvasás 5 sor: b a gamma
    for (int i = 0; i < ROWS; ++i) {
        fin >> in[i][0] >> in[i][1] >> in[i][2];
        if (!fin) {
            // ha kevesebb adat van, a maradék marad 0, de visszaadjuk az out-ot
            break;
        }

        double b = in[i][0];
        double a = in[i][1];
        double gamma = in[i][2];


        double c = std::sqrt(a * a + b * b - 2.0 * a * b * std::cos(gamma * M_PI / 180.0));

        double beta = 0.0;
        if (c != 0.0) {
            double x = (b / c) * std::sin(gamma * M_PI / 180.0);
            // numerikus védelem asin tartományra
            if (x > 1.0) x = 1.0;
            if (x < -1.0) x = -1.0;
            beta = std::asin(x) / M_PI * 180.0;
        }

        double alfa = 180.0 - gamma - beta;

        // sorrend: c, beta, alfa
        out[i][0] = c;
        out[i][1] = beta;
        out[i][2] = alfa;
    }

    fin.close();
    freeMatrix(in, ROWS);

    return out;
}

int main()
{
    std::string inputFile = "triangles.txt";

    double** res = cosTetel(inputFile);
    if (res == 0) return 0;

    for (int i = 0; i < ROWS; ++i) {
        std::cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << std::endl;
    }

    freeMatrix(res, ROWS);

    /*
    Output:
    49.5725 23.794 126.206
    30.4138 34.715 85.285
    38.2683 67.5 67.5
    26.9258 21.8014 68.1986
    50.4004 34.1382 100.862
    */
    return 0;
}
