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

---

## 2. Írás fájlba

```cpp
ofstream fout("example.txt");   // megnyitás írásra
if (!fout) {
    cout << "Error opening file!";
    return 1;
}

fout << "Hello File!" << endl;
fout << 123 << endl;
fout.close();
```

- Ha a fájl nem létezik, létrejön.
- Ha létezik, alapból felülírja.

---

## 3. Olvasás fájlból

```cpp
ifstream fin("example.txt");
if (!fin) {
    cout << "Error opening file!";
    return 1;
}

string word;
while (fin >> word) {  // szavanként olvas
    cout << word << endl;
}
fin.close();
```

- `fin >> var` → szóalapú olvasás
- `getline(fin, line)` → teljes sor beolvasása

---

## 4. Hozzáfűzés (append mód)

```cpp
ofstream fout("example.txt", ios::app);
fout << "New line appended!" << endl;
fout.close();
```

- `ios::app` → mindig a fájl végére ír.

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
    fout.write((char*)&s1, sizeof(s1));
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

---

## 6. Hasznos módszerek

```cpp
fin.eof();      // true ha elérte a fájl végét
fin.fail();     // true ha olvasási hiba történt
fin.clear();    // hibajelző törlése
fin.seekg(0);   // vissza a fájl elejére
```

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

**Példa 2 – Számok összege**

```cpp
ifstream fin("numbers.txt");
int x, sum = 0;

while (fin >> x)
    sum += x;

cout << "Sum = " << sum;
```

---

## 8. Gyakorló feladatok

- Írj programot, ami beolvas egy fájlt, és kiírja a sorok számát.
- Készíts programot, ami a felhasználótól bekért számokat kiírja egy fájlba.
- Írj programot, ami egy fájlból beolvasott számok átlagát számolja ki.
- Írj programot, ami szavanként beolvassa egy szövegfájl tartalmát, és megszámolja, hány darab van.
- Készíts programot, ami bináris fájlban eltárolja és visszaolvassa egy diák adatait.