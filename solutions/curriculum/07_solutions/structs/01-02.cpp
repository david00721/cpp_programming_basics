#include <iostream>

// 01 - Hozz létre egy Rectangle structot, amelynek mezői: width (szélesség), height (magasság). Hozz létre egy példányt, adj neki értékeket, és írd ki a területét!
struct Rectangle {
    double width;
    double height;
};

// 02 - Hozz létre egy Student structot, mezőkkel: name (string), age (int). Hozz létre két diákot, töltsd fel adatokkal, és írd ki őket a képernyőre!
struct Student {
    std::string name;
    int age;
};

int main() {
    // 01 feladat megoldása
    Rectangle rect;
    rect.width = 5.0;
    rect.height = 3.0;

    double area = rect.width * rect.height;
    std::cout << "A téglalap területe: " << area << std::endl;

    // 02 feladat megoldása
    Student student1 = {"János", 20};
    Student student2 = {"Anna", 22};

    std::cout << "Diák 1: " << student1.name << ", életkor: " << student1.age << std::endl;
    std::cout << "Diák 2: " << student2.name << ", életkor: " << student2.age << std::endl;

    return 0;
}