#include <iostream>
#include <string>

// Prototype - implement this function
void decode(std::string s);

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
