#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Gyak 04 - Számrendszer-visszaalakítás
// Írj függvényt, ami egy bináris/oktális/hexadecimális számot visszaalakít tízes számrendszerbe (stringből indulva).
// Használd a switch-et a hexadecimális karakterek átalakításához.

int convertToDecimal(const string& num, int base)
{
    int result = 0;
    for (char digit : num)
    {
        result *= base;
        if (digit >= '0' && digit <= '9')
            result += digit - '0';
        else if (digit >= 'A' && digit <= 'F')
            result += digit - 'A' + 10;
    }
    return result;
}

// Ez a függvény egy adott számot (string formátumban) átalakít
// 10-es számrendszerbe (decimális), bármilyen 2 és 16 közötti alapból.
//
// Példák:
//   convertToDecimal("1011", 2)   → 11
//   convertToDecimal("17", 8)     → 15
//   convertToDecimal("1A", 16)    → 26
//
// Paraméterek:
//   num  - a szám string formátumban (pl. "1A")
//   base - a számrendszer alapja (pl. 2, 8, 10, 16)
//
// Működés menete:
//   - Kezdő érték: result = 0
//   - Végigmegyünk a string összes karakterén balról jobbra.
//   - Minden lépésben:
//       1. Megszorozzuk a result-ot a bázissal.
//          Ez olyan, mintha a helyiértékeket balra tolnánk.
//       2. Hozzáadjuk az aktuális számjegy értékét:
//          - '0'..'9' esetén: digit - '0'
//          - 'A'..'F' esetén: digit - 'A' + 10
//   - A ciklus végére a result tartalmazza a decimális értéket.


int main()
{
    string num;
    int base;

    cout << "Kérem a számot: ";
    cin >> num;
    cout << "Kérem a számrendszert (2, 8, 16): ";
    cin >> base;

    if (base != 2 && base != 8 && base != 16)
    {
        cout << "Érvénytelen számrendszer!" << endl;
        return 1;
    }

    int decimalValue = convertToDecimal(num, base);
    cout << "Tízes számrendszerbeli érték: " << decimalValue << endl;

    return 0;
}