# 08 -- File Handling (C++) -- Részletes jegyzet példákkal

## 1. Alapok -- `<fstream>`

A C++ fájlkezeléshez az alábbi fejlécre van szükség:

``` cpp
#include <fstream>
#include <iostream>
using namespace std;
```

Három fő típust használunk:

-   `ifstream` -- fájl olvasásához\
-   `ofstream` -- fájl írásához\
-   `fstream` -- olvasáshoz és íráshoz is

### Példa: fájl megnyitása és ellenőrzése

``` cpp
ifstream fin("input.txt");
if (!fin) { // vagy !fin.is_open()
    cout << "Failed to open file!\n";
    return 1;
}
```

------------------------------------------------------------------------

## 2. Írás fájlba

``` cpp
ofstream fout("example.txt");
if (!fout) { // vagy !fout.is_open())
    cout << "Cannot open file!\n";
    return 1;
}

fout << "Hello File!" << endl;
fout << 42 << endl;
fout.close();
```

### Fontos:

-   Ha a fájl létezik → **felülíródik**.
-   Ha nem létezik → létrejön.

------------------------------------------------------------------------

## 3. Olvasás fájlból

### Szavankénti olvasás

``` cpp
string word;
while (fin >> word) {
    cout << word << endl;
}
```

### Soronkénti olvasás

``` cpp
string line;
while (getline(fin, line)) {
    cout << line << endl;
}
```

------------------------------------------------------------------------

## 3.1 `>>` és `getline()` keverésének problémája

A `>>` **bent hagyja a sortörést**, ezért a következő `getline()` üres
sort olvas.

### Rossz:

``` cpp
int x;
fin >> x;
getline(fin, line); // üres sort kap
```

### Megoldás:

``` cpp
fin.ignore(); // egy whitespace-t dob el
getline(fin, line); // már jó
```

Vagy minden beolvasás `getline()`-nel:

``` cpp
string s;
getline(fin, s);
int x = stoi(s);
```

## 3.2 String konverzió

A C++ a `<string>` könyvtárban több beépített függvényt biztosít,
amelyekkel szövegből számot lehet konvertálni. Ezek különösen akkor
hasznosak, amikor `getline()` segítségével olvasunk be adatot, és utána
szükség van számokká alakításra.

### Egész szám típusok

```text
`int`       ->  `stoi()`
`long`      ->  `stol()`
`long long` ->  `stoll()`
```

**Példa:**

``` cpp
string s = "123";
int a = stoi(s);              // 123
long b = stol("456");         // 456
long long c = stoll("789");   // 789
```
## 3.3 Stringstream használata

A stringstream olyan, mint a *cin*, csak nem a felhasználótól, hanem
stringből olvas.

``` cpp
#include <sstream>

stringstream ss("12 3.14 test");
int a; double b; string s;
ss >> a >> b >> s;
```

### CSV példa stringstreammel

Bemenet:

    John,25,180

``` cpp
getline(fin, line);

for (char& c : line)
    if (c == ',') c = ' ';

/*
for (size_t i = 0; i < line.size(); i++) {
    if (line[i] == ',') {
        line[i] = ' ';
    }
}
*/

stringstream ss(line);

string name;
int age, height;
ss >> name >> age >> height;
```

------------------------------------------------------------------------

### Lebegőpontos típusok

```text
`float`       ->  `stof()`
`double`      ->  `stod()`
`long double` ->  `stold()`
```

**Példa:**

``` cpp
double d = stod("3.1415");          // 3.1415
float f = stof("2.71");             // 2.71f
long double ld = stold("1.234");    // 1.234L
```

### Tipikus használat getline() után

``` cpp
string line;
getline(fin, line);
int value = stoi(line);   // sorból számot készít
```

------------------------------------------------------------------------

## 4. Fájlmódok (flags)

``` cpp
ofstream fout("data.txt", ios::app | ios::out);
```

  Flag            Jelentés
  --------------- ------------------------------------
  `ios::in`       olvasás
  `ios::out`      írás
  `ios::app`      hozzáfűzés
  `ios::trunc`    tartalom törlése
  `ios::binary`   bináris mód
  `ios::ate`      a fájl végére ugrik megnyitás után

------------------------------------------------------------------------

## 5. Hozzáfűzés

``` cpp
ofstream fout("log.txt", ios::app);
fout << "Log entry" << endl;
```

------------------------------------------------------------------------

## 6. Bináris fájlkezelés

``` cpp
struct Student {
    char name[20];
    int age;
};

Student s1 = {"Alice", 21};

ofstream fout("student.bin", ios::binary);
fout.write((char*)&s1, sizeof(s1));
// fout.write(reinterpret_cast<const char*>(&s1), sizeof(s1));
fout.close();
```

### Olvasás:

``` cpp
Student s2;

ifstream fin("student.bin", ios::binary);
fin.read((char*)&s2, sizeof(s2));
// fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));

cout << s2.name << " " << s2.age;
```

------------------------------------------------------------------------

## 7. Stream állapotok

``` cpp
fin.good(); // nincs hiba
fin.eof();  // elértük-e a fájl végét
fin.fail(); // hiba olvasásnál
fin.bad();  // súlyos IO hiba
fin.clear(); // hibabitek törlése
```

### Példa hibakezelésre:

``` cpp
int x;
fin >> x;

if (fin.fail()) {
    cout << "Invalid number!\n";
}
```

------------------------------------------------------------------------

## 8. Fájlpozíció -- seekg, seekp

``` cpp
fin.seekg(0); // elejére ugrás
fin.seekg(0, ios::end); // végére ugrás
```

### Példa újraolvasásra:

``` cpp
fin.clear();
fin.seekg(0);
getline(fin, line);
```

------------------------------------------------------------------------

## 9. FONTOS

-   `getline()` üres sort olvas `>>` után → `ignore()` kell\
-   fájlt nem ellenőriztünk megnyitás után\
-   `seekg()` előtt mindig `clear()`\
-   soha ne használj `while (!fin.eof())` beolvasásra

------------------------------------------------------------------------

## 10. Gyors összefoglaló

-   `>>` → szavanként olvas\
-   `getline()` → sort olvas\
-   `>>` után mindig `ignore()` ha `getline()` jön\
-   bináris írás: `write()`, olvasás: `read()`\
-   mindig ellenőrizd a streamet (`if (!fin)`)\
-   `while (fin >> val)` a helyes beolvasási minta

------------------------------------------------------------------------
