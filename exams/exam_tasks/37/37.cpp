#include <iostream>
#include <string>

// Prototype - implement this function
void decode(std::string s)
{
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            int cnt = s[i] - '0';
            if (i + 1 < n) {
                for (int k = 0; k < cnt; ++k) {
                    std::cout << s[i + 1];
                }
                i++; // a számjegy utáni karaktert már feldolgoztuk
            }
        } else {
            // ha előtte nem számjegy állt
            if (i == 0 || !(s[i - 1] >= '0' && s[i - 1] <= '9')) {
                std::cout << s[i];
            }
        }
    }
}

int main()
{
    std::string s1 = "3a2bcd";
    std::string s2 = "a4x1yZ";
    std::string s3 = "5*ab";

    decode(s1);
    std::cout << std::endl;

    decode(s2);
    std::cout << std::endl;

    decode(s3);
    std::cout << std::endl;

    /*
    Expected output:
    aaabbcd
    axxxxyZ
    *****ab
    */

    return 0;
}
