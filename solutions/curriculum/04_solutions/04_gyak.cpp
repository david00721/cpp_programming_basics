#include <iostream>
#include <cstring>

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

// Segedfuggveny swap
void csere(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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

// Gyak 02 - Írj programot, ami rendezi egy tömb elemeit növekvő sorrendbe!
void rendezes_novekvo(int szamok[], int meret)
{
    // Bubble sort algoritmus
    for (int i = 0; i < meret - 1; i++)
    {
        for (int j = 0; j < meret - i - 1; j++)
        {
            if (szamok[j] > szamok[j + 1])
            {
                csere(szamok[j], szamok[j + 1]);
            }
        }
    }
}

// Gyak 03 - Írj programot, ami kiszámolja egy mátrix főátlójának összegét!
int fo_atlo_osszeg(int matrix[3][3])
{
    int osszeg = 0;

    for (int i = 0; i < 3; i++)
    {
        osszeg += matrix[i][i];
    }
    return osszeg;
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

int main()
{
    // Gyak 01
    beolvas_tiz_szamot();

    // Gyak 02
    int szamok[] = {5, 2, 9, 1, 5, 6};
    int meret = sizeof(szamok) / sizeof(szamok[0]);
    rendezes_novekvo(szamok, meret);
    cout << "Rendezett tomb: ";
    printArray(szamok, meret);

    // Gyak 03
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "A matrix foatlajanak osszege: " << fo_atlo_osszeg(matrix) << endl;
    
    // Gyak 04
    string szo;
    cout << "Adj meg egy szot: ";
    cin >> szo;
    if (palindrom_e(szo))
        cout << szo << " palindrom." << endl;
    else
        cout << szo << " nem palindrom." << endl;

    // Gyak 05
    osszefuz_cstring();
    
    return 0;
}