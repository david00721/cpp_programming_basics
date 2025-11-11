#include <iostream>

using namespace std;

int main() {
    // 01 - Feladat közösen: Írj programot, ami bekéri egy lista kívánt hosszát, majd kiírja, hogy statikusan miért nem tudná ezt lefoglalni.
    int length;
    cout << "Add meg a lista kívánt hosszát: ";
    cin >> length;

    cout << "Statikusan nem tudnánk " << length << " elemű listát lefoglalni, mert a statikus memóriafoglalás a fordítási időben történik, és a méretét nem tudjuk dinamikusan megadni." << endl;

    // 03 - Feladat közösen: Foglalj dinamikusan egy char típusú változót, olvass be bele egy betűt, majd írd ki.
    char* dynamicChar = new char;
    cout << "Add meg a betűt: ";
    cin >> *dynamicChar;
    cout << "A megadott betű: " << *dynamicChar << endl;
    delete dynamicChar;

    // 04 - Feladat önállóan: Foglalj dinamikusan egy long long tömböt n mérettel, töltsd fel négyzetszámokkal (0², 1², 2²...), majd írd ki őket.
    long long* squares = new long long[length];

    for (int i = 0; i < length; i++) {
        squares[i] = i * i;
    }

    cout << "A négyzetszámok: ";

    for (int i = 0; i < length; i++) {
        cout << squares[i] << " ";
    }
    cout << endl;

    delete[] squares;

    // 05 - Feladat közösen: Foglalj dinamikusan egy float változót, adj neki kezdőértéket foglaláskor, majd írd ki.
    float* dynamicFloat = new float(5.5);
    cout << "A dinamikusan foglalt float változó értéke: " << *dynamicFloat << endl;
    delete dynamicFloat;

    // 06 - Feladat önállóan: Foglalj dinamikusan egy bool tömböt, töltsd fel igaz/hamis értékek mintázatával (pl. igaz, hamis, igaz, hamis...), majd jelenítsd meg.
    int length2;
    cout << "Add meg a bool tömb hosszát: ";
    cin >> length2;

    bool* dynamicBoolArray = new bool[length2];
    for (int i = 0; i < length2; i++) {
        dynamicBoolArray[i] = (i % 2 == 0);
    }

    cout << "A dinamikusan foglalt bool tömb értékei: ";
    for (int i = 0; i < length2; i++) {
        cout << (dynamicBoolArray[i] ? "igaz" : "hamis") << " ";
    }
    cout << endl;

    delete[] dynamicBoolArray;

    // 07 - Feladat közösen: Hozz létre dinamikusan egy 2×3-as mátrixot, töltsd fel sorindex + oszlopindex összegével, majd jelenítsd meg.
    int rows = 2;
    int cols = 3;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    cout << "A dinamikusan foglalt mátrix értékei:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Ne felejtsd el felszabadítani a dinamikusan foglalt memóriát!
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // 08 - Feladat önállóan: Készíts dinamikusan egy 4×4-es mátrixot, töltsd fel növekvő számokkal 1-től kezdve, majd számold ki az alsó háromszög elemösszegét.
    int rows2 = 4;
    int cols2 = 4;

    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = new int[cols2];
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i * cols2 + j + 1;
        }
    }

    int lowerTriangleSum = 0;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            if (i >= j) {
                lowerTriangleSum += matrix2[i][j];
            }
            // other logic
        }
    }

    cout << "Az alsó háromszög elemösszege: " << lowerTriangleSum << endl;

    // Ne felejtsd el felszabadítani a dinamikusan foglalt memóriát!
    for (int i = 0; i < rows2; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    // 09 - Feladat közösen: Írj programot, ami bemutatja, hogy egy pointer felszabadítás után nem használható, és a nullptr beállítás megoldja a problémát.
    int* ptr = new int(42);
    cout << "A pointer értéke: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    if (ptr != nullptr) {
        cout << "A pointer értéke: " << *ptr << endl;
    } else {
        cout << "A pointer már nem mutat érvényes memóriacímre." << endl;
    }

    // 10 - Feladat önállóan: Foglalj egy double tömböt, szabadítsd fel, majd állítsd minden pointert nullptr-re, és jelezd a felhasználónak, hogy a memória felszabadult.
    double* dynamicArray = new double[5];

    // ... (tömb feltöltése, használata)

    delete[] dynamicArray;
    dynamicArray = nullptr;

    cout << "A dinamikusan foglalt tömb memóriája felszabadult." << endl;

    // 11 - Feladat közösen: Írj programot, ami memóriaszivárgást okoz!
    int* memoryLeak = new int(42);
    // A memória nem kerül felszabadításra

    // 12 - Feladat önállóan: Javítsd ki a programot delete használatával!
    delete memoryLeak;
    
    return 0;
}