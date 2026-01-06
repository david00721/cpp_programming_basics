#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

const int ROWS = 5;
const int COLS = 3;

void freeMatrix(double** m, int r)
{
    if (m == 0) return;
    for (int i = 0; i < r; ++i) delete[] m[i];
    delete[] m;
}

// Prototype - implement this function
double** cosTetel(std::string fbe);

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
