#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype - implement this function
void rightAlign(const string& fileName);

int main() {
    cout << "Test\tResult\n";
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