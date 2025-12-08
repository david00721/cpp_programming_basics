#include <iostream>
#include <cctype>

using namespace std;

const int MAXLEN = 128;

// Prototype - implement this function
int loadText(char t_bk[]);

// Prototype - implement this function
void upperNumber(char un_bl[], int lm);

int main() {
    char text[MAXLEN + 1];

    int len = loadText(text);
    upperNumber(text, len);

    // abCDeFgh → ab01e2gh

    return 0;
}
