#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype - implement this function
void rightAlign(const string& fileName)
{
    ifstream in(fileName);
    if (!in) {
        cerr << "Hiba: Nem lehet megnyitni a fajlt: " << fileName << endl;
        return;
    }

    string lines[100];
    int count = 0;
    size_t maxLength = 0;

    // Beolvassuk a fájl sorait és meghatározzuk a leghosszabb sort
    while (getline(in, lines[count])) {
        size_t len = lines[count].length();
        if (len > maxLength) {
            maxLength = len;
        }
        count++;
    }
    in.close();

    // Print
    for (int i = 0; i < count; i++) {
        size_t len = lines[i].length();
        size_t spacesToAdd = maxLength - len;
        for (size_t j = 0; j < spacesToAdd; j++) {
            cout << ' ';
        }
        cout << lines[i] << endl;
    }
}

int main() {
    cout << "rightAlign(\"file1.txt\");\n";
    rightAlign("file1.txt");

    cout << "\nFile tartalma:\n";
    
    // kiíratjuk a fájl tartalmát is, ahogy a példa mutatja
    ifstream in("file1.txt");
    if (in) {
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "(file1.txt nem talalhato)" << endl;
    }

    return 0;
}