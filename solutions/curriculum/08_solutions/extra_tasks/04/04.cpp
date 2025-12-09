#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Saját rendezés (bubble sort)
void sajatRendezes(string* tomb, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tomb[j] > tomb[j + 1]) {
                string tmp = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = tmp;
            }
        }
    }
}

string* fullNameSort(string fbe, string fki)
{
    ifstream be(fbe);
    if (!be) {
        cout << "Sikertelen file-nyitás!";
        return nullptr;
    }

    int n;
    be >> n;
    be.ignore();  // biztosan eldobjuk a sortörést

    string* tomb = new string[n];

    for (int i = 0; i < n; i++) {
        string line;
        getline(be, line);

        // vessző helyének keresése
        size_t commaPos = line.find(',');
        string lastName = line.substr(0, commaPos);

        // maradék rész (keresztnév(ek))
        string firstNames = line.substr(commaPos + 2);

        tomb[i] = firstNames + " " + lastName;
    }
    be.close();

    sajatRendezes(tomb, n);

    ofstream ki(fki);
    if (!ki) {
        cout << "Háttértár hiba!";
        return tomb;
    }

    for (int i = 0; i < n; i++)
        ki << tomb[i] << '\n';

    ki.close();
    return tomb;
}

int main()
{
    string bemenet = "input.txt";
    string kimenet = "output.txt";

    string* rendezett = fullNameSort(bemenet, kimenet);

    if (rendezett == nullptr) {
        return 1; // hiba esetén kilépés
    }

    // Bemeneti fájlból ki kell olvasni, hány sor van → újra beolvassuk az első sort
    ifstream be(bemenet);
    int n;
    be >> n;
    be.close();

    cout << "Rendezett szerzok:" << endl;
    for (int i = 0; i < n; i++) {
        cout << rendezett[i] << endl;
    }

    delete[] rendezett;

    return 0;
}