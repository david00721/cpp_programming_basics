#include <iostream>

using namespace std;

// 01 - Írj függvényt, ami visszaadja egy szám köbét!
int cube(int x)
{
    return x * x * x;
}

// 02 - Írj függvényt, ami egy szám abszolút értékét adja vissza!
int absoluteValue(int x)
{
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    // 01 - Írj függvényt, ami visszaadja egy szám köbét!
    int num;
    cout << "Adj meg egy szamot: ";
    cin >> num;
    cout << "A szam kobja: " << cube(num) << endl;

    // 02 - Írj függvényt, ami egy szám abszolút értékét adja vissza!
    cout << "Adj meg egy szamot: ";
    cin >> num;
    cout << "A szam abszolut erteke: " << absoluteValue(num) << endl;

    return 0;
}