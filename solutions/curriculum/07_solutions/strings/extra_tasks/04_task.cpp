#include <iostream>
#include <string>
using namespace std;

void mbox(const string& message) {
    // 1. Széttörjük a message-t sorokra
    string lines[100];   // elég nagy statikus tömb
    int lineCount = 0;

    string current = "";
    for (int i = 0; i < (int)message.size(); ++i) {
        if (message[i] == '\n') {
            lines[lineCount++] = current;
            current = "";
        } else {
            current += message[i];
        }
    }
    // Az utolsó sor hozzáadása (ha nincs newline a végén)
    lines[lineCount++] = current;

    // 2. Megkeressük a leghosszabb sor hosszát
    int maxLen = 0;
    for (int i = 0; i < lineCount; ++i) {
        if ((int)lines[i].size() > maxLen) {
            maxLen = lines[i].size();
        }
    }

    // 3. Kiírjuk a felső keretet
    for (int i = 0; i < maxLen + 2; ++i) cout << "*";
    cout << "\n";

    // 4. Kiírjuk a sorokat
    for (int i = 0; i < lineCount; ++i) {
        cout << "*" << lines[i];

        // kitöltés szóközökkel
        int spaces = maxLen - lines[i].size();
        for (int s = 0; s < spaces; ++s) cout << " ";

        cout << "*\n";
    }

    // 5. Kiírjuk az alsó keretet
    for (int i = 0; i < maxLen + 2; ++i) cout << "*";
    cout << "\n";
}

int main() {
    mbox("ab\ncde\nf");
    return 0;
}