# 02 – Control Structures (C++)

## 🎯 Célok

- Megérteni, hogyan lehet döntéseket hozni a programban.
- Megtanulni az `if-else`, `switch` szerkezeteket.
- Elsajátítani a ciklusok működését (`for`, `while`, `do-while`).
- Gyakorlati feladatokkal alkalmazni az ismétlést és az elágazást.

---

## 🔹 1. Elágazások (Decisions)

### If szerkezet

```cpp
if (feltétel) {
    // utasítás, ha a feltétel igaz
}
```

### If-else szerkezet

```cpp
if (x > 0) {
    cout << "Positive";
} else {
    cout << "Not positive";
}
```

### If-else if-else lánc

```cpp
if (x > 0) {
    cout << "Positive";
} else if (x < 0) {
    cout << "Negative";
} else {
    cout << "Zero";
}
```

### Switch szerkezet

Akkor használjuk, ha egy változó több lehetséges értékét akarjuk vizsgálni.

```cpp
switch (grade) {
    case 'A': cout << "Excellent"; break;
    case 'B': cout << "Good"; break;
    case 'C': cout << "Average"; break;
    case 'D': cout << "Poor"; break;
    case 'F': cout << "Fail"; break;
    default: cout << "Invalid grade";
}
```

> **Figyelem:**  
> - A `break` megakadályozza, hogy a végrehajtás „átcsússzon” a következő ágba.  
> - A `default` opcionális, de jó gyakorlat használni.

---

## 🔹 2. Ciklusok (Loops)
### For ciklus

Akkor használjuk, ha előre tudjuk, hányszor ismétlünk.

```cpp
for (int i = 0; i < 5; i++) {
    cout << "i = " << i << endl;
}
```

- `int i = 0;` → inicializálás
- `i < 5;` → feltétel
- `i++` → minden iteráció után végrehajtódik

#### Tömb bejárása for ciklussal

Ha egy tömb minden elemén végig akarunk menni:

```cpp
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

#### Range-based for ciklus (C++11-től)

Egyszerűbb szintaxis tömbök vagy konténerek bejárásához:

```cpp
int arr[] = {10, 20, 30, 40, 50};
for (int x : arr) {
    cout << x << " ";
}
```

### While ciklus

Addig ismétel, amíg a feltétel igaz.

```cpp
int i = 0;
while (i < 5) {
    cout << "i = " << i << endl;
    i++;
}
```

### Do-while ciklus

Mindig lefut legalább egyszer, akkor is, ha a feltétel hamis.

```cpp
int i = 0;
do {
    cout << "i = " << i << endl;
    i++;
} while (i < 5);
```

### Vezérlési utasítások

- `break` → kilép a ciklusból
- `continue` → ugrik a következő iterációra

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;  // 3 kimarad
    cout << i << " ";
}
```

---

## 🔹 3. Beágyazott ciklusok

Ciklus egy másikon belül – például szorzótábla:

```cpp
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i * j << "\t";
    }
    cout << endl;
}
```

---

## 🔹 4. Gyakorlati példák

**Példa 1 – Páros/páratlan szám**

```cpp
int x;
cin >> x;
if (x % 2 == 0) cout << "Even";
else cout << "Odd";
```

**Példa 2 – Maximum három szám közül**

```cpp
int a, b, c;
cin >> a >> b >> c;

int max = a;
if (b > max) max = b;
if (c > max) max = c;

cout << "Max = " << max;
```

**Példa 3 – Szám faktoriálisa (for ciklussal)**

```cpp
int n;
cin >> n;
long long fact = 1;

for (int i = 1; i <= n; i++) {
    fact *= i;
}

cout << "n! = " << fact;
```

**Példa 4 – Számjegyek összege (while ciklussal)**

```cpp
int n, sum = 0;
cin >> n;

while (n > 0) {
    sum += n % 10;
    n /= 10;
}

cout << "Sum of digits = " << sum;
```

**Példa 5 – Egyszerű menü (switch + do-while)**

```cpp
int choice;
do {
    cout << "Menu:\n";
    cout << "1. Say Hello\n";
    cout << "2. Say Goodbye\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: cout << "Hello!\n"; break;
        case 2: cout << "Goodbye!\n"; break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
    }
} while (choice != 0);
```

---

## 🔹 5. Gyakorló feladatok

- Írj programot, ami kiírja 1-től 100-ig az összes páros számot!
- Írj programot, ami kiszámolja az első n természetes szám összegét (1+2+…+n)!
- Kérj be egy számot, és döntsd el róla, hogy prímszám-e!
- Írj programot, ami kirajzol egy 10×10-es négyzetet `*` karakterekből!
- Írj egyszerű menüt, ami addig ismétlődik, amíg a felhasználó ki nem lép!