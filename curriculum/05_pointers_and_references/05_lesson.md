# 05 – Pointers and References (C++)

## 🎯 Célok

- Megérteni, hogyan működik a memória címzése C++-ban.
- Megtanulni a pointerek (mutatók) használatát és kapcsolatát a tömbökkel.
- Megérteni a referenciák szerepét és különbségét a pointerekhez képest.
- Gyakorlati példák pointerekkel, referenciákkal és függvényparaméterekkel.

---

### 1. Memóriacím és pointer fogalma

- Minden változó egy memóriacímen tárolódik.
- `&` → egy változó címét adja vissza.
- `*` → pointeren keresztül az értéket érjük el (dereferálás).

```cpp
int x = 42;
cout << &x << endl;   // a változó címe
```

**Pointer deklaráció:**
```cpp
int x = 42;
int *ptr = &x;     // ptr az x címét tárolja
cout << ptr << endl;   // a cím
cout << *ptr << endl;  // az x értéke (42)
```

👉 **01 - Feladat közösen:** Írj programot, ami kiírja egy változó címét és értékét!  
👉 **02 - Feladat önállóan:** Írj programot, ami pointer segítségével módosítja egy változó értékét!

---

### 2. Pointer és változó kapcsolata

```cpp
int a = 10;
int *p = &a;

*p = 20;  // az 'a' értékét is módosítja
cout << a; // 20
```

👉 **03 - Feladat közösen:** Írj programot, ami pointeren keresztül ad új értéket egy változónak!  
👉 **04 - Feladat önállóan:** Írj programot, ami két változó értékét pointer segítségével cseréli meg!

---

### 3. Pointerek és tömbök

- Egy tömb neve valójában pointer az első elemre.

```cpp
int arr[3] = {10, 20, 30};
cout << arr << endl;     // cím
cout << *arr << endl;    // 10 (első elem)
cout << *(arr + 1) << endl; // 20
```

**Tömb bejárás pointerrel:**
```cpp
int arr[3] = {1, 2, 3};
int *p = arr;

for (int i = 0; i < 3; i++) {
    cout << *(p + i) << " ";
}
```

👉 **05 - Feladat közösen:** Írj programot, ami pointer segítségével kiír egy tömb minden elemét!  
👉 **06 - Feladat önállóan:** Írj programot, ami pointer segítségével kiszámolja egy tömb elemeinek összegét!

---

### 4. Pointer aritmetika

- Ha egy `int*` pointert növelünk, akkor a következő egészre mutat (nem a következő byte-ra).

```cpp
int arr[3] = {10, 20, 30};
int *p = arr;

cout << *p << endl;     // 10
p++;
cout << *p << endl;     // 20
```

👉 **07 - Feladat közösen:** Írj programot, ami pointer aritmetikával bejárja egy tömb elemeit!  
👉 **08 - Feladat önállóan:** Írj programot, ami pointer aritmetikával megkeresi a legnagyobb elemet egy tömbben!

---

### 5. Pointerek függvényekben

**Érték szerinti átadás:**
```cpp
void setValue(int x) {
    x = 100;
}
// Nem módosítja az eredeti változót.
```

**Pointer átadás:**
```cpp
void setValue(int *x) {
    *x = 100;
}

int main() {
    int a = 5;
    setValue(&a);
    cout << a;  // 100
}
```

👉 **09 - Feladat közösen:** Írj függvényt, ami pointer paraméterrel módosít egy változót!  
👉 **10 - Feladat önállóan:** Írj függvényt, ami pointer paraméterrel megszoroz egy változót 2-vel!

---

### 6. Referenciák (reference)

Referencia = alternatív név egy változóra.

```cpp
int a = 10;
int &ref = a;

ref = 20;   // a is módosul
cout << a;  // 20
```

👉 **11 - Feladat közösen:** Írj programot, ami referencia segítségével módosítja egy változó értékét!  
👉 **12 - Feladat önállóan:** Írj programot, ami referencia segítségével két szám összegét adja vissza egy függvényben!

---

### 7. Referencia paraméterek

Nagyon hasznos függvényeknél, ha az eredeti változót akarjuk módosítani.

```cpp
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 3, b = 7;
    swap(a, b);
    cout << a << " " << b; // 7 3
}
```

👉 **13 - Feladat közösen:** Írj függvényt, ami referencia segítségével kicserél két számot!  
👉 **14 - Feladat önállóan:** Írj függvényt, ami referencia segítségével megszoroz két számot!

---

### 8. Const pointer és referencia

- **const pointer:** a pointer által mutatott cím nem változtatható.
- **pointer const értékre:** az értéket nem lehet módosítani.

```cpp
const int *p1 = &a;   // értéket nem lehet módosítani
int *const p2 = &a;   // pointer nem mutathat másra
```

Referencia is lehet const:
```cpp
void print(const int &x) {
    cout << x;
}
```

👉 **15 - Feladat közösen:** Írj függvényt, ami const referenciát kap, és kiírja a paramétert!  
👉 **16 - Feladat önállóan:** Írj programot, ami const pointert használ, és kiírja egy változó értékét!

---

### 9. Null pointer

- Ha nincs érvényes cím:

```cpp
int *p = nullptr;  // modern C++
```

- Régebben: `NULL`.

👉 **17 - Feladat közösen:** Írj programot, ami null pointert inicializál, majd ellenőrzi, hogy érvényes-e!  
👉 **18 - Feladat önállóan:** Írj programot, ami csak akkor dereferál egy pointert, ha az nem null!

---

### 10. Példák

**Példa 1 – Két szám cseréje pointerrel**
```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

**Példa 2 – Tömb minimum értéke pointerrel**
```cpp
int findMin(int *arr, int n) {
    int minVal = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < minVal) minVal = *(arr + i);
    }
    return minVal;
}
```

**Példa 3 – String hossz pointerrel**
```cpp
int length(const char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
```

👉 **19 - Feladat közösen:** Írj függvényt, ami pointer segítségével visszaadja egy tömb minimumát!  
👉 **20 - Feladat önállóan:** Írj függvényt, ami pointer segítségével megszámolja egy string hosszát!

---

### 11. Gyakorló feladatok

- Írj programot, ami pointerrel kiírja egy tömb összes elemét!
- Írj függvényt, ami pointerrel kiszámolja egy tömb összegét!
- Írj programot, ami pointer segítségével két változót megcserél!
- Írj függvényt, ami referencia segítségével három szám közül a legnagyobbat visszaadja!
- Írj programot, ami pointer segítségével megfordít egy karakterláncot (pl. "hello" → "olleh")!

---

