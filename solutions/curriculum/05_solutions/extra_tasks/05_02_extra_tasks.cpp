#include <iostream>

/**
 * kulso_szorzas
 * --------------
 * A függvény két vektort kap bemenetként:
 *   - oszlop:   no elemű oszlopvektor
 *   - sor:      ns elemű sorvektor
 *
 * Feladat:
 *   Az oszlop és sor minden elemét összeszorozzuk,
 *   és az eredményt egy no × ns méretű mátrixba írjuk.
 *
 * Megkötések:
 *   - A mátrix memóriáját nem itt foglaljuk, azt a hívó biztosítja.
 *   - sorfolytonos tárolás: matrix[r * ns + c]
 *   - Nem használunk dinamikus memóriát vagy STL konténert.
 *
 * Példa:
 *   oszlop = { 1, 2, 3 }
 *   sor    = { 4, 5 }
 *
 *   matrix =
 *     4   5
 *     8  10
 *    12  15
 *
 * Paraméterek:
 *   oszlop  - mutató az első vektor elejére
 *   no      - oszlopvektor mérete
 *   sor     - mutató a második vektor elejére
 *   ns      - sorvektor mérete
 *   matrix  - mutató a kimeneti mátrix első elemére
 */
void kulso_szorzas(
    const int* oszlop, int no,
    const int* sor, int ns,
    int* matrix
) {
    // Két egymásba ágyazott ciklus:
    // külső: a sorok (oszlopvektor elemei)
    // belső: az oszlopok (sorvektor elemei)
    for (int r = 0; r < no; ++r) {
        for (int c = 0; c < ns; ++c) {
            // matrix[r][c] = oszlop[r] * sor[c]
            *(matrix + r * ns + c) = *(oszlop + r) * *(sor + c);
        }
    }
}

int main() {
    const int oszlop[] = { 1, 2, 3 };
    const int sor[] = { 4, 5 };
    const int no = sizeof(oszlop) / sizeof(oszlop[0]);
    const int ns = sizeof(sor) / sizeof(sor[0]);

    int matrix[no][ns];  // A mátrix deklarálása

    kulso_szorzas(oszlop, no, sor, ns, &matrix[0][0]);

    // Eredmény kiírása
    for (int r = 0; r < no; ++r) {
        for (int c = 0; c < ns; ++c) {
            std::cout << matrix[r][c] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}