# Cheatsheet

## Dinamikus 2D Mátrix Kezelése Egész Számokkal

### Lefoglalás

Egész számokat tartalmazó 2D mátrix dinamikus lefoglalása, soronként külön memóriaterületen.

```cpp
int **mtx = new int*[no]; // 'no' a sorok száma
for (int i = 0; i < no; ++i) {
    mtx[i] = new int[mo]; // 'mo' az oszlopok száma
}
```

### Felszabadítás

A dinamikusan lefoglalt 2D mátrix felszabadítása soronként, majd a fő mutató törlése.

```cpp
for (int i = 0; i < no; ++i) {
    delete[] mtx[i];
}
delete[] mtx;
```

## Láncolt Listák Műveletei

### Létrehozás

Egyszerű láncolt lista csomópontjának definíciója adatokkal és a következő elem mutatójával.

```cpp
struct Node {
    int data;
    Node* next;
};
```

### Beszúrás

Beszúrás a láncolt lista elejére egy új csomópont létrehozásával.

```cpp
Node* insertFront(Node* head, int value) {
    Node* newNode = new Node{value, head};
    return newNode;
}
```

Beszúrás a láncolt lista végére a lista végigjárásával.

```cpp
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
```

### Törlés

A lista összes csomópontját felszabadítja, majd a head nullára áll.

```cpp
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

## Rendezési Algoritmusok

### Swap segédfüggvény

Két egész szám értékének felcserélése.

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### Buborékrendezés

Elemek ismételt összehasonlítása és felcserélése egymás után.

További információ: [Bubble Sort Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/)

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Kiválasztásos rendezés

Minden lépésben a legkisebb elem megkeresése és cseréje.

További információ: [Selection Sort Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

### Beszúrásos rendezés

Az aktuális elem megfelelő helyre illesztése a rendezett részben.

További információ: [Insertion Sort Algorithm – GeeksforGeeks](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
```

## Fájlbeolvasás és fájlbaírás

### Fájl beolvasása soronként

Egy szövegfájl sorainak beolvasása és feldolgozása.

```cpp
#include <fstream>
#include <string>

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        // Sor feldolgozása
    }
    file.close();
}
```

### Fájlba írás soronként

Szövegfájl létrehozása és adatok soronkénti kiírása.

```cpp
#include <fstream>
#include <string>

void writeFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "Első sor\n";
    file << "Második sor\n";
    file.close();
}
```

## Egész véletlen szám generálása adott tartományban

A rand() függvény használata [min, max] tartományban.

```cpp
#include <cstdlib>
#include <ctime>

// Inicializálás egyszer a program elején
srand(static_cast<unsigned>(time(0)));

// Véletlen szám generálása [min, max] tartományban
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}
```

## Minimum és maximum keresése tömbben

A tömb legkisebb és legnagyobb elemének meghatározása.

```cpp
void findMinMax(const int arr[], int n, int& minVal, int& maxVal) {
    if (n <= 0) return;
    minVal = maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}
```

## Számjegyek megszámlálása

Egy szám számjegyeinek megszámolása
```cpp
int numberOfDigits(int x){
    if (x == 0) return 1;
    int digits = 0;
    while (x > 0){
        x /= 10;
        digits++;
    }
    return digits;
}
```

## String műveletek

### String megfordítása

Egy C-string karaktereinek felcserélése elejétől a végéig.

```cpp
#include <cstring>

void reverseString(char str[]) {
    int n = std::strlen(str);
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
```

### String karaktereinek összekeverése (shuffle)

A std::shuffle függvénnyel véletlenszerű sorrendbe rendezés.

```cpp
#include <algorithm>
#include <random>
#include <string>

void shuffleString(std::string& str) {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(str.begin(), str.end(), g);
}
```

### Szóközök számolása szövegben

Megszámolja a szóköz karaktereket.

```cpp
int countSpaces(const std::string& str) {
    int cnt = 0;
    for (char c : str) if (c == ' ') ++cnt;
    return cnt;
}
```

### Palindróm ellenőrzése

Megvizsgálja, hogy a szöveg ugyanaz-e előről és hátulról.

```cpp
bool isPalindrome(const std::string& str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j]) return false;
        ++i; --j;
    }
    return true;
}
```

## Strukturák használata

### Struktúra deklarálása és példányosítása

Adatok összefogása egy struktúrában, példány létrehozása.

```cpp
struct Szemely {
    std::string nev;
    int eletkor;
    double fizetes;
};

Szemely peldany;
peldany.nev = "Kiss Anna";
peldany.eletkor = 25;
peldany.fizetes = 350000.0;
```

### Struktúra tömb deklarálása

Több struktúra példány tárolása tömbben.

```cpp
Szemely dolgozok[10];
```

### Struktúra tömb feltöltése

A tömb minden elemének inicializálása.

```cpp
for (int i = 0; i < 10; ++i) {
    dolgozok[i].nev = "Dolgozó " + std::to_string(i + 1);
    dolgozok[i].eletkor = 20 + i;
    dolgozok[i].fizetes = 300000 + i * 10000;
}
```

### Struktúra pointer használata

Mutató segítségével hozzáférés a struktúra mezőihez.

```cpp
Szemely* ptr = &peldany;
ptr->eletkor = 30;
```

## Keresések tömbben

### Lineáris keresés

Végigmegy a tömbön, és visszaadja a keresett elem indexét, vagy -1-et.

```cpp
int linearSearch(const int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}
```

### Bináris keresés (rendezett tömbben)

A keresési tartományt mindig felezve hatékonyabb keresés.

```cpp
int binarySearch(const int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

## String leggyakoribb függvények

### `s.size()` / `s.length()`

**Visszaadja a string hosszát.**

``` cpp
#include <iostream>
#include <string>
int main() {
    std::string s = "Hello";
    std::cout << s.size();
}
```

Kimenet:

    5

### `s.empty()`

**Megmondja, hogy üres-e a string.**

``` cpp
std::string s = "";
std::cout << s.empty();
```

Kimenet:

    1

### `s.at(index)`

**Biztonságos indexelés bounds-checkkel.**

``` cpp
std::string s = "Hello";
std::cout << s.at(1);
```

Kimenet:

    e

### `s.append(str)` vagy `s += str`

**Hozzáfűz egy másik stringet.**

``` cpp
std::string s = "Hello";
s.append(" World");
std::cout << s;
```

Kimenet:

    Hello World

### `s.insert(pos, str)`

**String beszúrása adott pozícióban.**

``` cpp
std::string s = "Helo";
s.insert(2, "l");
std::cout << s;
```

Kimenet:

    Hello

### `s.erase(pos, count)`

**Töröl `count` karaktert a `pos` pozíciótól.**

``` cpp
std::string s = "Hello!!!";
s.erase(5, 3);
std::cout << s;
```

Kimenet:

    Hello

### `s.replace(pos, count, str)`

**Kicserél egy részstringet egy másikra.**

``` cpp
std::string s = "H3llo";
s.replace(1, 1, "e");
std::cout << s;
```

Kimenet:

    Hello

### `s.find(str)`

**Megadja az első előfordulás indexét, vagy `npos`.**

``` cpp
std::string s = "Hello World";
std::cout << s.find("World");
```

Kimenet:

    6

### `s.rfind(str)`

**Megadja az utolsó előfordulás indexét.**

``` cpp
std::string s = "test_test";
std::cout << s.rfind("test");
```

Kimenet:

    5

### `s.substr(pos, count)`

**Kivág egy részstringet.**

``` cpp
std::string s = "Hello World";
std::cout << s.substr(6, 5);
```

Kimenet:

    World

### `std::stoi(s)`

**String → int konverzió.**

``` cpp
std::string s = "123";
std::cout << std::stoi(s) + 1;
```

Kimenet:

    124

### `std::to_string(num)`

**Szám → string konverzió.**

``` cpp
int x = 42;
std::cout << std::to_string(x);
```

Kimenet:

    42

### `std::getline(cin, s)`

**Egész sort beolvas szóközökkel együtt.**

``` cpp
// input: Hello World
std::string s;
std::getline(std::cin, s);
std::cout << s;
```

Kimenet:

    Hello World

### `s.compare(str)`

**Lexikografikus összehasonlítás (-, 0, +).**

``` cpp
std::string a = "apple";
std::string b = "banana";
std::cout << a.compare(b);  // <0
```

Kimenet:

    -1

### `s.push_back(c)` / `s.pop_back()`

**Egy karakter hozzáadása vagy eltávolítása a végéről.**

``` cpp
std::string s = "Hell";
s.push_back('o');
std::cout << s;
```

Kimenet:

    Hello

### Iterálás stringen (`for` loop)

**Karakterenkénti bejárás.**

``` cpp
std::string s = "Hi";
for(char c : s) std::cout << c << "-";
```

Kimenet:

    H-i-
