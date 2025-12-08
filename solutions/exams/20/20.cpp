#include <iostream>
#include <cmath>

using namespace std;

struct Coord {
    double x;
    double y;
    double z;
};

// Prototype - implement this function
double* calcEuclid(const Coord* coords, int n)
{
    double* distances = new double[n];

    for (int i = 0; i < n; ++i) {
        distances[i] = sqrt(coords[i].x * coords[i].x +
                            coords[i].y * coords[i].y +
                            coords[i].z * coords[i].z);
    }

    return distances;
}

int main() {
    Coord coords[2];

    coords[0].x = 0.0;
    coords[0].y = 0.0;
    coords[0].z = 0.0;

    coords[1].x = 10.0;
    coords[1].y = 5.0;
    coords[1].z = 0.0;

    double* res = calcEuclid(coords, 2);

    for (int i = 0; i < 2; i++) {
        cout << res[i] << '\n';
    }

    delete[] res;

    return 0;
}
