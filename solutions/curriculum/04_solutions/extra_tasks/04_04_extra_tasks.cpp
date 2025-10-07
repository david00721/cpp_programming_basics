#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;

int main() {
    char szoveg[200];
    cout << "Adj meg egy mondatot: ";
    cin.getline(szoveg, 200);

    int maganh = 0, massalh = 0;

    for (int i = 0; szoveg[i] != '\0'; i++) {
        char c = tolower(szoveg[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maganh++;
            else
                massalh++;
        }
    }

    cout << "Maganhangzok: " << maganh << endl;
    cout << "Massalhangzok: " << massalh << endl;
    return 0;
}