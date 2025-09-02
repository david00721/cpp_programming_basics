#include <iostream>

/*
Task 1

Írj programot, ami bekér egy számot, és kiírja a kétszeresét!
*/

int main()
{
    int num;
    std::cout << "Please enter a number: ";
    std::cin >> num;
    std::cout << "The double of the number is: " << num * 2 << std::endl;

    return 0;
}