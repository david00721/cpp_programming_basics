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
        int h1 = (first[0] - '0') * 10 + (first[1] - '0');
        int m1 = (first[3] - '0') * 10 + (first[4] - '0');

        // második időpont
        int h2 = (second[0] - '0') * 10 + (second[1] - '0');
        int m2 = (second[3] - '0') * 10 + (second[4] - '0');

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