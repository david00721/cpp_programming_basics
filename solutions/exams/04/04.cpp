#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
Feladat:
Definiálja azt a bool capsLocked(std::string s) függvényt, ami igaz értékkel tér vissza, ha a paraméterként neki átadott s karakterlánc

tartalmaz legalább egy betűt és
amennyiben az első karakter betű, akkor az kisbetű,
az összes ezt követő karakter nem kisbetű.
Betűk alatt az angol ábécé betűit értjük, a magyar ékezetes betűkkel nem kell foglalkozni.
*/

// Prototype - implement this function
bool capsLocked(std::string s) {
    bool hasLetter = false;
    bool firstIsLower = false;

    for (size_t i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) {
            hasLetter = true;
            if (i == 0) {
                firstIsLower = islower(s[i]);
            } else {
                if (firstIsLower && islower(s[i])) {
                    return false;
                }
                if (!firstIsLower && islower(s[i])) {
                    return false;
                }
            }
        }
    }

    return hasLetter && (firstIsLower || !firstIsLower);
}

int main() {
    cout << (capsLocked("pISTA") ? "igen" : "nem") << endl;
    cout << (capsLocked("Pista") ? "igen" : "nem") << endl;
    cout << (capsLocked("alma")  ? "igen" : "nem") << endl;
    cout << (capsLocked("aLMA")  ? "igen" : "nem") << endl;
    cout << (capsLocked("123A")  ? "igen" : "nem") << endl;
    cout << (capsLocked("123a")  ? "igen" : "nem") << endl;

    return 0;
}