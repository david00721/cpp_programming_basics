#include <iostream>
#include <cmath>

// Prototype - implement this function
double surface(double r, double h)
{
    double l = std::sqrt(r * r + h * h);          // alkotó
    return M_PI * r * (r + l);                    // teljes felszín
}

int main()
{
    double r = 1.0;
    double h = 1.0;

    std::cout << surface(r, h) << std::endl;

    // Expected output: 7.58448

    return 0;
}
