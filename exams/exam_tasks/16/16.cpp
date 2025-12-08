#include <iostream>
#include <cctype>

using namespace std;

const int MAXHOSSZ = 50;

// Prototype - implement this function
int feltoltNagybetu(char szovegTb[]);

// Prototype - implement this function
void cserel(char szovegTb[], int hossz);

int main() {
    char szoveg[MAXHOSSZ + 1];

    int hossz = feltoltNagybetu(szoveg);
    cserel(szoveg, hossz);

    return 0;
}
