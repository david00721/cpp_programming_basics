#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
bool ispalindrome(const string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << ispalindrome("gorog") << endl;   // 1
    cout << ispalindrome("level") << endl;   // 1
    cout << ispalindrome("alma") << endl;    // 0
    cout << ispalindrome("ABBA") << endl;    // 1
    cout << ispalindrome("abBA") << endl;    // 0 (kis/nagy különbözik!)

    return 0;
}