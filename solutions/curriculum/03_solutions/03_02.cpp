#include <iostream>

using namespace std;

// 01 Írj függvényt, ami két szám különbségét adja vissza, és használd prototípussal!  
int difference(int a, int b); // prototípus

// 02 Írj függvényt, ami két szám szorzatát adja vissza, prototípussal!
int product(int a, int b); // prototípus

int main()
{
    // 01 Írj függvényt, ami két szám különbségét adja vissza, és használd prototípussal!
    int a = 5, b = 3;
    cout << "Kulonbseg: " << difference(a, b) << endl;

    // 02 Írj függvényt, ami két szám szorzatát adja vissza, prototípussal!
    cout << "Szorzat: " << product(a, b) << endl;

    return 0;
}

// 01 Írj függvényt, ami két szám különbségét adja vissza, és használd prototípussal!
int difference(int a, int b) // definíció
{
    return a - b;
}

// 02 Írj függvényt, ami két szám szorzatát adja vissza, prototípussal!
int product(int a, int b) // definíció
{
    return a * b;
}