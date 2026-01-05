#include <iostream>

struct chord {
    char tune[6];
    int  fret[6];
    int  finger[6];
};

// Prototype - implement this function
void printChord(struct chord c)
{
    int minF = 1000000;
    int maxF = -1000000;

    // Determine the min and max frets used (ignoring open and muted strings)
    for (int i = 0; i < 6; ++i) {
        if (c.fret[i] > 0) {
            if (c.fret[i] < minF) minF = c.fret[i];
            if (c.fret[i] > maxF) maxF = c.fret[i];
        }
    }

    int span = 0;
    int startFret = 0;

    // If no frets are pressed, default to span of 1 starting at fret 0
    if (maxF == -1000000) {
        span = 1;
        startFret = 0;
    } else {
        span = (maxF - minF) + 1;
        startFret = minF;
    }

    // Print each string
    for (int i = 0; i < 6; ++i) {
        std::cout << c.tune[i] << ' ';

        // Print open, muted, or space
        if (c.fret[i] == 0) {
            std::cout << 'O';
        } else if (c.fret[i] < 0) {
            std::cout << 'X';
        } else {
            std::cout << ' ';
        }

        // Print the frets
        for (int k = 0; k < span; ++k) {
            std::cout << '|';
            int currentFret = startFret + k;

            // Print finger or empty space
            if (c.fret[i] == currentFret) {
                int f = c.finger[i];
                if (f < 0) f = 0;
                std::cout << '-' << f << '-';
            } else {
                std::cout << "---";
            }
        }
        std::cout << '|' << std::endl;
    }

    // Print starting fret if greater than 0
    if (startFret > 0) {
        std::cout << "     " << startFret << std::endl;
    }
}

int main()
{
    chord c1 = {{'e','b','g','d','a','e'}, {-1, 7, 5, 4, 5, -1}, {-1, 4, 3, 1, 2, -1}};
    printChord(c1);

    std::cout << std::endl;

    chord c2 = {{'e','b','g','d','a','e'}, {0, 1, 2, 2, 0, -1}, {-1, 1, 3, 2, -1, -1}};
    printChord(c2);

    return 0;
}
