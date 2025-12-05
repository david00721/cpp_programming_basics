#include <iostream>
#include <string>
using namespace std;

// A káromkodás adatait tároló struktúra
struct curse {
    string movie;  // a film címe
    string word;   // a káromkodás szövege
    double time;   // az elhangzás ideje a filmben (pl. másodpercben)
};

// A leghamarabb elhangzó káromkodáshoz tartozó film címét adja vissza
string getFirstCurse(curse curses[], int n) {
    if (n <= 0) {
        // Ha nincs elem, visszaadhatunk üres stringet
        return "";
    }

    int minIndex = 0;               // induljunk az első elemtől
    double minTime = curses[0].time;

    for (int i = 1; i < n; ++i) {
        if (curses[i].time < minTime) {
            minTime = curses[i].time;
            minIndex = i;
        }
    }

    return curses[minIndex].movie;
}

int main() {
    curse curses[] = {
        {"Pulp Fiction", "f*ck", 123.4},
        {"Kill Bill", "damn", 45.2},
        {"Reservoir Dogs", "bastard", 78.9}
    };

    int n = sizeof(curses) / sizeof(curses[0]);

    string firstMovie = getFirstCurse(curses, n);
    cout << "A leghamarabbi káromkodás ebben a filmben hangzott el: "
         << firstMovie << endl;

    return 0;
}