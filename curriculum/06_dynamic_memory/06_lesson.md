# 06 – Dynamic Memory (C++)

## 🎯 Célok

- Megérteni a dinamikus memóriafoglalás szükségességét.
- Használni a `new` és `delete` operátorokat.
- Dinamikus tömböket kezelni.
- Megismerni a memória-szivárgás (memory leak) problémáját.
- Gyakorolni dinamikus memória használatát függvényekben és adatszerkezetekben.

---

### 1. Miért van szükség dinamikus memóriára?

- **Statikus memória:** méretet fordítási időben kell tudni.

    ```cpp
    int arr[100];   // fix méret, nem változtatható futás közben
    ```

- **Dinamikus memória:** futásidőben foglalunk helyet a heap-en.  
    Például: felhasználó által megadott méretű tömb.

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
int *arr = new int[n];   // n méretű tömb foglalása
for (int i = 0; i < n; i++) arr[i] = i * 2;
for (int i = 0; i < n; i++) cout << arr[i] << " ";
delete[] arr;   // tömb felszabadítása
```

> ⚠️ Ha elfelejtjük a `delete`-et → memóriaszivárgás (a memória foglalt marad a program végéig).

---

### 3. Példák

**Példa 1 – Dinamikus változó**
```cpp
int *x = new int(10);  // értékadás foglaláskor
cout << *x;  // 10
delete x;
```

**Példa 2 – Dinamikus mátrix**
```cpp
int rows = 3, cols = 4;

// mátrix létrehozása
int **matrix = new int*[rows];
for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

// kitöltés
for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
                matrix[i][j] = i + j;

// kiírás
for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
                cout << matrix[i][j] << " ";
        cout << endl;
}

// felszabadítás
for (int i = 0; i < rows; i++)
        delete[] matrix[i];
delete[] matrix;
```

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

---

### 5. Memória-szivárgás (Memory leak)

Ha lefoglaljuk a memóriát, de nem szabadítjuk fel → szivárgás.  
Ez nagy programokban súlyos probléma lehet.

```cpp
for (int i = 0; i < 1000; i++) {
        int *p = new int(i);
        // delete p;  <-- ha kimarad, memória szivárog
}
```

---

### 6. Smart pointer (előzetes)

Modern C++-ban ritkán kell `new`/`delete`, helyette:

- `std::unique_ptr` – egy tulajdonos
- `std::shared_ptr` – több tulajdonos
- `std::weak_ptr` – nem számít bele az élettartamba

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

---

### 8. Gyakorló feladatok

- Készíts programot, ami lefoglal egy n hosszú tömböt, feltölti véletlenszámokkal, majd kiírja a legnagyobb értéket.
- Írj függvényt, ami dinamikusan létrehoz egy n x n mátrixot, és visszaadja a főátló összegét.
- Készíts függvényt, ami két dinamikus tömböt összefűz egy új tömbbe.
- Írj programot, ami dinamikusan lefoglalt karaktertömbben tárolja a felhasználó által beírt szót, majd visszafelé kiírja.
- Szimulálj memória-szivárgást, majd javítsd ki a `delete` megfelelő használatával.