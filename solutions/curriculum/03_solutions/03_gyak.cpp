#include <iostream>

using namespace std;

// Gyak 01 - Írj függvényt, ami visszaadja egy szám négyzetét!
int square(int n)
{
    return n * n;
}

// Gyak 02 - Írj függvényt, ami visszaadja egy szám összes osztójának számát!
int countDivisors(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    return count;
}

// Gyak 03 - Írj függvényt, ami eldönti, hogy egy szám prímszám-e!
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Gyak 04 - Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Gyak 05 - Írj függvényt, ami két szám LNKO-ját számolja ki (rekurzívan)!
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    cout << "Square of 5: " << square(5) << endl;
    cout << "Divisors of 12: " << countDivisors(12) << endl;
    cout << "Is 7 prime? " << (isPrime(7) ? "Yes" : "No") << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "GCD of 12 and 15: " << gcd(12, 15) << endl;

    return 0;
}
