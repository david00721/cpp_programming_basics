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

👉 **01 - Feladat közösen:** Írj programot, ami bekér egy számot, és kiírja, hogy nagyobb-e 10-nél!  
👉 **02 - Feladat önállóan:** Írj programot, ami bekér egy számot, és kiírja, hogy kisebb-e 100-nál!

---

### If-else szerkezet

```cpp
if (x > 0) {
    cout << "Positive";
} else {
    cout << "Not positive";
}
```

👉 **03 - Feladat közösen:** Írj programot, ami bekér egy számot, és kiírja, hogy pozitív vagy nem!  
👉 **04 - Feladat önállóan:** Írj programot, ami bekér egy számot, és kiírja, hogy páros vagy páratlan!

---

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

👉 **05 - Feladat közösen:** Írj programot, ami bekér egy számot, és kiírja, hogy pozitív, negatív vagy nulla!  
👉 **06 - Feladat önállóan:** Írj programot, ami bekér egy számot, és eldönti róla, hogy osztható-e 3-mal, 5-tel vagy mindkettővel!

---

### Switch szerkezet

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

👉 **07 - Feladat közösen:** Írj programot, ami bekér egy jegyet (A–F), és szöveges értékelést ad rá!  
👉 **08 - Feladat önállóan:** Írj programot, ami bekér egy számot 1–7 között, és kiírja a hét megfelelő napját!

---

## 🔹 2. Ciklusok (Loops)

### For ciklus

```cpp
for (int i = 0; i < 5; i++) {
    cout << "i = " << i << endl;
}
```

👉 **09 - Feladat közösen:** Írj programot, ami kiírja az 1–10 közötti számokat!  
👉 **10 - Feladat önállóan:** Írj programot, ami kiírja az 1–20 közötti páros számokat!

---

#### Tömb bejárása for ciklussal

```cpp
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

👉 **11 - Feladat közösen:** Írj programot, ami kiírja egy tömb minden elemét!  
👉 **12 - Feladat önállóan:** Írj programot, ami összeadja egy tömb elemeit!

---

#### Range-based for ciklus (C++11-től)

```cpp
int arr[] = {10, 20, 30, 40, 50};
for (int x : arr) {
    cout << x << " ";
}
```

👉 **13 - Feladat közösen:** Írj programot, ami kiírja a tömb elemeit range-based for ciklussal!  
👉 **14 - Feladat önállóan:** Írj programot, ami megszámolja, hány páros szám van a tömbben!

---

### While ciklus

```cpp
int i = 0;
while (i < 5) {
    cout << "i = " << i << endl;
    i++;
}
```

👉 **15 - Feladat közösen:** Írj programot, ami while ciklussal kiírja az 1–10 közötti számokat!  
👉 **16 - Feladat önállóan:** Írj programot, ami while ciklussal összeadja az 1–n közötti számokat!

---

### Do-while ciklus

```cpp
int i = 0;
do {
    cout << "i = " << i << endl;
    i++;
} while (i < 5);
```

👉 **17 - Feladat közösen:** Írj programot, ami do-while ciklussal legalább egyszer kiír egy üzenetet!  
👉 **18 - Feladat önállóan:** Írj programot, ami do-while ciklussal addig kér be számot, amíg a felhasználó nullát nem ad meg!

---

### Vezérlési utasítások

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;  // 3 kimarad
    cout << i << " ";
}
```

👉 **19 - Feladat közösen:** Írj programot, ami 1–10 között kiír minden számot, kivéve az 5-öst!  
👉 **20 - Feladat önállóan:** Írj programot, ami 1–20 között kiírja a számokat, de ha 13-hoz ér, kilép a ciklusból!

---

## 🔹 3. Beágyazott ciklusok

```cpp
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        cout << i * j << "\t";
    }
    cout << endl;
}
```

👉 **21 - Feladat közösen:** Írj programot, ami beágyazott ciklussal kirajzol egy 5×5-ös négyzetet `*` karakterekből!  
👉 **22 - Feladat önállóan:** Írj programot, ami beágyazott ciklussal kirajzol egy derékszögű háromszöget `*` karakterekből!

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

👉 **23 - Feladat közösen:** Egészítsd ki a menüt egy új opcióval, ami kiírja a nevedet!  
👉 **24 - Feladat önállóan:** Egészítsd ki a menüt egy új opcióval, ami kiszámolja két szám összegét!

---

## 🔹 5. Gyakorló feladatok

- Írj programot, ami kiírja 1-től 100-ig az összes páros számot!
- Írj programot, ami kiszámolja az első n természetes szám összegét (1+2+…+n)!
- Kérj be egy számot, és döntsd el róla, hogy prímszám-e!
- Írj programot, ami kirajzol egy 10×10-es négyzetet `*` karakterekből (csak a körvonalát)!
- Írj egyszerű menüt, ami addig ismétlődik, amíg a felhasználó ki nem lép!

---

