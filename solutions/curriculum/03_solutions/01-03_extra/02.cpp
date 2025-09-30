#include <iostream>
#include <cmath>

using namespace std;

// Gyak 02 - Armstrong-számok keresése
bool isArmstrong(int n)
{
    int sum = 0, temp = n, digits = 0;

    // Számjegyek számának meghatározása
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    temp = n;
    // Armstrong-szám ellenőrzése
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == n;
}

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    cout << "Armstrong numbers between 1 and n:" << endl;

    for (int i = 1; i <= n; i++)
    {
        if (isArmstrong(i))
            cout << i << " is an Armstrong number." << endl;
    }

    return 0;
}
