#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Prototype - implement this function
double getArea(int n, double l);

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