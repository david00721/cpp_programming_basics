#include <iostream>

/*
Task 5

Írj programot, ami bekér egy karaktert, és kiírja az ASCII kódját!
*/

int main()
{
    char ch;
    std::cout << "Please enter a character: ";
    std::cin >> ch;
    std::cout << "Its ASCII code is: " << static_cast<int>(ch) << std::endl;

    return 0;
}