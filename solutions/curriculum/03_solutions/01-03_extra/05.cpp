#include <iostream>
using namespace std;

// Üres négyzet
void hollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Üres háromszög
void hollowTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Ez a függvény egy üres rombuszt rajzol ki csillagokkal.
// A rombusz "üres", tehát csak a szélei vannak kirajzolva,
// a belseje szóköz.
//
// Példa, ha n = 4:
//
//    *    
//   * *   
//  *   *  
// *     * 
//  *   *  
//   * *   
//    *    
//
// Paraméter:
//   n - a rombusz "fele" magassága, azaz a középső sor feletti sorok száma
//
void hollowDiamond(int n) {
    // --- felső rész (1-től n-ig növekvő sorok) ---
    for (int i = 1; i <= n; i++) {
        // szóközök bal oldalon, hogy középre igazítsuk a rombuszt
        for (int j = 0; j < n - i; j++) cout << " ";

        // csillagok és belső üres helyek
        for (int j = 1; j <= 2*i-1; j++) {
            // az első és utolsó pozícióban legyen csillag
            if (j == 1 || j == 2*i-1) cout << "*";
            // közte üres hely
            else cout << " ";
        }
        cout << endl;
    }

    // --- alsó rész (n-1-től 1-ig csökkenő sorok) ---
    for (int i = n-1; i >= 1; i--) {
        // szóközök bal oldalon
        for (int j = 0; j < n - i; j++) cout << " ";

        // csillagok és belső üres helyek
        for (int j = 1; j <= 2*i-1; j++) {
            if (j == 1 || j == 2*i-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int meret, valasztas;
    cout << "Valassz alakzatot:\n1 - Ures negyzet\n2 - Ures haromszog\n3 - Ures rombusz\n";
    cin >> valasztas;
    cout << "Add meg a meretet: ";
    cin >> meret;

    switch (valasztas) {
        case 1: hollowSquare(meret); break;
        case 2: hollowTriangle(meret); break;
        case 3: hollowDiamond(meret); break;
        default: cout << "Ervenytelen valasztas." << endl;
    }

    return 0;
}