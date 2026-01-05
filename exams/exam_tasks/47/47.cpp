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
circle enclosingCircle(polygon p)
{
    circle c;
    c.center.x = 0.0;
    c.center.y = 0.0;
    c.radius = 0.0;

    if (p.pts == 0 || p.numOfPoints <= 0) {
        return c;
    }

    // középpont = pontok átlaga
    for (int i = 0; i < p.numOfPoints; ++i) {
        c.center.x += p.pts[i].x;
        c.center.y += p.pts[i].y;
    }
    c.center.x /= p.numOfPoints;
    c.center.y /= p.numOfPoints;

    // sugár = legtávolabbi pont távolsága a középponttól
    double maxDist2 = 0.0;
    for (int i = 0; i < p.numOfPoints; ++i) {
        double dx = p.pts[i].x - c.center.x;
        double dy = p.pts[i].y - c.center.y;
        double d2 = dx * dx + dy * dy;
        if (d2 > maxDist2) maxDist2 = d2;
    }
    c.radius = std::sqrt(maxDist2);

    return c;
}

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
