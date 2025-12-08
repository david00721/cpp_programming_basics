#include <iostream>
#include <cctype>

using namespace std;

const int MAXLEN = 256;

// Prototype - implement this function
int charLoad(char c_bk[]);

// Prototype - implement this function
void change(char up_bl[], int lg);

int main() {
    char buffer[MAXLEN + 1];

    int len = charLoad(buffer);
    change(buffer, len);

    return 0;
}
