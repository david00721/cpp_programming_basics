#include <iostream>
#include <cstring>

using namespace std;

// 11 - Írj egy függvényt, ami beolvas egy szót, és kiírja azt!
void beolvas_es_kiir()
{
    string szo;
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo;
    cout << "A megadott szo: " << szo << endl;
}

// 12 - Írj egy függvényt, ami beolvas egy mondatot `getline`-nel, majd kiírja a hosszát!
void beolvas_mondat_es_kiir_hossz()
{
    string mondat;
    cout << "Kerlek, adj meg egy mondatot: ";
    cin.ignore(); // Eltavolitja a bemeneti pufferben maradt '\n' karaktert
    getline(cin, mondat);
    cout << "A mondat hossza: " << mondat.length() << endl;
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

// 14 - Írj programot, ami két szót összehasonlít `strcmp`-pal, és kiírja, melyik van előbb az ABC-ben!
void osszehasonlit_szavak()
{
    char szo1[100], szo2[100];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo1;
    cout << "Kerlek, adj meg egy masik szot: ";
    cin >> szo2;
    int eredmeny = strcmp(szo1, szo2);
    if (eredmeny < 0)
        cout << szo1 << " van elobb az ABC-ben, mint " << szo2 << endl;
    else if (eredmeny > 0)
        cout << szo2 << " van elobb az ABC-ben, mint " << szo1 << endl;
    else
        cout << "A ket szo egyenlo." << endl;
}

int main()
{
    beolvas_es_kiir();
    beolvas_mondat_es_kiir_hossz();
    osszefuz_szavak();
    osszehasonlit_szavak();
    return 0;
}
