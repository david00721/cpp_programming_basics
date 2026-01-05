#include <iostream>
#include <cmath>

struct point {
    double x;
    double y;
};

struct polygon {
    point* pts;
    int    numOfPoints;
};

struct circle {
    point center;
    double radius;
};

// Prototype - implement this function
circle enclosingCircle(polygon p);

int main()
{
    int n = 4;
    point* pts = new point[n];
    pts[0] = {0.0, 0.0};
    pts[1] = {4.0, 0.0};
    pts[2] = {4.0, 3.0};
    pts[3] = {0.0, 3.0};

    polygon p;
    p.pts = pts;
    p.numOfPoints = n;

    circle c = enclosingCircle(p);

    std::cout << "Center: (" << c.center.x << ", " << c.center.y << ")\n";
    std::cout << "Radius: " << c.radius << "\n";

    delete[] pts;

    // Expected output:
    // Center: (2, 1.5)
    // Radius: 2.5
    return 0;
}
