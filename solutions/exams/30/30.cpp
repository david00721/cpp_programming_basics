#include <iostream>
#include <fstream>
#include <string>

using namespace std;

std::string toFullName(const std::string& s)
{
    int commaPos = -1;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == ',') {
            commaPos = i;
            break;
        }
    }
    if (commaPos < 0) return s;

    std::string last = s.substr(0, commaPos);
    std::string first = s.substr(commaPos + 2); // ", " után
    return first + " " + last;
}

// Prototype - implement this function
std::string* fullNameSort(std::string fbe, std::string fki)
{
    std::ifstream fin(fbe);
    if (!fin.is_open()) {
        std::cout << "Sikertelen file-nyitás!" << std::endl;
        return 0;
    }

    int n = 0;
    fin >> n;
    fin.ignore();

    if (n <= 0) {
        fin.close();
        return 0;
    }

    std::string* names = new std::string[n];

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(fin, line);
        
        names[i] = toFullName(line);
    }
    fin.close();

    // ABC rendezés teljes név szerint
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (names[j] < names[i]) {
                std::string tmp = names[i];
                names[i] = names[j];
                names[j] = tmp;
            }
        }
    }

    std::ofstream fout(fki.c_str());
    if (!fout.is_open()) {
        std::cout << "Háttértár hiba!" << std::endl;
        delete[] names;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        fout << names[i] << std::endl;
    }
    fout.close();

    return names;
}

int main() {
    string* sorted = fullNameSort("authors_in.txt", "authors_out.txt");

    if (sorted) {
        // A bemeneti file első sorában lévő n értéket neked kell majd beolvasnod a függvényben.
        // Itt példaként feltételezzük, hogy 8 elem volt.
        int n = 8;

        cout << "RENDEZETT NEVEK:" << endl;
        for (int i = 0; i < n; i++) {
            cout << sorted[i] << endl;
        }

        delete[] sorted;
    }

    return 0;
}
