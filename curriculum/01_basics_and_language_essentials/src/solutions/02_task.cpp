#include <iostream>

/*
Task 2

Írj programot, ami kiszámolja egy téglalap kerületét és területét!
*/

int main()
{
    float length, width;
    std::cout << "Please enter the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Please enter the width of the rectangle: ";
    std::cin >> width;

    float area = length * width;
    float perimeter = 2 * (length + width);

    std::cout << "The area of the rectangle is: " << area << std::endl;
    std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;

    return 0;
}