#include <iostream>
#include <cmath>

using namespace std;

const double E = 2.71828182845904523536;  // Euler-féle szám

// Prototype - implement this function
double* silu(double* data, int data_size);

int main() {
    double data[5] = {-3.0, -1.0, 0.0, 1.0, 3.0};

    double* result = silu(data, 5);

    for (int i = 0; i < 5; i++) {
        cout << result[i] << endl;
    }

    delete[] result;

    return 0;
}
