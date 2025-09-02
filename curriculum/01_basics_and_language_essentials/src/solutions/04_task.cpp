#include <iostream>

using namespace std;

/*
Task 4

Írj programot, ami bekér két egész számot, és kiírja az osztás eredményét és a maradékot!
*/

int main()
{
    int num1, num2;
    std::cout << "Please enter the first integer: ";
    std::cin >> num1;
    std::cout << "Please enter the second integer: ";
    std::cin >> num2;

    if (num2 != 0) {
        std::cout << "The result of the division: " << num1 / num2 << std::endl;
        std::cout << "The remainder: " << num1 % num2 << std::endl;
    } else {
        std::cout << "Division by zero is not allowed!" << std::endl;
    }

    return 0;
}