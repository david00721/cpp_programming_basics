#include <iostream>
#include <string>

// Prototype - implement this function
std::string getNotes(std::string chord);

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
