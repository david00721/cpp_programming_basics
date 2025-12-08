#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Prototype - implement this function
int* stat(string s);

int main() {
    string text = "Hello World! ABC xyz, Zebra... hello again!";

    int* freq = stat(text);

    for (int i = 0; i < 26; i++) {
        cout << char('a' + i) << ": " << freq[i] << endl;
    }

    delete[] freq;

    return 0;
}
