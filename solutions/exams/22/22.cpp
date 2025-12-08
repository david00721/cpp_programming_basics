#include <iostream>
#include <cmath>

using namespace std;



struct point {
    double x;
    double y;
};

// Prototype - implement this function
double compare(struct point* a, struct point* b, int l) {
    double sum = 0.0;

    for (int i = 0; i < l; i++) {
        double dx = a[i].x - b[i].x;
        double dy = a[i].y - b[i].y;
        sum += std::sqrt(dx * dx + dy * dy);
    }

    return sum / l;
}

int main() {
    point A[3] = {
        {0, 0},
        {1, 1},
        {2, 2}
    };

    point B[3] = {
        {0, 1},
        {1, 2},
        {2, 3}
    };

    double result = compare(A, B, 3);
    cout << result << endl;

    return 0;
}
