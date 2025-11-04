#include <iostream>

/**
 * find_saddle_point
 * ------------------
 * Feladat:
 *   Keressünk nyeregpontot egy sorfolytonosan (row-major) tárolt egész mátrixban.
 *   Egy (r,c) pozíció nyeregpont, ha:
 *     - az elem a saját SORÁBAN minimum (balról a legelső minimumot vegyük),
 *     - és a saját OSZLOPÁBAN maximum.
 *
 * Döntetlenek kezelése:
 *   - Ha több nyeregpont is létezik, a legkisebb sorindexű nyer.
 *   - Azonos sorban több minimum közül a legkisebb oszlopindexűt vizsgáljuk először.
 *   - A keresést sor- majd oszlop-sorrendben végezve az első érvényes nyeregpont
 *     kielégíti a fenti döntési szabályt.
 *
 * Paraméterek:
 *   matrix  : const int*  -- a mátrix első elemére mutató pointer (row-major)
 *   rows    : int         -- sorok száma
 *   cols    : int         -- oszlopok száma
 *   out_row : int*        -- ide írjuk a megtalált nyeregpont sorindexét
 *   out_col : int*        -- ide írjuk a megtalált nyeregpont oszlopindexét
 *
 * Visszatérés:
 *   true  : ha találtunk nyeregpontot, és out_row/out_col be van állítva
 *   false : ha nincs nyeregpont vagy a bemenet üres (rows==0 || cols==0)
 *
 * Megjegyzés a címzéshez (row-major):
 *   Az (r,c) elem címe: matrix + r*cols + c
 *   Az értéke: *(matrix + r*cols + c)
 */
bool find_saddle_point(
    const int* matrix, int rows, int cols,
    int* out_row, int* out_col
) {
    if (!matrix || rows <= 0 || cols <= 0) {
        return false;
    }

    for (int r = 0; r < rows; ++r) {
        // 1) Keressük meg az r-edik sor minimumát és annak baloldali (legkisebb) oszlopindexét.
        int c_min = 0;
        const int* row_base = matrix + r * cols;
        int row_min_val = *row_base; // kiindulás az első elemből

        for (int c = 1; c < cols; ++c) {
            int val = *(row_base + c);
            if (val < row_min_val) {
                row_min_val = val;
                c_min = c; // új baloldali minimum
            }
            // ha val == row_min_val, akkor a már meglévő (baloldalibb) c_min marad
        }

        // 2) Ellenőrizzük, hogy a (r, c_min) elem az oszlopában maximum-e.
        bool is_col_max = true;
        for (int rr = 0; rr < rows; ++rr) {
            int col_val = *(matrix + rr * cols + c_min);
            if (col_val > row_min_val) {
                is_col_max = false;
                break;
            }
        }

        if (is_col_max) {
            if (out_row) *out_row = r;
            if (out_col) *out_col = c_min;
            return true; // az első (legkisebb sorindexű, azon belül legkisebb oszlopindexű) nyeregpont
        }
    }

    return false; // nem találtunk nyeregpontot
}

int main() {
    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    int saddle_row = -1;
    int saddle_col = -1;

    if (find_saddle_point(&matrix[0][0], rows, cols, &saddle_row, &saddle_col)) {
        std::cout << "Nyeregpont található a következő pozíción: ("
                  << saddle_row << ", " << saddle_col << ")" << std::endl;
    } else {
        std::cout << "Nincs nyeregpont a mátrixban." << std::endl;
    }

    return 0;
}