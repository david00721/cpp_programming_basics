#include <iostream>

using namespace std;

/*
Definiálja a void kever(std::string& s) függvényt, ami véletlenszerű sorrendbe állítja az s string karaktereit!
*/

#include <algorithm>  // std::shuffle
#include <random>     // std::random_device, std::mt19937

void kever(std::string& s) {
    std::random_device rd;   // véletlenszám-generátor eszköz (hardveres entropiából)
    std::mt19937 g(rd());    // Mersenne Twister PRNG inicializálása
    std::shuffle(s.begin(), s.end(), g); // karakterek összekeverése
}

int main()
{
    std::string s = "programming";              // kiindulási string
    cout << "Eredeti string: " << s << endl;    // kiírjuk az eredeti sorrendet
    kever(s);                                   // összekeverjük a karaktereket
    cout << "Kevert string: " << s << endl;     // kiírjuk a kevert sorrendet
    return 0;                                   // program vége
}
