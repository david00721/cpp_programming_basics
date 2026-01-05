#include <iostream>
#include <string>

int findNoteIndex(const std::string& note)
{
    const std::string notes[12] = {
        "C","C#","D","D#","E","F","F#","G","G#","A","A#","B"
    };
    for (int i = 0; i < 12; ++i) {
        if (notes[i] == note) return i;
    }
    return -1;
}

std::string noteAt(int idx)
{
    const std::string notes[12] = {
        "C","C#","D","D#","E","F","F#","G","G#","A","A#","B"
    };
    while (idx < 0) idx += 12;
    idx %= 12;
    return notes[idx];
}

// Prototype - implement this function
std::string getNotes(std::string chord)
{
    bool is7 = false;
    std::string root;

    int n = chord.length();
    if (n <= 0) return "";

    if (chord[n - 1] == '7') {
        is7 = true;
        root = chord.substr(0, n - 1);
    } else {
        root = chord;
    }

    int rootIdx = findNoteIndex(root);
    if (rootIdx < 0) return "";

    std::string result;
    result = noteAt(rootIdx) + " " + noteAt(rootIdx + 4) + " " + noteAt(rootIdx + 7);

    if (is7) {
        result += " " + noteAt(rootIdx + 10);
    }

    return result;
}

int main()
{
    std::string tests[] = {"A", "C#", "A7", "C#7", "B7", "F"};
    int t = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < t; ++i) {
        std::cout << tests[i] << " -> " << getNotes(tests[i]) << std::endl;
    }

    // Expected output:
    // A -> A C# E
    // C# -> C# F G#
    // A7 -> A C# E G
    // C#7 -> C# F G# B
    // B7 -> B D# F# A
    // F -> F A C

    return 0;
}
