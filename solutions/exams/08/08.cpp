#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
void draw(const string& commands)
{
    const int width = 11;
    const int height = 11;
    char canvas[height][width];

    // Initialize canvas with spaces
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            canvas[i][j] = ' ';
        }
    }

    int x = 0, y = 0;
    canvas[y][x] = '*'; // Mark starting position

    // for (char command : commands) {
    for (size_t i = 0; i < commands.size(); ++i) {
        char command = commands[i];
        switch (command) {
            case 'U':
                if (y > 0) y--;
                break;
            case 'D':
                if (y < height - 1) y++;
                break;
            case 'L':
                if (x > 0) x--;
                break;
            case 'R':
                if (x < width - 1) x++;
                break;
        }
        canvas[y][x] = '*'; // Mark current position
    }

    // Print the canvas
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

int main() {
    cout << "Test\tResult" << endl;
    cout << "draw(\"DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL\");" << endl;

    draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");

    return 0;
}