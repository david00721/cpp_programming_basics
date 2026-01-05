#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Prototype - implement this function
int* stat(string s)
{
    int* freq = new int[26];
    for (int i = 0; i < 26; ++i) freq[i] = 0;

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        }
    }

    return freq;
}

int main() {
    string text = "Hello World! ABC xyz, Zebra... hello again!";

    int* freq = stat(text);

    for (int i = 0; i < 26; i++) {
        cout << char('a' + i) << ": " << freq[i] << endl;
    }

    delete[] freq;

    return 0;
}
