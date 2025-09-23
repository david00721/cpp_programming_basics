#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Készítse el azt a void rightAlign(const std::string& fileName) függvényt,
mely a paraméterként kapott nevű fájl sorait jobbra igazítva jeleníti meg a képernyőn!
Keresse meg a leghosszabb sort, és annak jobb széléhez igazítsa az összes többi sor tartalmát!
*/

void rightAlign(const std::string& fileName)
{
    std::ifstream file(fileName);                         // fájl megnyitása
    if (!file) {                                          // ha nem sikerül
        std::cerr << "Cannot open file: " << fileName << std::endl;
        return;
    }

    // --- Első kör: sorok számolása + max hossz ---
    int lineCount = 0;                                    // sorok száma
    size_t maxLen = 0;                                    // leghosszabb sor hossza
    std::string line;

    while (std::getline(file, line)) {                    // beolvassuk soronként
        lineCount++;                                      // sorok számlálása
        if (line.length() > maxLen) {                     // ha hosszabb a sor
            maxLen = line.length();                       // frissítjük a max hosszt
        }
    }

    // --- Újranyitjuk a fájlt olvasáshoz ---
    file.clear();                                         // stream hibajelzők törlése
    file.seekg(0);                                        // vissza az elejére

    // --- Dinamikus tömb lefoglalása ---
    std::string* lines = new std::string[lineCount];      // sorok tárolása dinamikusan

    int idx = 0;
    while (std::getline(file, line) && idx < lineCount) { // sorok beolvasása újra
        lines[idx++] = line;
    }
    file.close();                                         // fájl lezárása

    // --- Kiírás jobbra igazítva ---
    for (int i = 0; i < lineCount; i++) {
        std::cout << std::string(maxLen - lines[i].length(), ' ') // balra szóközök
                  << lines[i] << std::endl;                       // majd a sor tartalma
    }

    // --- Felszabadítás ---
    delete[] lines;                                      // dinamikus tömb törlése
}

int main()
{
    rightAlign("input_files/07_exam_task_input.txt");    // függvény hívása
    return 0;                                            // program vége
}
