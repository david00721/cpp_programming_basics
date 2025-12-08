#include <iostream>

using namespace std;

// Prototype - implement this function
void printGantt(int mtx[][2], int n);

int main() {
    int mtx[][2] = {
        {0, 3},
        {1, 5},
        {3, 9}
    };
    int n = sizeof(mtx) / sizeof(mtx[0]);

    printGantt(mtx, n);

    // További teszt
    cout << endl;

    int mtx2[][2] = {
        {0, 0},
        {2, 4},
        {5, 7}
    };
    int n2 = sizeof(mtx2) / sizeof(mtx2[0]);

    printGantt(mtx2, n2);

    return 0;
}
