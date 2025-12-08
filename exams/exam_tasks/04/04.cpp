#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Prototype - implement this function
bool capsLocked(string s);

int main() {
    cout << (capsLocked("pISTA") ? "igen" : "nem") << endl;
    cout << (capsLocked("Pista") ? "igen" : "nem") << endl;
    cout << (capsLocked("alma")  ? "igen" : "nem") << endl;
    cout << (capsLocked("aLMA")  ? "igen" : "nem") << endl;
    cout << (capsLocked("123A")  ? "igen" : "nem") << endl;
    cout << (capsLocked("123a")  ? "igen" : "nem") << endl;

    return 0;
}