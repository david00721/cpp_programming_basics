#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
string* lastFirstName();

int main() {
    string* szerzok = lastFirstName();

    if (szerzok) {
        // A példában 8 elem van → itt nem tudjuk előre, ezért kérd be külön, ha kell.
        int n = 8;
        for (int i = 0; i < n; i++) {
            cout << szerzok[i] << endl;
        }

        delete[] szerzok;
        szerzok = 0;
    }

    return 0;
}
