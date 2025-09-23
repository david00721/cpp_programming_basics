#include <iostream>

using namespace std;

/*
Definiálja azt a void stackedBarChart(int** data, int rows, int cols) függvényt, ami halmozott sávdiagramot rajzol 
a rows sorból és cols oszlopból álló data mátrix elemeit felhasználva! 
A sávdiagram annyi sorból álljon, amennyi rows értéke! A sorokat rendre az X, >, +, = és - jelekkel kell megrajzolni. 
Mindegyikből annyit kell egymás mellé írni, amennyi a mátrix aktuális sorában a soron következő cella értéke. 
Ha a mátrixnak 5-nél több oszlopa lenne, csak az első 5-öt kell megrajzolni.
*/

void stackedBarChart(int** data, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {                        // végigmegyünk a sorokon
        for (int j = 0; j < cols && j < 5; ++j) {           // oszloponként, max. 5-ig
            char symbol;                                    // a sorhoz tartozó jel
            switch (j) {                                    // oszlop indexhez tartozó jel
                case 0: symbol = 'X'; break;
                case 1: symbol = '>'; break;
                case 2: symbol = '+'; break;
                case 3: symbol = '='; break;
                case 4: symbol = '-'; break;
            }
            for (int k = 0; k < data[i][j]; ++k) {          // cella értékének megfelelően ismételjük
                cout << symbol;                             // kiírjuk a jelet
            }
        }
        cout << endl;                                       // sor vége
    }
}

int** createMtx(int* vec, int rows, int cols) {
    int** mtx = new int*[rows];                             // lefoglaljuk a sorokat
    for (int i = 0; i < rows; ++i) {
        mtx[i] = new int[cols];                             // lefoglaljuk az oszlopokat
        for (int j = 0; j < cols; ++j) {
            mtx[i][j] = vec[i * cols + j];                  // feltöltjük a mátrixot a vektor alapján
        }
    }
    return mtx;                                             // visszaadjuk a mátrix pointerét
}

void deleteMtx(int** mtx, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] mtx[i];                                    // sorok felszabadítása
    }
    delete[] mtx;                                           // pointer tömb felszabadítása
}

int main()
{
    int vec[6] = {                                         // bemeneti adatok 1D tömbben
        1, 5,
        3, 3,
        5, 3
    };

    int** data = createMtx(vec, 3, 2);                     // 3x2-es mátrix létrehozása
    stackedBarChart(data, 3, 2);                           // sávdiagram kirajzolása
    deleteMtx(data, 3);                                    // memória felszabadítása

    return 0;                                              // program vége
}
