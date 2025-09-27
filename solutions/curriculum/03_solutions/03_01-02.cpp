#include <iostream>

using namespace std;

// 01 - Írj függvényt, ami visszaadja egy szám köbét!
int cube(int x)
{
    return x * x * x;
}

// 02 - Írj függvényt, ami visszaadja egy szám kétszeresét!
int doubleValue(int x)
{
    return 2 * x;
}

int main()
{
    // 01 - Írj függvényt, ami visszaadja egy szám köbét!
    int num;
    cout << "Adj meg egy szamot: ";
    cin >> num;
    cout << "A szam kobja: " << cube(num) << endl;

    // 02 - Írj függvényt, ami visszaadja egy szám kétszeresét!
    cout << "A szam ketszerese: " << doubleValue(num) << endl;

    return 0;
}