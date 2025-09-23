#include <iostream>

using namespace std;

// 01 Írj egy függvényt, ami érték szerint próbál módosítani egy változót, majd ellenőrizd, hogy változott-e!
void modifyValue(int x)
{
    x = 10;
    cout << "A fuggvenyben: " << x << endl;
}

// 02 Írj egy függvényt, ami referencia szerint kap egy változót, és ténylegesen módosítja az értékét!
void modifyValueRef(int& x)
{
    x = 10;
    cout << "A fuggvenyben: " << x << endl;
}

int main()
{
    // 01 Írj egy függvényt, ami érték szerint próbál módosítani egy változót, majd ellenőrizd, hogy változott-e!

    int a = 5;
    cout << "A fuggveny hivasa elott: " << a << endl;
    modifyValue(a);
    cout << endl << "A fuggveny hivasa utan: " << a << endl;

    // 02 Írj egy függvényt, ami referencia szerint kap egy változót, és ténylegesen módosítja az értékét!
    int b = 5;
    cout << "A fuggveny hivasa elott: " << b << endl;
    modifyValueRef(b);
    cout << endl << "A fuggveny hivasa utan: " << b << endl;

    return 0;
}