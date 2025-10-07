#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

// Gyak 01 - Írj programot, ami beolvas 10 számot, és kiírja a legnagyobbat és legkisebbet!
void beolvas_tiz_szamot()
{
    int szamok[10];
    cout << "Adj meg 10 szamot:" << endl;
    for (int i = 0; i < sizeof(szamok) / sizeof(szamok[0]); i++)
    {
        cin >> szamok[i];
    }

    int legnagyobb = szamok[0];
    int legkisebb = szamok[0];

    for (int i = 1; i < sizeof(szamok) / sizeof(szamok[0]); i++)
    {
        if (szamok[i] > legnagyobb)
            legnagyobb = szamok[i];
        if (szamok[i] < legkisebb)
            legkisebb = szamok[i];
    }

    cout << "Legnagyobb: " << legnagyobb << endl;
    cout << "Legkisebb: " << legkisebb << endl;
}


// Segedfuggveny a tomb kiirasahoz
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Gyak 02 - Írj programot, ami visszaadja, hány elem nagyobb az átlagosnál!
int nagyobb_atlagosnal(int szamok[], int meret)
{
    double atlag = 0.0;
    for (int i = 0; i < meret; i++)
    {
        atlag += szamok[i];
    }
    atlag /= meret;

    int count = 0;
    for (int i = 0; i < meret; i++)
    {
        if (szamok[i] > atlag)
        {
            count++;
        }
    }
    return count;
}

// Gyak 03 - Írj programot, ami kiszámolja egy mátrix főátlójának és mellékátlójának különbségét!
int fo_atlo_osszeg(int matrix[3][3])
{
    int fo_atlo = 0;
    for (int i = 0; i < 3; i++)
    {
        fo_atlo += matrix[i][i];
    }
    return fo_atlo;
}

int mellek_atlo_osszeg(int matrix[3][3])
{
    int mellek_atlo = 0;
    for (int i = 0; i < 3; i++)
    {
        mellek_atlo += matrix[i][2 - i];
    }
    return mellek_atlo;
}

int fo_atlo_mellek_atlo_kulonbseg(int matrix[3][3])
{
    int fo_atlo = fo_atlo_osszeg(matrix);
    int mellek_atlo = mellek_atlo_osszeg(matrix);
    return abs(fo_atlo - mellek_atlo);
}

// Gyak 04 - Írj programot, ami eldönti, hogy egy szó palindrom-e (pl. “radar”).
bool palindrom_e(const string &s)
{
    int bal = 0;
    int jobb = s.length() - 1;

    while (bal < jobb)
    {
        if (s[bal] != s[jobb])
            return false;
        bal++;
        jobb--;
    }
    return true;
}

// Gyak 05 - Írj programot, ami két szöveget összefűz egy harmadikba C-string használatával!
void osszefuz_cstring()
{
    char szo1[100], szo2[100], eredmeny[200];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo1;
    cout << "Kerlek, adj meg egy masik szot: ";
    cin >> szo2;

    // C-string összefűzés
    strcpy(eredmeny, szo1);
    strcat(eredmeny, szo2);
    cout << "Az osszefuzott szoveg: " << eredmeny << endl;
}

// Extra kihívás: Írj programot, ami megszámolja, hány magánhangzó van egy beolvasott mondatban!
void megszamol_maganhangzok()
{
    char mondat[256];
    cout << "Kerlek, adj meg egy mondatot: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(mondat, 256);

    int maganhangzok = 0;
    for (int i = 0; mondat[i] != '\0'; i++) {
        char c = tolower(mondat[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            maganhangzok++;
        }
    }

    cout << "Maganhangzok szama: " << maganhangzok << endl;
}

int main()
{
    // Gyak 01
    beolvas_tiz_szamot();

    // Gyak 02
    int szamok[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int meret = sizeof(szamok) / sizeof(szamok[0]);
    int db_nagyobb = nagyobb_atlagosnal(szamok, meret);
    cout << "Hany elem nagyobb az atlagosnal: " << db_nagyobb << endl;

    // Gyak 03
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int kulonbseg = fo_atlo_mellek_atlo_kulonbseg(matrix);
    cout << "A foatlo es mellekatlo kulonbsege: " << kulonbseg << endl;

    // Gyak 04
    char szo[100];
    cout << "Kerlek, adj meg egy szot: ";
    cin >> szo;
    if (palindrom_e(szo))
        cout << szo << " palindrom." << endl;
    else
        cout << szo << " nem palindrom." << endl;

    // Gyak 05
    osszefuz_cstring();

    // Extra kihívás
    megszamol_maganhangzok();

    return 0;
}