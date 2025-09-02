# 04 – Arrays and Character Arrays (C++)

## 🎯 Célok

- Megérteni a tömbök (arrays) működését és használatát.
- Megtanulni, hogyan kell kezelni egydimenziós és kétdimenziós tömböket.
- Megérteni a C-stringek (char[]) működését.
- Gyakorlati példákon keresztül gyakorolni a keresést, rendezést és szövegfeldolgozást.

---

## 1. Tömbök alapjai

Egy tömb azonos típusú elemek sorozata, amelyet indexeléssel érünk el.

**Létrehozás:**
```cpp
int numbers[5];              // 5 elemű egész tömb
int values[3] = {10, 20, 30}; // inicializálás
int data[] = {1, 2, 3, 4};    // méret automatikusan 4
```

**Indexelés:**
- Az első elem indexe mindig 0.
- Utolsó elem indexe: méret-1.

```cpp
cout << values[0]; // 10
values[2] = 99;    // harmadik elem átírása
```

> ⚠️ Ha túlindexelsz (pl. `values[5]`), az hibás működéshez vezethet.

---

## 2. Tömb bejárása ciklussal

```cpp
int arr[5] = {3, 7, 2, 8, 5};

for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

---

## 3. Tömb átadása függvénynek

Egy tömböt referenciaként kap meg a függvény, nem készül másolat.

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int nums[3] = {1, 2, 3};
    printArray(nums, 3);
}
```

---

## 4. Egydimenziós tömb műveletek

**Keresés (lineáris keresés):**
```cpp
int find(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1; // nem találta
}
```

**Maximum/Minimum keresés:**
```cpp
int maxVal = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) maxVal = arr[i];
}
```

**Egyszerű rendezés (Buborék):**
```cpp
for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
```

---

## 5. Kétdimenziós tömbök (mátrixok)

**Létrehozás:**
```cpp
int matrix[3][3]; // 3×3 mátrix
int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

**Bejárás:**
```cpp
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        cout << grid[i][j] << " ";
    }
    cout << endl;
}
```

---

## 6. Karaktertömbök (C-string)

**Létrehozás:**
```cpp
char word[6] = "Hello";  // automatikusan '\0'-val zárul
```
A `'\0'` (null karakter) jelzi a string végét.

**Beolvasás:**
```cpp
char name[50];
cout << "Enter your name: ";
cin >> name;
```
> ⚠️ A `cin` megáll szóköznél.

Ha teljes sort akarunk:
```cpp
cin.getline(name, 50);
```

---

## 7. C-string függvények (`<cstring>`)

```cpp
#include <cstring>

char s1[20] = "Hello";
char s2[20] = "World";

cout << strlen(s1);        // hossz → 5
strcpy(s2, s1);            // másolás: s2 = "Hello"
strcat(s1, " World");      // összefűzés: "Hello World"
cout << strcmp("a", "b");  // összehasonlítás: -1
```

---

## 8. Példák

**Példa 1 – Tömb átlag**
```cpp
int arr[5] = {4, 7, 2, 9, 5};
int sum = 0;

for (int i = 0; i < 5; i++) sum += arr[i];

cout << "Average = " << (double)sum / 5;
```

**Példa 2 – Mátrix transzponálása**
```cpp
int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
int B[3][2];

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        B[j][i] = A[i][j];
    }
}
```

**Példa 3 – Palindrom ellenőrzés (C-string)**
```cpp
char str[100];
cin.getline(str, 100);

int len = strlen(str);
bool isPal = true;

for (int i = 0; i < len/2; i++) {
    if (str[i] != str[len - i - 1]) {
        isPal = false;
        break;
    }
}

if (isPal) cout << "Palindrome";
else cout << "Not palindrome";
```

---

## 9. Gyakorló feladatok

- Írj programot, ami beolvas 10 számot, és kiírja a legnagyobbat és legkisebbet!
- Írj programot, ami rendezi egy tömb elemeit növekvő sorrendbe!
- Írj programot, ami kiszámolja egy mátrix főátlójának összegét!
- Írj programot, ami eldönti, hogy egy szó palindrom-e (pl. “radar”).
- Írj programot, ami két szöveget összefűz egy harmadikba C-string használatával!