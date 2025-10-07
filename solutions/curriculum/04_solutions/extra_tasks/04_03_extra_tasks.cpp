#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int kep[N][N];

    cout << "Adj meg egy 5x5-os matrixot (0 vagy 1 ertekek):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Add meg a [" << i + 1 << "][" << j + 1 << "] elemet: ";
            cin >> kep[i][j];
        }
    }

    int aktiv = 0;
    cout << "\nA kep:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (kep[i][j] == 1) {
                cout << "# ";
                aktiv++;
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    cout << "\nAktiv pixelek szama: " << aktiv << endl;
    return 0;
}