#include <iostream>

using namespace std;

// 13 - Írj függvényt, ami visszaadja két szám legnagyobb közös osztóját!  
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 14 - Írj rekurzív függvényt, ami kiszámolja egy szám számjegyeinek szorzatát!
int digitProduct(int n)
{
    if (n == 0)
        return 1;
    return (n % 10) * digitProduct(n / 10);
}

int main()
{
    // 13 - Írj függvényt, ami visszaadja két szám legnagyobb közös osztóját!
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;

    // 14 - Írj rekurzív függvényt, ami kiszámolja egy szám számjegyeinek szorzatát!
    cout << "Digit product of 1234 = " << digitProduct(1234) << endl;
    cout << "GCD(56, 98) = " << gcd(56, 98) << endl;


    return 0;
}