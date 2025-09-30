#include <iostream>

using namespace std;

// Gyak 03 - LNKO és LKKT számítása
// Írj függvényt az LNKO kiszámítására (rekurzívan, Euklideszi algoritmussal).
// Írj másikat, ami az LNKO alapján kiszámolja az LKKT értékét.

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b; // Így elkerüljük a túlcsordulást
}

int main()
{
    int a, b;
    cout << "Kérek két számot: ";
    cin >> a >> b;

    cout << "LNKO: " << gcd(a, b) << endl;
    cout << "LKKT: " << lcm(a, b) << endl;

    return 0;
}
