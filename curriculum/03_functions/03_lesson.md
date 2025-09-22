# 03 – Functions (C++)

## 🎯 Célok

- Megérteni, miért használunk függvényeket.
- Megtanulni függvények definícióját, deklarációját és hívását.
- Megérteni a paraméterátadási módokat (érték, referencia, pointer).
- Megtanulni az alapértelmezett paramétereket és a függvény túlterhelést.
- Bevezetés a rekurzióba.

---

## 1. Miért jó a függvény?

- **Modularitás**: kisebb, átlátható részekre osztjuk a programot.
- **Újrafelhasználhatóság**: ugyanazt a kódot több helyen is meghívhatjuk.
- **Olvashatóság**: a főprogram tisztább, jobban érthető.

---

## 2. Függvény felépítése

```cpp
visszatérési_típus függvényNév(paraméterek) {
    // utasítások
    return érték; // ha van visszatérés
}
```

**Példa:**
```cpp
int square(int x) {
    return x * x;
}

int main() {
    cout << square(5) << endl; // 25
}
```

👉 **Feladat közösen:** Írj függvényt, ami visszaadja egy szám köbét!  
👉 **Feladat önállóan:** Írj függvényt, ami visszaadja egy szám kétszeresét!

---

## 3. Függvény deklaráció és definíció

C++-ban a függvényeket a `main()` felett kell definiálni, vagy előre deklarálni.

```cpp
int add(int a, int b); // deklaráció (prototípus)

int main() {
    cout << add(3, 4);
}

int add(int a, int b) { // definíció
    return a + b;
}
```

👉 **Feladat közösen:** Írj függvényt, ami két szám különbségét adja vissza, és használd prototípussal!  
👉 **Feladat önállóan:** Írj függvényt, ami két szám szorzatát adja vissza, prototípussal!

---

## 4. Paraméterátadás

- **Érték szerint (by value):** Másolatot kap, az eredeti változó nem módosul.
    ```cpp
    void f(int x) {
        x = 100;
    }
    ```

- **Referencia szerint (by reference):** Az eredeti változó módosul.
    ```cpp
    void f(int &x) {
        x = 100;
    }
    ```

- **Pointerrel:**
    ```cpp
    void f(int *x) {
        *x = 100;
    }
    ```

👉 **Feladat közösen:** Írj egy függvényt, ami érték szerint próbál módosítani egy változót, majd ellenőrizd, hogy változott-e!  
👉 **Feladat önállóan:** Írj egy függvényt, ami referencia szerint kap egy változót, és ténylegesen módosítja az értékét!

---

## 5. Alapértelmezett paraméterek

```cpp
int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

cout << power(5) << endl;    // 25
cout << power(5, 3) << endl; // 125
```

👉 **Feladat közösen:** Írj függvényt, ami egy számot hatványoz, és próbáld ki az alapértelmezett kitevőt!  
👉 **Feladat önállóan:** Írj függvényt, ami egy számot megszoroz egy alapértelmezett értékkel (pl. 10-zel), ha nem adsz meg másikat!

---

## 6. Függvény túlterhelés (overloading)

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

cout << add(3, 4) << endl;     // int verzió
cout << add(2.5, 1.5) << endl; // double verzió
```

👉 **Feladat közösen:** Írj két `multiply` függvényt: egyet int, egyet double típusra!  
👉 **Feladat önállóan:** Írj két `maximum` függvényt: egyet int, egyet double típusra!

---

## 7. Rekurzió

### Faktoriális
```cpp
int factorial(int n) {
    if (n == 0) return 1;   // bázis eset
    return n * factorial(n - 1); // rekurzív hívás
}
```

### Fibonacci-sor
```cpp
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

👉 **Feladat közösen:** Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
👉 **Feladat önállóan:** Írj rekurzív függvényt, ami visszaadja a Fibonacci-sorozat n-edik elemét!

---

## 8. Példák

**Példa 1 – Maximum két szám közül**
```cpp
int maximum(int a, int b) {
    return (a > b) ? a : b;
}
```

**Példa 2 – LNKO (legnagyobb közös osztó) – rekurzívan (Euklideszi algoritmus)**
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

**Példa 3 – Számjegyek összege (rekurzió)**
```cpp
int digit_sum(int n) {
    if (n == 0) return 0;
    return (n % 10) + digit_sum(n / 10);
}
```

👉 **Feladat közösen:** Írj függvényt, ami visszaadja két szám legnagyobb közös osztóját!  
👉 **Feladat önállóan:** Írj rekurzív függvényt, ami kiszámolja egy szám számjegyeinek szorzatát!

---

## 9. Gyakorló feladatok

- Írj függvényt, ami visszaadja egy szám négyzetét!
- Írj függvényt, ami visszaadja egy szám összes osztójának számát!
- Írj függvényt, ami eldönti, hogy egy szám prímszám-e!
- Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
- Írj függvényt, ami két szám LNKO-ját számolja ki (rekurzívan)!

---

