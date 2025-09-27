#include <iostream>

using namespace std;

int main()
{
    // 01 -Írj programot, ami bekér egy számot, és kiírja, hogy nagyobb-e 10-nél!  
    int number;
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number > 10) {
        cout << "A szam nagyobb mint 10." << endl;
    } else {
        cout << "A szam nem nagyobb mint 10." << endl;
    }

    // 02 - Írj programot, ami bekér egy számot, és kiírja, hogy kisebb-e 100-nál!
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number < 100) {
        cout << "A szam kisebb mint 100." << endl;
    } else {
        cout << "A szam nem kisebb mint 100." << endl;
    }

    // 03 - Írj programot, ami bekér egy számot, és kiírja, hogy pozitív vagy nem!  
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number > 0) {
        cout << "A szam pozitiv." << endl;
    } else {
        cout << "A szam nem pozitiv." << endl;
    }

    // 04 - Írj programot, ami bekér egy számot, és kiírja, hogy páros vagy páratlan!
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number % 2 == 0) {
        cout << "A szam paros." << endl;
    } else {
        cout << "A szam paratlan." << endl;
    }

    // 05 - Írj programot, ami bekér egy számot, és kiírja, hogy pozitív, negatív vagy nulla!
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number > 0) {
        cout << "A szam pozitiv." << endl;
    } else if (number < 0) {
        cout << "A szam negativ." << endl;
    } else {
        cout << "A szam nulla." << endl;
    }

    // 06 - Írj programot, ami bekér egy számot, és eldönti róla, hogy osztható-e 3-mal, 5-tel vagy mindkettővel!
    cout << "Adj meg egy szamot: ";
    cin >> number;
    if (number % 3 == 0 && number % 5 == 0) {
        cout << "A szam oszthato 3-mal es 5-tel." << endl;
    } else if (number % 3 == 0) {
        cout << "A szam oszthato 3-mal." << endl;
    } else if (number % 5 == 0) {
        cout << "A szam oszthato 5-tel." << endl;
    } else {
        cout << "A szam nem oszthato sem 3-mal, sem 5-tel." << endl;
    }

    // 07 - Írj programot, ami bekér egy jegyet (A–F), és szöveges értékelést ad rá!
    char grade;
    cout << "Adj meg egy jegyet (A-F): ";
    cin >> grade;
    switch (grade) {
        case 'A':
            cout << "Kiváló" << endl;
            break;
        case 'B':
            cout << "Jó" << endl;
            break;
        case 'C':
            cout << "Közepes" << endl;
            break;
        case 'D':
            cout << "Elégséges" << endl;
            break;
        case 'E':
            cout << "Elégséges" << endl;
            break;
        case 'F':
            cout << "Elégtelen" << endl;
            break;
        default:
            cout << "Érvénytelen jegy!" << endl;
    }

    // 08 - Írj programot, ami bekér egy számot 1–7 között, és kiírja a hét megfelelő napját!
    int day;
    cout << "Adj meg egy szamot 1-7 kozott: ";
    cin >> day;
    switch (day) {
        case 1:
            cout << "Hétfő" << endl;
            break;
        case 2:
            cout << "Kedd" << endl;
            break;
        case 3:
            cout << "Szerda" << endl;
            break;
        case 4:
            cout << "Csütörtök" << endl;
            break;
        case 5:
            cout << "Péntek" << endl;
            break;
        case 6:
            cout << "Szombat" << endl;
            break;
        case 7:
            cout << "Vasárnap" << endl;
            break;
        default:
            cout << "Érvénytelen szám!" << endl;
    }

    // 09 - Írj programot, ami kiírja az 1–10 közötti számokat!
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 10 - Írj programot, ami kiírja az 1–20 közötti páros számokat!
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // 11 - Írj programot, ami kiírja egy tömb minden elemét!
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 12 - Írj programot, ami összeadja egy tömb elemeit!
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    cout << "A tomb elemeinek osszege: " << sum << endl;

    // 13 - Írj programot, ami kiírja a tömb elemeit range-based for ciklussal!
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    // 14 - Írj programot, ami megszámolja, hány páros szám van a tömbben!
    int count = 0;
    for (const auto& elem : arr) {
        if (elem % 2 == 0) {
            count++;
        }
    }
    cout << "Paros szamok szama a tombben: " << count << endl;

    // 15 - Írj programot, ami while ciklussal kiírja az 1–10 közötti számokat!
    cout << "1-10 kozotti szamok: ";
    int i = 1;
    while (i <= 10) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // 16 - Írj programot, ami while ciklussal összeadja az 1–n közötti számokat!
    int n;
    cout << "Adj meg egy szamot n: ";
    cin >> n;
    int total = 0;
    int j = 1;
    while (j <= n) {
        total += j;
        j++;
    }
    cout << "Az 1-tol " << n << "ig terjedo szamok osszege: " << total << endl;


    // 17 - Írj programot, ami do-while ciklussal legalább egyszer kiír egy üzenetet!
    string message;
    do {
        cout << "Adj meg egy uzenetet (kilepeshez irj 'exit'): ";
        cin >> message;
        if (message != "exit") {
            cout << "Az uzeneted: " << message << endl;
        }
    } while (message != "exit");

    // 18 - Írj programot, ami do-while ciklussal addig kér be számot, amíg a felhasználó nullát nem ad meg!
    int num;
    do {
        cout << "Adj meg egy szamot (kilepeshez irj 0): ";
        cin >> num;
        if (num != 0) {
            cout << "A megadott szam: " << num << endl;
        }
    } while (num != 0);

    // 19 - Írj programot, ami 1–10 között kiír minden számot, kivéve az 5-öst!
    cout << "1-10 kozotti szamok (5-os nelkul): ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;

    // 20 - Írj programot, ami 1–20 között kiírja a számokat, de ha 13-hoz ér, kilép a ciklusból!
    cout << "1-20 kozotti szamok (13-nal kilepes): ";
    for (int i = 1; i <= 20; i++) {
        if (i == 13) {
            break;
        }
        cout << i << " ";
    }
    cout << endl;

    // 21 - Írj programot, ami beágyazott ciklussal kirajzol egy 5×5-ös négyzetet `*` karakterekből!
    cout << "5x5-os negyzet '*' karakterekbol:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // 22 - Írj programot, ami beágyazott ciklussal kirajzol egy derékszögű háromszöget `*` karakterekből!
    cout << "Derekszogu haromszog '*' karakterekbol:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Gyak 01 - Írj programot, ami kiírja 1-től 100-ig az összes páros számot!
    cout << "1-100 kozotti paros szamok: ";
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Gyak 02 - Írj programot, ami kiszámolja az első n természetes szám összegét (1+2+…+n)!
    cout << "Adj meg egy szamot n: ";
    cin >> n;
    total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    cout << "Az elso " << n << " termeszetes szam osszege: " << total << endl;

    // Gyak 03 - Kérj be egy számot, és döntsd el róla, hogy prímszám-e!
    cout << "Adj meg egy szamot: ";
    cin >> number;
    bool isPrime = true;
    if (number <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << number << " egy primszam." << endl;
    } else {
        cout << number << " nem primszam." << endl;
    }

    // Gyak 04 - Írj programot, ami kirajzol egy 10×10-es négyzetet `*` karakterekből (csak a körvonalát)!
    const int n = 10;

    cout << "10x10-es negyzet '*' karakterekbol (csak a korvonal):" << endl;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (r == 0 || r == n - 1 || c == 0 || c == n - 1) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    // Gyak 05 - Írj egyszerű menüt, ami addig ismétlődik, amíg a felhasználó ki nem lép!
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Opcio 1" << endl;
        cout << "2. Opcio 2" << endl;
        cout << "3. Kilepes" << endl;
        cout << "Valassz egy opciot (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Opcio 1 valasztva." << endl;
                break;
            case 2:
                cout << "Opcio 2 valasztva." << endl;
                break;
            case 3:
                cout << "Kilepes..." << endl;
                break;
            default:
                cout << "Ervenytelen valasztas!" << endl;
        }
    } while (choice != 3);
        

    return 0;
}