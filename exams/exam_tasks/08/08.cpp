#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
void draw(const string& commands);

int main() {
    cout << "Test\tResult" << endl;
    cout << "draw(\"DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL\");" << endl;

    draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");

    return 0;
}