#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Prototype - implement this function
double getArea(int n, double l)
{
    double radius = l / (2 * sin(M_PI / n));

    double a = radius;
    double b = radius;
    double c = l;

    double s = (a + b + c) / 2.0; // semi-perimeter
    double triangleArea = sqrt(s * (s - a) * (s - b) * (s - c));

    // Total area is n times the area of one triangle
    return n * triangleArea;
}

int main() {
    cout << fixed << setprecision(2);
    
    // Példa a feladatból
    cout << getArea(4, 2) << endl;  // elvárt: 4.00

    // További tesztek
    cout << getArea(3, 5) << endl;  // egyenlő oldalú háromszög (~10.83)
    cout << getArea(6, 3) << endl;  // szabályos hatszög (~23.38)
    cout << getArea(8, 1) << endl;  // szabályos nyolcszög (~2.41)

    return 0;
}