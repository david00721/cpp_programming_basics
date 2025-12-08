# 08 – File Handling (C++)

## 🎯 Célok

- Megérteni, hogyan lehet fájlokat kezelni C++-ban.
- Ismerni a fájl megnyitásának, olvasásának, írásának és zárásának módját.
- Gyakorolni a különböző fájlmódokat (append, binary, stb.).
- Megtanulni a hibakezelést fájlműveleteknél.

---

## 1. Alapok – `<fstream>`

A C++ fájlkezelés a `<fstream>` könyvtárban van:

- `ifstream` → fájl olvasása (input file stream)
- `ofstream` → fájl írása (output file stream)
- `fstream` → olvasás + írás

```cpp
#include <iostream>
#include <fstream>
using namespace std;
```

👉 **01 - Feladat közösen:** Írj programot, ami megnyit egy fájlt írásra, és kiír egy sort bele!  
👉 **02 - Feladat önállóan:** Írj programot, ami megnyit egy fájlt olvasásra, és kiírja az első szót!

---

## 2. Írás fájlba

```cpp
// Nyitás és hibakezelés
ofstream fout("example.txt");   // megnyitás írásra
if (!fout) {
    cout << "Error opening file!";
    return 1;
}
```

```cpp
// Írás
fout << "Hello File!" << endl;
fout << 123 << endl;
fout.close();
```

- Ha a fájl nem létezik, létrejön.
- Ha létezik, alapból felülírja.

👉 **03 - Feladat közösen:** Írj programot, ami fájlba írja a neved és életkorod!  
👉 **04 - Feladat önállóan:** Írj programot, ami fájlba írja az első 10 négyzetszámot!

---

## 3. Olvasás fájlból

```cpp
// Nyitás és hibakezelés
ifstream fin("example.txt");
if (!fin) {
    cout << "Error opening file!";
    return 1;
}
```

```cpp
// Szavankénti olvasás
string word;
while (fin >> word) {  // szavanként olvas
    cout << word << endl;
}
fin.close();
```

```cpp
// Soronkénti olvasás
string line;
while (getline(fin, line)) { // soronként olvas
    cout << line << endl;
}
fin.close();
```

- `fin >> var` → szóalapú olvasás
- `getline(fin, line)` → teljes sor beolvasása

👉 **05 - Feladat közösen:** Írj programot, ami soronként kiírja egy fájl tartalmát!  
👉 **06 - Feladat önállóan:** Írj programot, ami megszámolja, hány szó van egy fájlban!

---

## 4. Hozzáfűzés (append mód)

```cpp
ofstream fout("example.txt", ios::app); // input-output stream :: append
fout << "New line appended!" << endl;
fout.close();
```

- `ios::app` → mindig a fájl végére ír.

👉 **07 - Feladat közösen:** Írj programot, ami hozzáfűz egy sort egy meglévő fájlhoz!  
👉 **08 - Feladat önállóan:** Írj programot, ami a felhasználótól bekért szövegeket addig írja a fájl végére, amíg az üres sort nem ad meg!

---

## 5. Bináris fájlkezelés

```cpp
struct Student {
    char name[20];
    int age;
};

int main() {
    Student s1 = {"Alice", 21};

    // Írás bináris fájlba
    ofstream fout("student.bin", ios::binary);
    fout.write((char*)&s1, sizeof(s1)); // a s1 struktúra címét char pointerré alakítjuk, hogy a write byte-sorozatként kezelje, megadjuk, hogy hány byte-ot írjon ki (a struktúra teljes mérete)
    fout.close();

    // Olvasás bináris fájlból
    Student s2;
    ifstream fin("student.bin", ios::binary);
    fin.read((char*)&s2, sizeof(s2));
    fin.close();

    cout << s2.name << " " << s2.age;
}
```

- Bináris fájlban nyers memóriát írunk és olvasunk.

👉 **09 - Feladat közösen:** Írj programot, ami bináris fájlba ment egy diák nevét és életkorát, majd visszaolvassa!  
👉 **10 - Feladat önállóan:** Írj programot, ami bináris fájlba ment több diákot (tömbben), majd visszaolvassa!

---

## 6. Hasznos módszerek

```cpp
fin.eof();      // true ha elérte a fájl végét
fin.fail();     // true ha olvasási hiba történt
fin.clear();    // hibajelző törlése
fin.seekg(0);   // vissza a fájl elejére
```

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("example.txt");

    char c;
    while (fin.get(c)) {
        cout << c;
    }

    if (fin.eof()) {
        cout << "\nElértük a fájl végét.\n";
    }
}
```

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("numbers.txt");

    int x;
    fin >> x;   // Tegyük fel, hogy a fájlban egy betű van → olvasási hiba

    if (fin.fail()) {
        cout << "Hibás olvasás történt!\n";
    }
}
```

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("example.txt");

    string word;
    while (fin >> word) { }  // Olvasás a végéig → EOF

    if (fin.eof()) {
        cout << "Vége a fájlnak.\n";
    }

    fin.clear();  // hibabitek törlése → újra használható a stream
    cout << "clear() után az EOF állapot: " << fin.eof() << endl;
}
```

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("example.txt");

    string word;
    fin >> word;   // első szó
    cout << "Elso olvasas: " << word << endl;

    fin.clear();   // kell az EOF/reset miatt
    fin.seekg(0);  // vissza a fájl elejére

    fin >> word;   // újra az első szó
    cout << "Második olvasás: " << word << endl;
}
```

👉 **11 - Feladat közösen:** Írj programot, ami beolvassa egy fájl első sorát, majd seekg segítségével újraolvassa!  
👉 **12 - Feladat önállóan:** Írj programot, ami hibakezelést végez: ha nem létezik a fájl, jelezze a felhasználónak!

---

## 7. Példák

**Példa 1 – Sorok számlálása**

```cpp
ifstream fin("example.txt");
string line;
int count = 0;

while (getline(fin, line))
    count++;

cout << "Lines: " << count;
```

👉 **13 - Feladat közösen:** Írj programot, ami megszámolja egy fájl sorait!  
👉 **14 - Feladat önállóan:** Írj programot, ami megszámolja egy fájl karaktereit!

---

**Példa 2 – Számok összege**

```cpp
ifstream fin("numbers.txt");
int x, sum = 0;

while (fin >> x)
    sum += x;

cout << "Sum = " << sum;
```

👉 **15 - Feladat közösen:** Írj programot, ami kiírja egy fájlban lévő számok összegét!  
👉 **16 - Feladat önállóan:** Írj programot, ami kiszámolja egy fájlban lévő számok átlagát!

---

## 8. Gyakorló feladatok

- Írj programot, ami beolvas egy fájlt, és kiírja a sorok számát.
- Készíts programot, ami a felhasználótól bekért számokat kiírja egy fájlba.
- Írj programot, ami egy fájlból beolvasott számok átlagát számolja ki.
- Írj programot, ami szavanként beolvassa egy szövegfájl tartalmát, és megszámolja, hány darab van.
- Készíts programot, ami bináris fájlban eltárolja és visszaolvassa egy diák adatait.

---

