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

---

## 2. Adattípusok

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

---

## 3. Változók és konstansok

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

---

## 4. Be- és kimenet

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

---

## 5. Operátorok

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

```cpp
int i = 5;
cout << ++i << endl; // 6
cout << i++ << endl; // 6, de i most 7
```

---

## 6. Fordítás és futtatás

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

---

## 7. Gyakorlati példák

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

## 8. Gyakorló feladatok

- Írj programot, ami bekér egy számot, és kiírja a kétszeresét!
- Írj programot, ami kiszámolja egy téglalap kerületét és területét!
- Kérj be három számot, és írd ki az átlagukat!
- Írj programot, ami bekér két egész számot, és kiírja az osztás eredményét és a maradékot!
- Írj programot, ami bekér egy karaktert, és kiírja az ASCII kódját!
