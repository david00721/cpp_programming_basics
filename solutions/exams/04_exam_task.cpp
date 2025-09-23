#include <iostream>

using namespace std;

/*
Definiálja azt a bool capsLocked(std::string s) függvényt, ami igaz értékkel tér vissza, ha a paraméterként neki átadott s karakterlánc
- tartalmaz legalább egy betűt és
- amennyiben az első karakter betű, akkor az kisbetű,
- az összes ezt követő karakter nem kisbetű.

Betűk alatt az angol ábécé betűit értjük, a magyar ékezetes betűkkel nem kell foglalkozni.
*/

bool capsLocked(std::string s) {
    if (s.empty()) return false;                  // ha üres a string, akkor biztos nem jó

    bool firstIsLower = false;                    // első betű kisbetű-e?
    bool allOthersAreUpper = true;                // összes többi nagybetű-e?

    for (size_t i = 0; i < s.length(); ++i) {     // végigmegyünk az összes karakteren
        if (isalpha(s[i])) {                      // csak a betűket vizsgáljuk
            if (i == 0) {                         // első betű
                firstIsLower = islower(s[i]);     // kisbetűnek kell lennie
            } else {                              // többi betű
                allOthersAreUpper = allOthersAreUpper && isupper(s[i]); 
                // ha bármelyik nem nagybetű, akkor false lesz
            }
        }
    }

    return firstIsLower && allOthersAreUpper;     // akkor true, ha mindkét feltétel teljesül
}

int main()
{
    std::cout << std::boolalpha;                  // bool kiírás true/false formában

    std::cout << capsLocked("pISTA") << std::endl; // true: első 'p' kisbetű, többi nagy
    std::cout << capsLocked("Pista") << std::endl; // false: első nem kisbetű

    return 0;                                     // program vége
}
