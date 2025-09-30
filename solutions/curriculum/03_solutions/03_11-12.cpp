#include <iostream>

using namespace std;

// 11 - Írj rekurzív függvényt, ami visszaadja egy szám számjegyeinek fordítottját! (pl. 123 → 321)
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNumber(n / 10, rev * 10 + n % 10);
}
/*
- n: az aktuális szám, amit még fel kell dolgozni.
- rev: az eddig összerakott fordított szám. Alapértelmezett értéke 0, így az első hívásban nem kell megadni.

- Alap eset: ha n 0, akkor visszatérünk a rev értékével, mert nincs több számjegy, amit hozzá kellene adni.
- Rekurzív eset: a függvény újra meghívja önmagát azzal, hogy n-et elosztja 10-zel (ez eltávolítja a legutolsó számjegyet),
  és rev-et úgy frissíti, hogy megszorozza 10-zel (helyet csinál az új számjegynek) és hozzáadja n utolsó számjegyét (n % 10).

  Így a függvény lépésről lépésre építi fel a fordított számot.

  Példa lépésről lépésre a 123 számra:
  - reverseNumber(123, 0) hívás → n nem 0, rekurzív hívás: reverseNumber(12, 3)
  - reverseNumber(12, 3) hívás → n nem 0, rekurzív hívás: reverseNumber(1, 32)
  - reverseNumber(1, 32) hívás → n nem 0, rekurzív hívás: reverseNumber(0, 321)
  - reverseNumber(0, 321) hívás → n 0, visszatér 321
*/

// 12 - Írj rekurzív függvényt, ami visszaadja a^b értékét (ahol a alap, b kitevő, egész szám, b >= 0)!
int power(int a, int b)
{
    // Alap eset: ha b 0, akkor a^0 = 1
    if (b == 0)
        return 1;

    // Rekurzív hívás: a^(b-1) * a
    return a * power(a, b - 1);
}

int main()
{
    // 11 - Írj rekurzív függvényt, ami visszaadja egy szám számjegyeinek fordítottját! (pl. 123 → 321)
    int number;
    cout << "Adj meg egy szamot, amelynek a szamjegyeit megforditom: ";
    cin >> number;
    cout << "A szam forditottja: " << reverseNumber(number) << endl;

    // 12 - Írj rekurzív függvényt, ami visszaadja a^b értékét (ahol a alap, b kitevő, egész szám, b >= 0)!
    int base, exponent;
    cout << "Add meg az alapot és a kitevot (kitevo >= 0): ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    return 0;
}