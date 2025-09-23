#include <iostream>

using namespace std;

/*
Készítse el az int szamtani(int a0, int d, bool uj) függvényt! 
Ha az uj paraméter értéke true,
akkor a függvény felkészül az an+1 = an + d képletű számtani sorozat elemeinek előállítására, 
és visszatérési értéke a0 lesz.
Ha az uj paraméter értéke false, akkor a korábban meghatározott sorozat következő elemének értékét szolgáltatja.
*/

int szamtani(int a0, int d, bool uj) {
    static int an = a0;        // megőrzi az aktuális állapotot a függvényhívások között
    if (uj) {                  // ha új sorozatot indítunk
        an = a0;               // kezdőérték beállítása
        return a0;             // visszaadja az első elemet
    } else {                   // ha nem új sorozat
        an += d;               // a következő elem kiszámítása
        return an;             // visszaadja az új elemet
    }
}

int main()
{
    std::cout << szamtani(0, 1, true); // új sorozat indítása: 0-tól, differencia = 1
    
    for(int i = 0; i < 9; i++) {
        std::cout << ' ' << szamtani(0, 1, false); // következő 9 elem lekérése
    }
    std::cout << std::endl; // sor vége

    return 0; // program vége
}
