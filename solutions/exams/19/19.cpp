#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
bool ispalindrome(const string& str);

int main() {
    cout << ispalindrome("gorog") << endl;   // 1
    cout << ispalindrome("level") << endl;   // 1
    cout << ispalindrome("alma") << endl;    // 0
    cout << ispalindrome("ABBA") << endl;    // 1
    cout << ispalindrome("abBA") << endl;    // 0 (kis/nagy különbözik!)

    return 0;
}