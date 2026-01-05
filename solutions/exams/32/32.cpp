#include <iostream>
#include <cmath>

using namespace std;

const int MERET = 5;

// Prototype - implement this function
double infuse(double in_bk[])
{
    int filled = 0;
    while (filled < MERET) {
        double x;
        std::cin >> x;

        if (x > 0.0 && x < 256.0) {
            in_bk[filled] = x;
            filled++;
        }
    }

    double prod = 1.0;
    for (int i = 0; i < MERET; ++i) {
        prod *= pow(in_bk[i], 1.0 / 3);
    }
    return prod;
}

// Prototype - implement this function
void outwrite(double root)
{
    long long whole = (long long)root; // egész rész (0 felé csonkol)
    if (whole % 2 == 0) {
        std::cout << "Outwrite: The integer part is even." << std::endl;
    } else {
        std::cout << "Outwrite: The integer part is odd." << std::endl;
    }
}

int main()
{
    double arr[MERET];
    double prod = infuse(arr);

    std::cout << "Szorzatuk: ";

    for (int i = 0; i < MERET; ++i) {
        double r = pow(arr[i], 1.0 / 3);
        long long ri = (long long)(r + 1e-9); // tipikusan egész a példában
        std::cout << ri;
        if (i < MERET - 1) std::cout << " \xC3\x97 ";
    }

    std::cout << " = " << prod << std::endl;

    std::cout << "Infuse: " << prod << std::endl;
    outwrite(std::ceil(prod * 100.0) / 100.0);

    return 0;
}