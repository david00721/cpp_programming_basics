#include <iostream>

struct chord {
    char tune[6];
    int  fret[6];
    int  finger[6];
};

// Prototype - implement this function
void printChord(struct chord c);

int main()
{
    chord c1 = {{'e','b','g','d','a','e'}, {-1, 7, 5, 4, 5, -1}, {-1, 4, 3, 1, 2, -1}};
    printChord(c1);

    std::cout << std::endl;

    chord c2 = {{'e','b','g','d','a','e'}, {0, 1, 2, 2, 0, -1}, {-1, 1, 3, 2, -1, -1}};
    printChord(c2);

    return 0;
}
