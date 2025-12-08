#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void isFart(string dataset)
{
    ifstream file(dataset);
    if (!file) {
        // A feladat nem írt elő hibaüzenetet, de valamit muszáj kezelnünk
        return;
    }

    string line;
    bool firstPrinted = true;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        size_t sep = line.find(';');

        string name = line.substr(0, sep);
        string status = line.substr(sep + 1);

        if (status == "Yes" || status == "Hell Yes") {
            if (!firstPrinted) {
                cout << ';';
            }
            cout << name;
            firstPrinted = false;
        }
    }
}

int main()
{
    string filename = "animals.csv";
    isFart(filename);
    return 0;
}