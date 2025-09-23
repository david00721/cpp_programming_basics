#include <iostream>

using namespace std;

// 01 Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// 02 Írj rekurzív függvényt, ami visszaadja a Fibonacci-sorozat n-edik elemét!
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // 01 Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
    cout << "5! = " << factorial(5) << endl;
    cout << "7! = " << factorial(7) << endl;

    // 02 Írj rekurzív függvényt, ami visszaadja a Fibonacci-sorozat n-edik elemét!
    cout << "Fibonacci(5) = " << fibonacci(5) << endl;
    cout << "Fibonacci(7) = " << fibonacci(7) << endl;

    return 0;
}