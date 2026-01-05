#include <iostream>
#include <cmath>

using namespace std;

const int MERET = 6;

// Prototype - implement this function
double uploading(double up_bl[])
{
    int filled = 0;
    while (filled < MERET) {
        double x;
        std::cin >> x;

        // negatív és -10-nél nagyobb
        if (x < 0.0 && x > -10.0) {
            up_bl[filled] = x;
            filled++;
        }
    }

    double diff = pow(up_bl[0], 3);
    for (int i = 1; i < MERET; ++i) {
        diff -= pow(up_bl[i], 3);
    }
    return diff;
}

// Prototype - implement this function
void writesOut(double diff)
{
    long long whole = (long long)diff; // egész rész (0 felé csonkol)
    int d = 0;
    if (whole == 0) {
        d = 1; // ha a különbség egész része 0, akkor egy számjegy van
    } else {
        if (whole < 0) {
            whole = -whole; // abszolút érték
        }
        while (whole > 0) {
            whole /= 10;
            d++;
        }
    }

    std::cout << "A kulonbseg egesz reszenek szamjegyeinek szama: " << d << std::endl;
}

int main()
{
    double arr[MERET];
    double diff = uploading(arr);

    // a feladat példája szerinti sorok kiírása
    for (int i = 0; i < MERET; ++i) {
        if (i > 0) std::cout << " - ";
        std::cout << "(" << arr[i] << ")^3";
    }
    std::cout << std::endl;

    std::cout << "= ";
    for (int i = 0; i < MERET; ++i) {
        if (i > 0) std::cout << " - ";
        std::cout << "(" << pow(arr[i], 3) << ")";
    }
    std::cout << std::endl;

    std::cout << "= " << pow(arr[0], 3);
    for (int i = 1; i < MERET; ++i) {
        double c = pow(arr[i], 3);
        if (c < 0) {
            std::cout << " + " << (-c);
        } else {
            std::cout << " - " << c;
        }
    }
    std::cout << std::endl;

    std::cout << "= " << diff << std::endl;

    // plusz a feladat által kért 2. függvény
    writesOut(diff);

    // Expected output:
    // -1 -2 -3 -4 -5 -6
    // (-1)^3 - (-2)^3 - (-3)^3 - (-4)^3 - (-5)^3 - (-6)^3
    // = (-1) - (-8) - (-27) - (-64) - (-125) - (-216)
    // = -1 + 8 + 27 + 64 + 125 + 216
    // = 439
    // A kulonbseg egesz reszenek szamjegyeinek szama: 3

    return 0;
}
