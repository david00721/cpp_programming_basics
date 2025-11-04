#include <iostream>

/**
 * print_longest_common_substring
 * ------------------------------
 * A függvény megkap két NEM feltétlenül null-terminált karaktertömböt
 * és azok méretét, majd megkeresi a leghosszabb közös FOLYTONOS részletet
 * (longest common substring), és kiírja a képernyőre.
 *
 * Megkötések:
 *  - Nem használunk dinamikus memóriát.
 *  - Nem használunk STL tárolókat vagy algoritmusokat.
 *  - Pointereket és ciklusokat használunk.
 *  - Ha nincs közös rész, kiírjuk: "Nincs közös rész."
 *
 * Bemenet:
 *   a  - első karaktertömb kezdőcíme
 *   na - első tömb hossza
 *   b  - második karaktertömb kezdőcíme
 *   nb - második tömb hossza
 *
 * Kimenet:
 *   A függvény kiírja a megtalált leghosszabb közös substringet.
 */

void print_longest_common_substring(const char* a, int na, const char* b, int nb)
{
    int maxLen = 0;         // a leghosszabb egyezés hossza
    int maxPosA = 0;        // a leghosszabb egyezés kezdőpozíciója az 'a' tömbben

    // Külső ciklus: végigmegyünk az 'a' tömb elemein
    for (int i = 0; i < na; i++) {
        const char* pa = a + i; // pointer az 'a' tömb aktuális helyére

        // Belső ciklus: végigmegyünk a 'b' tömb elemein
        for (int j = 0; j < nb; j++) {
            const char* pb = b + j; // pointer a 'b' tömb aktuális helyére

            // Ha az aktuális karakterek nem egyeznek, nincs mit vizsgálni
            if (*pa != *pb) {
                continue;
            }

            // Ha egyezés van, elindulunk előrefelé, amíg egyeznek a karakterek
            int length = 0;
            const char* p1 = pa;
            const char* p2 = pb;
            
            // Ez a feltétel azt biztosítja, hogy a pointerek nem lépnek ki a tömb határain kívülre, miközben előre haladunk és hasonlítgatjuk a karaktereket.
            while (p1 < a + na && p2 < b + nb && *p1 == *p2) {
                length++;
                p1++;
                p2++;
            }

            // Frissítjük a leghosszabb talált szakaszt
            if (length > maxLen) {
                maxLen = length;
                maxPosA = i;
            }
        }
    }

    // Ha nem találtunk közös részt
    if (maxLen == 0) {
        std::cout << "Nincs közös rész." << std::endl;
        return;
    }

    // Kiírjuk a leghosszabb közös részt
    for (int k = 0; k < maxLen; k++) {
        std::cout << *(a + maxPosA + k);
    }
    std::cout << std::endl;
}

int main(){
    const char* a = "abcdef";
    const char* b = "zcdemf";
    print_longest_common_substring(a, 6, b, 6);
    return 0;
}