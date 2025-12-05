#include <iostream>
#include <string>
using namespace std;

int wordCount(const string text) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < (int)text.size(); ++i) {
        char c = text[i];

        bool isSeparator = (c == ' ' || c == '\t' || c == '\n');

        if (!isSeparator && !inWord) {
            // új szó kezdődik
            count++;
            inWord = true;
        }
        else if (isSeparator) {
            inWord = false;
        }
    }

    return count;
}

int main() {
    cout << wordCount("hello   world") << endl;        // 2
    cout << wordCount("  a b   c   ") << endl;         // 3
    cout << wordCount("line1\nline2\tline3") << endl;  // 3
    cout << wordCount("") << endl;                     // 0
    return 0;
}