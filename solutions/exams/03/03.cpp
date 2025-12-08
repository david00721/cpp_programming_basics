#include <iostream>

using namespace std;

// Prototype - implement this function
int szamtani(int a0, int d, bool uj)
{
    static int n = 0;
    if (uj) {
        n = 0;
        return a0;
    } else {
        n++;
        return a0 + n * d;
    }
}

int main() {
    cout << szamtani(0, 1, true);
    for (int i = 0; i < 9; i++) {
        cout << ' ' << szamtani(0, 1, false);
    }
    cout << endl;

    cout << szamtani(5, 3, true);
    for (int i = 0; i < 5; i++) {
        cout << ' ' << szamtani(5, 3, false);
    }
    cout << endl;

    return 0;
}