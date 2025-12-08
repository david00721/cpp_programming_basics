#include <iostream>
#include <cctype>

using namespace std;

const int MAXHOSSZ = 50;

// Prototype - implement this function
int feltoltNagybetu(char szovegTb[]) {
    int i = 0;
    char c;

    while (i < MAXHOSSZ && cin.get(c) && c != '\n') {
        if (islower(c)) c = toupper(c);
        szovegTb[i++] = c;
    }
    szovegTb[i] = '\0'; // lezárás
    return i;
}

// Prototype - implement this function
void cserel(char szovegTb[], int hossz) {
    int index = 0;
    int szam = 1; // a szavak mediánjába kerülő növekvő szám

    while (index < hossz) {
        // Szó elejének megkeresése (betű vagy szám)
        if (isalnum(szovegTb[index])) {
            int start = index;

            // Szó vége
            while (index < hossz && isalnum(szovegTb[index])) {
                index++;
            }

            int end = index - 1;
            int wordLen = end - start + 1;

            // Medián pozíciók meghatározása
            if (wordLen % 2 == 1) {
                // Páratlan → 1 karakter cserélődik
                int mid = start + wordLen / 2;
                szovegTb[mid] = '0' + szam;
            } else {
                // Páros → 2 karakter cserélődik
                int mid1 = start + (wordLen / 2) - 1;
                int mid2 = start + (wordLen / 2);
                szovegTb[mid1] = '0' + szam;
                szovegTb[mid2] = '0' + szam;
            }

            szam++;
        } else {
            index++;
        }
    }

    // Kiírás
    cout << szovegTb << endl;
}

int main() {
    char szoveg[MAXHOSSZ + 1];

    int hossz = feltoltNagybetu(szoveg);
    cserel(szoveg, hossz);

    return 0;
}
