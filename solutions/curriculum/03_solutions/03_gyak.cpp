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
    for (int i = 2; i * i <= n; i++)  // i < sqrt(n)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Gyak 04 - Írj rekurzív függvényt, ami eldönti, hogy egy szám palindróm-e!
bool isPalindrome(int n, int rev = 0)
{
    if (n == 0)
        return rev;
    return isPalindrome(n / 10, rev * 10 + n % 10);
}

// Gyak 05 - Írj függvényt, ami visszaadja az n-edik háromszögszámot (1+2+…+n)!
int triangularNumber(int n)
{
    return n * (n + 1) / 2;

    // Másképp
    // if (n == 1)
    //     return 1;
    // return n + triangularNumber(n - 1);

    // Vagy ciklussal
    // int sum = 0;
    // for (int i = 1; i <= n; i++)
    //     sum += i;
    // return sum;
}


int main()
{
    cout << "Square of 5: " << square(5) << endl;
    cout << "Divisors of 12: " << countDivisors(12) << endl;
    cout << "Is 7 prime? " << (isPrime(7) ? "Yes" : "No") << endl;
    cout << "Is 121 palindrome? " << (isPalindrome(121) ? "Yes" : "No") << endl;
    cout << "5th triangular number: " << triangularNumber(5) << endl;

    return 0;
}
