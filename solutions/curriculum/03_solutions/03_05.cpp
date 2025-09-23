#include <iostream>

using namespace std;

// 01 Írj két `multiply` függvényt: egyet int, egyet double típusra!
int multiply(int a, int b)
{
    return a * b;
}

double multiply(double a, double b)
{
    return a * b;
}

// 02 Írj két `maximum` függvényt: egyet int, egyet double típusra!
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

double maximum(double a, double b)
{
    return (a > b) ? a : b;
}

int main()
{
    // 01 Írj két `multiply` függvényt: egyet int, egyet double típusra!
    cout << "Int multiply: " << multiply(5, 10) << endl;
    cout << "Double multiply: " << multiply(5.5, 10.5) << endl;

    // 02 Írj két `maximum` függvényt: egyet int, egyet double típusra!
    cout << "Int maximum: " << maximum(5, 10) << endl;
    cout << "Double maximum: " << maximum(5.5, 10.5) << endl;

    return 0;
}