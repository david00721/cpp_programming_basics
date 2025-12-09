#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype - implement this function
void rightAlign(const string& fileName)
{
    ifstream in(fileName);
    if (!in) {
        cout << "Hiba: Nem lehet megnyitni a fajlt: " << fileName << endl;
        return;
    }

    string line;
    int count = 0;
    size_t maxLength = 0;

    // 1. menet: hány sor és melyik a leghosszabb
    while (getline(in, line)) {
        count++;
        if (line.length() > maxLength)
            maxLength = line.length();
    }

    in.clear();       // EOF törlése
    in.seekg(0);      // vissza a fájl elejére

    // 2. menet: sorok beolvasása és kiírás jobbra igazítva
    while (getline(in, line)) {
        size_t spaces = maxLength - line.length();
        for (size_t i = 0; i < spaces; i++)
            cout << ' ';

        cout << line << endl;
    }

    in.close();
}

int main() {
    cout << "\nFile tartalma:\n";
    ifstream in("file1.txt");
    if (!in) {
        cout << "(file1.txt nem talalhato)" << endl;
        return 0;
    }

    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    cout << endl;
    in.close();

    rightAlign("file1.txt");
}