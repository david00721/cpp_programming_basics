#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void duration(string fileName)
{
    ifstream file(fileName);

    string line;
    // fejléc átugrása
    getline(file, line);

    // további sorok feldolgozása
    while (getline(file, line)) {
        // sor formátuma: "HH:MM,HH:MM"

        // vessző helye
        size_t commaPos = line.find(',');

        string first  = line.substr(0, commaPos);
        string second = line.substr(commaPos + 1);

        // első időpont
        int h1 = stoi(first.substr(0, 2));
        int m1 = stoi(first.substr(3, 2));

        // második időpont
        int h2 = stoi(second.substr(0, 2));
        int m2 = stoi(second.substr(3, 2));

        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;

        cout << (t2 - t1) << endl;
    }
}

int main()
{
    string file = "ido1.csv";

    duration(file);

    return 0;
}