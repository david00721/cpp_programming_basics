#include <iostream>

using namespace std;

/*
Definiálja az int** szorzat(int* oszlop, int no, int* sor, int ns) függvényt, ami az no elemű oszlop oszlopvektor és
az ns elemű sor sorvektor elemeiből készíthető valamennyi párt összeszorozza, és a szorzatokat tartalmazó,
no sorból és ns oszlopból álló mátrixot adja eredményül!
*/

int** szorzat(int* oszlop, int no, int* sor, int ns) {
    int** matrix = new int*[no];                 // mátrix sorainak lefoglalása
    for (int i = 0; i < no; i++) {
        matrix[i] = new int[ns];                 // minden sorhoz lefoglaljuk az oszlopokat
        for (int j = 0; j < ns; j++) {
            matrix[i][j] = oszlop[i] * sor[j];   // i. sor * j. oszlop → szorzat beírása
        }
    }
    return matrix;                               // visszaadjuk a kész mátrixot
}

void nyomtat(int* oszlop, int no, int* sor, int ns, int** matrix) {
    cout << "\t";                                // első sor eleje üres
    for (int j = 0; j < ns; j++) {
        cout << sor[j] << "\t";                  // fejlécként kiírjuk a sorvektor elemeit
    }
    cout << endl;
    for (int i = 0; i < no; i++) {
        cout << oszlop[i] << "\t";               // sor elején az oszlopvektor eleme
        for (int j = 0; j < ns; j++) {
            cout << matrix[i][j] << "\t";        // mátrix celláinak kiírása
        }
        cout << endl;
    }
}

void felszabadit(int** matrix, int no) {
    for (int i = 0; i < no; i++) {
        delete[] matrix[i];                      // minden sor felszabadítása
    }
    delete[] matrix;                             // sorpointerek felszabadítása
}

int main()
{
    int oszlop[] = {1, 2, 3};                    // oszlopvektor
    int sor[] = {4, 5};                          // sorvektor

    int no = sizeof(oszlop) / sizeof(oszlop[0]); // oszlopvektor hossza
    int ns = sizeof(sor) / sizeof(sor[0]);       // sorvektor hossza
    int** result = szorzat(oszlop, no, sor, ns); // mátrix kiszámítása

    nyomtat(oszlop, no, sor, ns, result);        // mátrix kiíratása
    felszabadit(result, no);                     // memória felszabadítása

    return 0;                                    // program vége
}
