#include <iostream>

/**
 * row_with_max_sum
 * -----------------
 * A függvény megkeresi, melyik sornak a legnagyobb az elemsumája
 * egy sorfolytonosan tárolt rows × cols mátrixban.
 *
 * Feltételek:
 *  - pointeraritmetika használata: *(matrix + r*cols + c)
 *  - ha több sornak is ugyanakkora az összege, a kisebb indexű sor nyer
 *  - ha rows == 0 vagy cols == 0 -> visszatérés: -1
 *
 * Paraméterek:
 *   matrix  - bemeneti mátrix (sorfolytonosan tárolva)
 *   rows    - sorok száma
 *   cols    - oszlopok száma
 *
 * Visszatérés:
 *   a legnagyobb összegű sor indexe
 */
int row_with_max_sum(const int* matrix, int rows, int cols) {
    // üres mátrix esetén nincs értelmezhető sor
    if (rows <= 0 || cols <= 0) {
        return -1;
    }

    int bestRow = 0;      // a legnagyobb összegű sor indexe
    int bestSum = 0;      // a legnagyobb talált összeg

    // első sor összegének kiszámítása a kiinduláshoz
    for (int c = 0; c < cols; ++c) {
        bestSum += *(matrix + c);
    }

    // indulunk a második sortól, mert az elsőt már feldolgoztuk
    for (int r = 1; r < rows; ++r) {
        int currentSum = 0;

        // aktuális sor összege: *(matrix + r*cols + c)
        for (int c = 0; c < cols; ++c) {
            currentSum += *(matrix + r * cols + c);
        }

        // ha jobb összeget találtunk, frissítjük
        if (currentSum > bestSum) {
            bestSum = currentSum;
            bestRow = r;
        }
    }

    return bestRow;
}

int main() {
    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    int result = row_with_max_sum(&matrix[0][0], rows, cols);
    std::cout << "A legnagyobb összegű sor indexe: " << result << std::endl;

    return 0;
}