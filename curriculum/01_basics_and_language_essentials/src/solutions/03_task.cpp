#include <iostream>

/*
Task 3

Kérj be három számot, és írd ki az átlagukat!
*/

int main()
{
    float num1, num2, num3;
    std::cout << "Please enter the first number: ";
    std::cin >> num1;
    std::cout << "Please enter the second number: ";
    std::cin >> num2;
    std::cout << "Please enter the third number: ";
    std::cin >> num3;

    const float average = (num1 + num2 + num3) / 3;

    std::cout << "The average of the three numbers is: " << average << std::endl;

    return 0;
}