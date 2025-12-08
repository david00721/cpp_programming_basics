#include <iostream>
#include <string>

using namespace std;

// Prototype - implement this function
string* lastFirstName() {
    int n = 3; // Például 3 szerző, de ez legyen változtatható!
    string* arr = new string[n];

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        size_t p = line.find(',');
        string last = line.substr(0, p);
        string first = line.substr(p + 2);   // feladat szerint: vessző + szóköz

        arr[i] = first + " " + last;
    }

    return arr;
}

int main() {
    string* szerzok = lastFirstName();
    cout << endl;

    if (szerzok) {
        // A példában 8 elem van → itt nem tudjuk előre, ezért kérd be külön, ha kell.
        int n = 3;
        for (int i = 0; i < n; i++) {
            cout << szerzok[i] << endl;
        }

        delete[] szerzok;
        szerzok = 0;
    }

    return 0;
}
