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

**Általános forma:**
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
```

**Használat:**
```cpp
int main() {
    cout << square(5) << endl; // 25
}
```

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

---

## 5. Alapértelmezett paraméterek

Ha nincs érték megadva, a megadott alapértéket használja.

```cpp
int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

cout << power(5) << endl;    // 25
cout << power(5, 3) << endl; // 125
```

---

## 6. Függvény túlterhelés (overloading)

Ugyanaz a név, de eltérő paraméterlista.

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

---

## 7. Rekurzió

A függvény saját magát hívja.  
**Fontos:** mindig legyen megállási feltétel!

**Faktoriális:**
```cpp
int factorial(int n) {
    if (n == 0) return 1;   // bázis eset
    return n * factorial(n - 1); // rekurzív hívás
}
```

**Fibonacci-sor:**
```cpp
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

> ⚠️ Rekurzió előnye: kód egyszerűbb. Hátránya: lassabb lehet, sok memória kell (stack).

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

---

## 9. Gyakorló feladatok

- Írj függvényt, ami visszaadja egy szám négyzetét!
- Írj függvényt, ami visszaadja egy szám összes osztójának számát!
- Írj függvényt, ami eldönti, hogy egy szám prímszám-e!
- Írj rekurzív függvényt, ami visszaadja egy szám faktoriálisát!
- Írj függvényt, ami két szám LNKO-ját számolja ki (rekurzívan)!