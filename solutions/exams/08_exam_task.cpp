#include <iostream>

using namespace std;

/*
Definiálja azt a void draw(const std::string& commands) függvényt, ami egy karakterláncot fogad!
Ennek betűi parancsok arra vonatkozóan, hogy merre kell mozgatni egy tollat a képernyőn.
A karakterlánc csak az U (fel), D (le), R (jobbra) és L (balra) betűket tartalmazza.
Kezdetben a toll a képernyő bal felső sarkában áll.
Feltételezheti, hogy a toll a képernyő bal felső sarkától csak jobbra és lefelé távolodik majd el,
legfeljebb 10 karakterpozícióval. 
Minden olyan helyen, ahol a toll tartózkodik, egy csillag karakternek kell megjelennie!
*/

void draw(const std::string& commands)
{
    const int width = 11;   // vászon szélessége
    const int height = 11;  // vászon magassága
    char canvas[height][width];

    // vászon feltöltése szóközökkel
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            canvas[i][j] = ' ';

    int x = 0, y = 0;       // toll kezdőpozíciója (bal felső sarok)
    canvas[y][x] = '*';     // kezdőpont megjelölése

    // parancsok feldolgozása
    for (char command : commands) {
        switch (command) {
            case 'U': // fel
                if (y > 0) --y;
                break;
            case 'D': // le
                if (y < height - 1) ++y;
                break;
            case 'L': // balra
                if (x > 0) --x;
                break;
            case 'R': // jobbra
                if (x < width - 1) ++x;
                break;
            default:  // érvénytelen parancs → kihagyjuk
                break;
        }
        canvas[y][x] = '*'; // toll nyoma (csillag)
    }

    // vászon kirajzolása
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

int main()
{
    // teszt: egy téglalap alakzat rajzolása
    draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");
    return 0;
}
