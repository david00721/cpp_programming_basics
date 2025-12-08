#include <iostream>
#include <cmath>

using namespace std;

const int MERET = 6;

// Prototype - implement this function
double uploading(double up_bl[]);

// Prototype - implement this function
void writesOut(double diff);

int main() {
    double up_bl[MERET];

    double diff = uploading(up_bl);
    writesOut(diff);

    return 0;
}
