#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
Definiálja a `double getArea(int n, double l)` függvényt, ami egy `n` oldalú, `l` oldalhosszúságú **szabályos sokszög** területét adja meg.

A sokszöget bontsuk `n` darab egyforma háromszögre a középpontba húzott szakaszokkal.
E háromszögek két oldala a köré írt kör sugara `R`, a harmadik oldala az oldalhossz `l`.
*/

double getArea(int n, double l)
{
    const double pi = 3.14159265;                         // pi közelítő értéke
    double R = l / (2 * sin(pi / n));                     // köré írt kör sugara
    double areaOfOneTriangle = (l * R * cos(pi / n)) / 2; // egy háromszög területe (képletből)
    return n * areaOfOneTriangle;                         // sokszög területe = n * háromszög terület
}

int main()
{
    std::cout << std::setprecision(2) // két tizedes pontosság
              << getArea(4, 2)        // négyzet területe, oldal = 2
              << std::endl;           // kiírás sorvéggel
    return 0;                         // program vége
}

