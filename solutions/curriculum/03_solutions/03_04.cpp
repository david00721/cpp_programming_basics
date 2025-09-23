#include <iostream>

using namespace std;

// 01 Írj függvényt, ami egy számot hatványoz, és próbáld ki az alapértelmezett kitevőt!  
double power(double base, int exponent = 2)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

// 02 Írj függvényt, ami egy számot megszoroz egy alapértelmezett értékkel (pl. 10-zel), ha nem adsz meg másikat!
double multiply(double number, double factor = 10)
{
    return number * factor;
}

int main()
{
    // 01 Írj függvényt, ami egy számot hatványoz, és próbáld ki az alapértelmezett kitevőt!  
    cout << "2^3 = " << power(2, 3) << endl;
    cout << "5^2 = " << power(5) << endl;  // Alapértelmezett kitevő

    // 02 Írj függvényt, ami egy számot megszoroz egy alapértelmezett értékkel (pl. 10-zel), ha nem adsz meg másikat!
    cout << "5 * 3 = " << multiply(5, 3) << endl;
    cout << "7 * 10 = " << multiply(7) << endl;  // Alapértelmezett szorzó
    
    return 0;
}