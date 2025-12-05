#include <iostream>
#include <string>
using namespace std;

string getNotes(string chord) {
    // A lehetséges hangok sorrendben
    const string notes[12] = {
        "C", "C#", "D", "D#", "E", "F",
        "F#", "G", "G#", "A", "A#", "B"
    };
    const int NOTES_COUNT = 12;

    // Megállapítjuk, hogy domináns szeptim-e (végződik-e '7'-tel)
    bool isDominant7 = false;
    if (!chord.empty() && chord[chord.size() - 1] == '7') {
        isDominant7 = true;
        chord.erase(chord.size() - 1); // levesszük a '7'-et, marad pl. "A" vagy "C#"
    }

    string root = chord; // alaphang
    int rootIndex = -1;

    // Megkeressük az alaphang indexét a notes tömbben
    for (int i = 0; i < NOTES_COUNT; ++i) {
        if (notes[i] == root) {
            rootIndex = i;
            break;
        }
    }

    if (rootIndex == -1) {
        // Nem találtuk az alaphangot (hibás bemenet esetén)
        return "";
    }

    // Intervallumok félhangokban:
    // dúr: 0, 4, 7
    // domináns szeptim: 0, 4, 7, 10
    int intervals[4];
    int intervalCount = 0;

    intervals[intervalCount++] = 0;
    intervals[intervalCount++] = 4;
    intervals[intervalCount++] = 7;
    if (isDominant7) {
        intervals[intervalCount++] = 10;
    }

    // Összerakjuk az eredményt
    string result = "";
    for (int i = 0; i < intervalCount; ++i) {
        int idx = (rootIndex + intervals[i]) % NOTES_COUNT;
        if (!result.empty()) {
            result += " ";
        }
        result += notes[idx];
    }

    return result;
}

int main() {
    cout << getNotes("C") << endl;   // C E G
    cout << getNotes("A") << endl;   // A C# E
    cout << getNotes("C#") << endl;  // C# F G#
    cout << getNotes("A7") << endl;  // A C# E G
    cout << getNotes("G7") << endl;  // G B D F
    return 0;
}
