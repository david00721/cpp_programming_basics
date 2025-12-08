#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};

// Prototype - implement this function
double compare(struct point* a, struct point* b, int l);

int main() {
    point A[3] = {
        {0, 0},
        {1, 1},
        {2, 2}
    };

    point B[3] = {
        {0, 0},
        {2, 1},
        {2, 4}
    };

    double result = compare(A, B, 3);
    cout << result << endl;

    return 0;
}
