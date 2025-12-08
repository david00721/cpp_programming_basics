#include <iostream>
#include <cmath>

using namespace std;

const int MERET = 5;

// Prototype - implement this function
double infuse(double in_bk[]);

// Prototype - implement this function
void outwrite(double root);

int main() {
    double arr[MERET];

    double r = infuse(arr);
    outwrite(r);

    return 0;
}