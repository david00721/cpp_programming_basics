#include <iostream>
#include <cctype>

using namespace std;

const int MAXLEN = 256;

// Prototype - implement this function
int charLoad(char c_bk[])
{
    int len = 0;
    char ch;

    while (len < MAXLEN) {
        ch = std::cin.get();
        if (ch == '\n') break;
        c_bk[len++] = ch;
    }
    return len;
}

// Prototype - implement this function
void change(char up_bl[], int lg)
{
    int originalUpper = 0;

    for (int i = 0; i < lg; ++i) {
        if (up_bl[i] >= 'A' && up_bl[i] <= 'Z') {
            originalUpper++;
        } else if (up_bl[i] >= 'a' && up_bl[i] <= 'z') {
            up_bl[i] = up_bl[i] - 'a' + 'A';
        }
    }

    for (int i = 0; i < lg; ++i) {
        std::cout << up_bl[i];
    }
    std::cout << std::endl;

    std::cout << "Original uppercase count: " << originalUpper << std::endl;
}

int main() {
    char buffer[MAXLEN + 1];

    int len = charLoad(buffer);
    change(buffer, len);

    /*
    AbCdEfGh
    ABCDEFGH
    Original uppercase count: 4
    */

    return 0;
}
