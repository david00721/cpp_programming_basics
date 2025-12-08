#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype - implement this function
void center(const string& fileName)
{
    ifstream file(fileName);
    if(!file) {
        cerr << "Hiba: Nem lehet megnyitni a fajlt: " << fileName << endl;
        return;
    }

    string line;
    int maxLength = 0;

    // First pass: find the length of the longest line
    while (getline(file, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    // Reset file stream to beginning
    file.clear();
    file.seekg(0, ios::beg);

    // Second pass: print each line centered
    while (getline(file, line)) {
        int totalSpaces = maxLength - line.length();
        int leadingSpaces = totalSpaces / 2;

        // Print leading spaces manually
        for (int i = 0; i < leadingSpaces; ++i) {
            cout << ' ';
        }

        cout << line;

        // Print trailing spaces manually
        for (size_t i = 0; i < totalSpaces - leadingSpaces; ++i) {
            cout << ' ';
        }

        cout << endl;
    }

    file.close();
}


int main() {
    center("file1.txt");

    return 0;
}