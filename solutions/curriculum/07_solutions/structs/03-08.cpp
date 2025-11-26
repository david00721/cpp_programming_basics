#include <iostream>

// 03 - Hozz létre egy Rectangle structot (width, height), és írj függvényt, ami paraméterként kap egy Rectangle-et referencia szerint, és kiszélesíti +5-tel.
struct Rectangle {
    double width;
    double height;
};

void widenRectangle(Rectangle& rect, double amount) {
    rect.width += amount;
}

// 04 - Készíts Student structot (name, age, averageGrade), majd írj függvényt, ami kiír egy diákot szép formában, pl.: `Név: Anna, Kor: 20, Átlag: 4.5`
struct Student {
    std::string name;
    int age;
    double averageGrade;
};

void printStudent(const Student& student) {
    std::cout << "Név: " << student.name << ", Kor: " << student.age << ", Átlag: " << student.averageGrade << std::endl;
}

// 07

struct Point {
        double x;
        double y;
    };

int main() {
    // 03 feladat megoldása
    Rectangle rect = {10.0, 5.0};
    std::cout << "Eredeti szélesség: " << rect.width << std::endl;
    widenRectangle(rect, 5.0);
    std::cout << "Szélesség szélesítés után: " << rect.width << std::endl;

    // 04 feladat megoldása
    Student student = {"Anna", 20, 4.5};
    printStudent(student);

    // 05 - Készíts programot, amely egy 3 elemű Student tömböt hoz létre, beolvassa a diákok nevét és életkorát, majd kiírja őket.
    const int numStudents = 3;
    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Add meg a(z) " << (i + 1) << ". diák nevét: ";
        std::cin >> students[i].name;
        std::cout << "Add meg a(z) " << (i + 1) << ". diák életkorát: ";
        std::cin >> students[i].age;
        students[i].averageGrade = 0.0; // Alapértelmezett érték
    }

    for (int i = 0; i < numStudents; ++i) {
        printStudent(students[i]);
    }

    // 06 - 

    // 07 - Írj programot, amely beolvas egy n értéket, majd dinamikusan lefoglal egy Point tömböt (`new Point[n]`), beolvassa az x,y koordinátákat, és kiírja őket.
    int n;
    std::cout << "Hány pontot szeretnél megadni? ";
    std::cin >> n;

    Point* points = new Point[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Add meg a(z) " << (i + 1) << ". pont x koordinátáját: ";
        std::cin >> points[i].x;
        std::cout << "Add meg a(z) " << (i + 1) << ". pont y koordinátáját: ";
        std::cin >> points[i].y;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << "Pont " << (i + 1) << ": (" << points[i].x << ", " << points[i].y << ")" << std::endl;
    }

    delete[] points;

    // 08 - Írj programot, amely dinamikusan foglal egy Student-ot (`Student* s = new Student;`), beolvassa az adatait, kiírja, majd felszabadítja a memóriát.
    Student* s = new Student;
    std::cout << "Add meg a diák nevét: ";
    std::cin >> s->name;
    std::cout << "Add meg a diák életkorát: ";
    std::cin >> s->age;
    std::cout << "Add meg a diák átlagát: ";
    std::cin >> s->averageGrade;

    printStudent(*s);

    delete s;

    return 0;
}