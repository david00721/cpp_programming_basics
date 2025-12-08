#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype - implement this function
string* fullNameSort(string fbe, string fki);

int main() {
    string* sorted = fullNameSort("authors_in.txt", "authors_out.txt");

    if (sorted) {
        // A bemeneti file első sorában lévő n értéket neked kell majd beolvasnod a függvényben.
        // Itt példaként feltételezzük, hogy 8 elem volt.
        int n = 8;

        cout << "RENDEZETT NEVEK:" << endl;
        for (int i = 0; i < n; i++) {
            cout << sorted[i] << endl;
        }

        delete[] sorted;
    }

    return 0;
}
