# 01 – Basics and Language Essentials (C++)

## 🎯 Célok

- Megérteni, hogyan épül fel egy C++ program.
- Megtanulni a legfontosabb adattípusokat és változók kezelését.
- Elsajátítani az alapvető operátorokat és kifejezéseket.
- Első saját programok megírása és fordítása.

---

## 1. A C++ program szerkezete

Minden C++ program belépési pontja a `main()` függvény.  
Egy legegyszerűbb program így néz ki:

```cpp
#include <iostream>   // be/kimenet kezeléséhez
using namespace std;  // egyszerűbb írásmódhoz

int main()
{
    cout << "Hello, World!" << endl;
    return 0;  // 0 visszatérés: sikeres futás
}
```

**Fontos elemek:**

- `#include <iostream>` – előfeldolgozó utasítás, ami betölti az input/output könyvtárat.
- `using namespace std;` – lehetővé teszi, hogy `cout`-ot írjunk `std::cout` helyett.
- `int main()` – a program kezdete. Mindig visszatér egy egész értékkel.
- `cout <<` – kiírás a képernyőre.
- `endl` – sortörés és buffer ürítés.
- `return 0;` – a program sikeres futását jelzi az operációs rendszernek.

👉 **01 - Feladat közösen:** Írj programot, ami kiírja a neved és az életkorod!  
👉 **02 - Feladat önállóan:** Írj programot, ami két sort ír ki: az elsőben a kedvenc focicsapatod, a másodikban a kedvenc filmedet!

---

## 2. Megjegyzések

A kódba megjegyzéseket lehet írni, amelyek nem befolyásolják a program futását.

```cpp
// Ez egy egysoros megjegyzés
/* Ez pedig
   több soros megjegyzés */
```

---

## 3. Adattípusok

A C++ erősen típusos nyelv – minden változónak típusa van.

| Típus   | Méret (átlag) | Példa értékek           |
|---------|---------------|-------------------------|
| int     | 4 byte        | -10, 0, 42              |
| float   | 4 byte        | 3.14, -0.5              |
| double  | 8 byte        | 3.14159265358979        |
| char    | 1 byte        | 'a', 'Z', '7'           |
| bool    | 1 byte        | true, false             |
| string  | változó méret | "Hello" (`std::string`) |

**Példa változókra:**

```cpp
int age = 21;
double pi = 3.14159;
char grade = 'A';
bool is_student = true;
string name = "Alice";
```

👉 **03 - Feladat közösen:** Írj programot, amelyben tárolod a saját neved, életkorod és azt, hogy tanuló vagy-e, majd írd ki őket!  
👉 **04 - Feladat önállóan:** Írj programot, amelyben eltárolod egy könyv címét, szerzőjét és oldalszámát, majd jelenítsd meg!

---

## 4. Változók és konstansok

**Változó:**  
Egy „doboz” a memóriában, ami egy értéket tárol.

```cpp
int x = 10;
x = x + 5; // most x = 15
```

**Konstans:**  
Értéke nem változhat a program futása közben.

```cpp
const double PI = 3.14159;
```

Régebbi módszer (inkább C-ből maradt):

```cpp
#define MAX 100
```

👉 **05 - Feladat közösen:** Írj programot, ami eltárolja egy kör sugarát, majd kiírja a kör kerületét a konstans `PI` felhasználásával!  
👉 **06 - Feladat önállóan:** Írj programot, ami kiszámítja egy négyzet területét, és a számításnál konstansként használd az oldalhosszt!

---

## 5. `auto` típus

A fordító képes kitalálni a típust:

```cpp
auto x = 42;    // int
auto y = 3.14;  // double
```

👉 **07 - Feladat közösen:** Írj programot, amelyben `auto`-val létrehozol három különböző típusú változót, majd kiírod őket!  
👉 **08 - Feladat önállóan:** Írj programot, amely két `auto` típusú változót összead, és kiírja az eredményt!

---

## 6. Típuskonverzió (casting)

Példa:

```cpp
int a = 5, b = 2;
double result = (double)a / b; // 2.5
double result2 = static_cast<double>(a) / b; // 2.5
```

👉 **09 - Feladat közösen:** Írj programot, ami bekér két egész számot, majd lebegőpontos osztással kiszámítja a hányadosukat!  
👉 **10 - Feladat önállóan:** Írj programot, ami Celsius fokot Fahrenheitre vált át, lebegőpontos számítással!

---

## 7. Be- és kimenet

**Kimenet:**

```cpp
cout << "Age: " << age << endl;
```

**Bemenet:**

```cpp
int number;
cout << "Enter a number: ";
cin >> number;
cout << "You entered: " << number << endl;
```

👉 **11 - Feladat közösen:** Írj programot, ami bekéri a neved és az életkorod, majd kiírja egy mondatban!  
👉 **12 - Feladat önállóan:** Írj programot, ami bekér egy számot, majd kiírja a négyzetét!

---

## 8. Operátorok

**Aritmetikai:**  
`+`, `-`, `*`, `/`, `%`

```cpp
int a = 10, b = 3;
cout << a / b << endl;   // 3 (egész osztás)
cout << a % b << endl;   // 1 (maradék)
```

**Értékadó:**  
`=`, `+=`, `-=`, `*=`, `/=`, `%=`  

```cpp
int x = 5;
x += 3;  // x = 8
```

**Relációs:**  
`==`, `!=`, `<`, `<=`, `>`, `>=`

```cpp
cout << (5 < 10) << endl; // true → 1
```

**Logikai:**  
`&&` (és), `||` (vagy), `!` (nem)

```cpp
bool a = true, b = false;
cout << (a && b) << endl; // 0
```

**Növelés/Csökkentés:**  
`++i` (pre-increment), `i++` (post-increment)

| Művelet         | Leírás                                      | Példa                |
|-----------------|---------------------------------------------|----------------------|
| **Pre-increment**<br>(`++i`)  | Először növeli az értéket, majd visszaadja az újat.<br>Hatékonyabb, mert nem hoz létre ideiglenes objektumot. | `int i = 5; ++i; // i = 6` |
| **Post-increment**<br>(`i++`) | Először visszaadja a régi értéket, majd növeli az értéket.<br>Létrehoz egy ideiglenes másolatot a régi értékről. | `int i = 5; i++; // i = 6` |


```cpp
int i = 5;
cout << ++i << endl; // 6
cout << i++ << endl; // 6, de i most 7
```

👉 **13 - Feladat közösen:** Írj programot, ami bekér két számot, és kiírja a különbséget, szorzatot és hányadost!  
👉 **14 - Feladat önállóan:** Írj programot, ami bekér egy számot, és kiírja a szám maradékát, ha elosztod 3-mal!

---

## 9. Fordítás és futtatás

**Parancssorból (Linux/Mac/WSL):**

```sh
g++ program.cpp -o program
./program
```

**Windows (MinGW esetén):**

```sh
g++ program.cpp -o program.exe
program.exe
```

**IDE-ben** (pl. Visual Studio, CLion, Code::Blocks):  
Elég a „Run” gomb.

👉 **15 - Feladat közösen:** Fordítsd le és futtasd az egyik eddigi programodat parancssorból!  
👉 **16 - Feladat önállóan:** Fordíts le és futtass egy másik programot IDE-ben!

---

## 10. Gyakorlati példák

**Példa 1 – két szám összeadása**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum = " << a + b << endl;
    return 0;
}
```

**Példa 2 – kör területe**

```cpp
#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area = " << PI * r * r << endl;
    return 0;
}
```

---

## 11. Gyakorló feladatok

- Írj programot, ami bekér egy számot, és kiírja a kétszeresét!
- Írj programot, ami kiszámolja egy téglalap kerületét és területét!
- Kérj be három számot, és írd ki az átlagukat!
- Írj programot, ami bekér két egész számot, és kiírja az osztás eredményét és a maradékot!
- Írj programot, ami bekér egy karaktert, és kiírja az ASCII kódját!
