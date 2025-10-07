#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

// 11 - Írj programot, ami beolvas egy szót, és kiírja azt visszafelé!
void beolvas_es_kiir()
{
    char szo[100];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo;
    cout << "A megadott szo visszafele: ";
    for (int i = strlen(szo) - 1; i >= 0; i--) {
        cout << szo[i];
    }
    cout << endl;
    cout << "A megadott szo: " << szo << endl;
}

// 12 - Írj programot, ami beolvas egy mondatot getline-nel, majd megszámolja, hány szó van benne!
void beolvas_mondat_es_megszamol_szavak()
{
    char mondat[256];
    cout << "Kerlek, adj meg egy mondatot: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(mondat, 256);

    int szavak = 1; // legalább egy szó van
    for (int i = 0; mondat[i] != '\0'; i++) {
        if (mondat[i] == ' ') {
            szavak++;
        }
    }

    cout << "Szavak szama: " << szavak << endl;
}

// 13 - Írj programot, ami két szót összefűz `strcat` segítségével!
void osszefuz_szavak()
{
    char szo1[100], szo2[100];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo1;
    cout << "Kerlek, adj meg egy masik szot: ";
    cin >> szo2;
    strcat(szo1, szo2);
    cout << "Osszefuzott szo: " << szo1 << endl;
}

// 14 - Írj programot, ami megvizsgálja, hogy két szó egyezik-e (strcmp), és ha nem, kiírja, melyik hosszabb!
void osszehasonlit_szavak()
{
    char szo1[100], szo2[100];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo1;
    cout << "Kerlek, adj meg egy masik szot: ";
    cin >> szo2;

    int eredmeny = strcmp(szo1, szo2);
    if (eredmeny == 0) {
        cout << "A ket szo egyezik." << endl;
    } else {
        cout << "A ket szo nem egyezik." << endl;
        if (strlen(szo1) > strlen(szo2)) {
            cout << "Az elso szo hosszabb." << endl;
        } else if (strlen(szo1) < strlen(szo2)) {
            cout << "A masodik szo hosszabb." << endl;
        } else {
            cout << "A ket szo egyforma hosszú." << endl;
        }
    }
}

int main()
{
    beolvas_es_kiir();
    beolvas_mondat_es_megszamol_szavak();
    osszefuz_szavak();
    osszehasonlit_szavak();
    return 0;
}
