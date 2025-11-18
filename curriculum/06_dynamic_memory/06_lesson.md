# 06 – Dynamic Memory (C++)

## 🎯 Célok

- Megérteni a dinamikus memóriafoglalás szükségességét.
- Használni a `new` és `delete` operátorokat.
- Dinamikus tömböket kezelni.
- Megismerni a memória-szivárgás (memory leak) problémáját.
- Gyakorolni dinamikus memória használatát függvényekben és adatszerkezetekben.

---

### 1. Miért van szükség dinamikus memóriára?

Statikus tömböknél a méret fix még fordítási időben:

```cpp
int arr[100];   // fix méret, nem változtatható futás közben
```

Ez problémás, ha a program futás közben deríti ki, mekkora tömböt akar használni.

Dinamikus memória (heap):
- futásidőben foglalsz
- annyi helyet kérsz, amennyit szeretnél
- szabadítanod is kell

👉 **01 - Feladat közösen:** Írj programot, ami bekéri egy lista kívánt hosszát, majd kiírja, hogy statikusan miért nem tudná ezt lefoglalni.

👉 **02 - Feladat közösen:**

---

### 2. `new` és `delete` operátor

**Egy változó foglalása:**
```cpp
int *p = new int;   // egy int méretű memória foglalása
*p = 42;
cout << *p;  // 42
delete p;    // memória felszabadítása
```

**Tömb foglalása:**
```cpp
int n;
cin >> n;

// Lefoglalás
int *arr = new int[n];

// ...

// Felszabadítás
delete[] arr;
```

👉 **03 - Feladat közösen:** Foglalj dinamikusan egy char típusú változót, olvass be bele egy betűt, majd írd ki.

👉 **04 - Feladat önállóan:** Foglalj dinamikusan egy long long tömböt n mérettel, töltsd fel négyzetszámokkal (0², 1², 2²...), majd írd ki őket.

---

### 3. Példák

**Példa 1 – Dinamikus változó**
```cpp
int *x = new int(10);  // értékadás foglaláskor
cout << *x;  // 10
delete x;
```

👉 **05 - Feladat közösen:** Foglalj dinamikusan egy float változót, adj neki kezdőértéket foglaláskor, majd írd ki.

👉 **06 - Feladat önállóan:** Foglalj dinamikusan egy bool tömböt, töltsd fel igaz/hamis értékek mintázatával (pl. igaz, hamis, igaz, hamis...), majd jelenítsd meg.

---

**Példa 2 – Dinamikus mátrix**

Tömb tömbje típusú foglalás:
```cpp
int rows = 3, cols = 4;

// mátrix létrehozása
int **matrix = new int*[rows];
for (int i = 0; i < rows; i++)
    matrix[i] = new int[cols];

// felszabadítás
for (int i = 0; i < rows; i++)
    delete[] matrix[i];
delete[] matrix;
```

👉 **07 - Feladat közösen:** Hozz létre dinamikusan egy 2×3-as mátrixot, töltsd fel sorindex + oszlopindex összegével, majd jelenítsd meg.

👉 **08 - Feladat önállóan:** Készíts dinamikusan egy 4×4-es mátrixot, töltsd fel növekvő számokkal 1-től kezdve, majd számold ki az alsó háromszög elemösszegét.

---

### 4. Dangling pointer

Olyan pointer, ami felszabadított memóriára mutat → veszélyes!

```cpp
int *p = new int(5);
delete p;
cout << *p;   // ❌ hibás használat
```

**Megoldás:** törlés után `nullptr`-re állítani.
```cpp
delete p;
p = nullptr;
```

👉 **09 - Feladat közösen:** Írj programot, ami bemutatja, hogy egy pointer felszabadítás után nem használható, és a nullptr beállítás megoldja a problémát.

👉 **10 - Feladat önállóan:** Foglalj egy double tömböt, szabadítsd fel, majd állítsd minden pointert nullptr-re, és jelezd a felhasználónak, hogy a memória felszabadult.

---

### 5. Memória-szivárgás (Memory leak)

Ha lefoglaljuk a memóriát, de nem szabadítjuk fel → szivárgás.

```cpp
for (int i = 0; i < 1000; i++) {
    int *p = new int(i);
    // delete p;  <-- ha kimarad, memória szivárog
}
```

👉 **11 - Feladat közösen:** Írj programot, ami memóriaszivárgást okoz!

👉 **12 - Feladat önállóan:** Javítsd ki a programot `delete` használatával!

---

### 6. Smart pointer (előzetes)

Modern C++-ban ritkán kell `new`/`delete`, helyette:

- `std::unique_ptr` – egy tulajdonos
- `std::shared_ptr` – több tulajdonos
- `std::weak_ptr` – nem számít bele az élettartamba

```cpp
#include <memory>
#include <iostream>
using namespace std;

int main() {
    unique_ptr<int> p = make_unique<int>(42);
    cout << *p << endl;
}
```
_De ez már későbbi (OOP) tananyag._

---

### 7. Gyakorló példák

**Példa 1 – Dinamikus tömb átlaga**
```cpp
int n;
cin >> n;
int *arr = new int[n];
for (int i = 0; i < n; i++) cin >> arr[i];

double sum = 0;
for (int i = 0; i < n; i++) sum += arr[i];
cout << "Average: " << sum / n;

delete[] arr;
```

👉 **13 - Feladat közösen:** Írj programot, ami dinamikus tömböt hoz létre, majd kiszámolja az átlagot!  
👉 **14 - Feladat önállóan:** Írj programot, ami dinamikus tömböt hoz létre, majd megkeresi a legnagyobb elemet!

---

**Példa 2 – Dinamikus string másolás**
```cpp
char str[] = "Hello";
int len = 0;
while (str[len] != '\0') len++;

char *copy = new char[len + 1];
for (int i = 0; i <= len; i++)
    copy[i] = str[i];

cout << copy;
delete[] copy;
```

👉 **15 - Feladat közösen:** Írj programot, ami dinamikusan lemásol egy stringet!  
👉 **16 - Feladat önállóan:** Írj programot, ami dinamikusan megfordít egy stringet!

---

### 8. Gyakorló feladatok

- Kérj be egy n számot, foglalj dinamikus tömböt, töltsd fel véletlen páros számokkal, majd számold ki az összegüket.
- Függvény: Foglaljon le rows × cols méretű mátrixot és adja vissza a legnagyobb elem helyét.
- Függvény: Fűzz össze két dinamikusan foglalt integer tömböt egy harmadikba.
- Foglalj dinamikusan egy karaktertömböt, kérj be egy szót, majd alakítsd át nagybetűssé.

---