#include <iostream>

using namespace std;

// Gyak 01 - Számjegyek összegének rekurzív és iteratív összehasonlítása
int sumDigitsRecursive(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumDigitsRecursive(n / 10);
}

int sumDigitsIterative(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int number = 12345;
    cout << "Recursive sum of digits: " << sumDigitsRecursive(number) << endl;
    cout << "Iterative sum of digits: " << sumDigitsIterative(number) << endl;

    return 0;
}
