# Láncolt listás vizsgafeladatok
---

## 1. Feladat – Prefix kód dekódolása (`decode`)

Definiálja azt a

```cpp
void decode(const prefixPair* codeWords, const std::string& message);
```

függvényt, melynek célja egy **prefix kóddal** kódolt szöveg visszafejtése és szavainak
szabvány kimenetre nyomtatása **egymás alá**!

A *prefix kódok* olyan kódszavakkal helyettesítik az eredeti üzenet szavait, melyekre teljesül a **prefix tulajdonság**, azaz:

> egyik kódszó sem kezdődik egyetlen másik kódszóval sem.

A kódszavakat a `codeWords` paraméter adja meg egy `prefixPair` típusú struktúrákból álló **láncolt lista** formájában.  
Ennek

- `codeWord` tagja egy kódszó (pl. `"0"`),
- `text` tagja pedig a kódolt szöveg (pl. `"Samsung"`),
- `next` nevű tagja a következő listaelemet címzi.

A `decode` függvény második paramétere (`message`) a **kódolt üzenetet** adja meg.

### Struktúra definíciója

```cpp
struct prefixPair {
    std::string codeWord;
    std::string text;
    prefixPair* next;
};
```

### Példa használat

```cpp
prefixPair* codeWords = nullptr;
append(codeWords, "0",  "Samsung");
append(codeWords, "10", "Xiaomi");
append(codeWords, "11", "Apple");

decode(codeWords, "01011100");
clear(codeWords);
```

### Várt kimenet

```text
Samsung
Xiaomi
Apple
Xiaomi
Samsung
```

---

## 2. Feladat – Ingatlanok adatai láncolt listában

Ingatlanok értékeit gyűjtjük össze egy **láncolt listába**.

Egy láncolt lista elemben a következő adatokat tároljuk:

- **Terület** (négyzetméterben) – `double`
- **Érték** (forintban) – `int` vagy `long long`

Feladat:

1. A láncolt lista struktúra elkészítése (`IngatlanLista`).
2. **Beszúrás a lista elejére** művelet (`beszurElejere`).
3. Az ingatlanok által lefedett **teljes terület** összegzése (`totalArea`).
4. Az **átlagos ingatlanérték** meghatározása **az összterület felhasználásával** (`averageArea`).  
   Ügyeljen a **0-s osztóra** (ha az összterület nulla, ne osszunk vele)!

### Segítség – függvényfejlécek (példa)

```cpp
struct IngatlanLista {
    double area;       // négyzetméter
    long long value;   // Ft
    IngatlanLista* next;
};

IngatlanLista* beszurElejere(IngatlanLista* head, double area, long long value);
double totalArea(const IngatlanLista* head);
double averageArea(const IngatlanLista* head);
```

### Példa használat

```cpp
IngatlanLista* list = nullptr;
list = beszurElejere(nullptr, 10.0, 1000);
list = beszurElejere(list,  5.0,  500);
list = beszurElejere(list,  5.0,  500);

std::cout << totalArea(list)   << '\n';
std::cout << averageArea(list) << '\n';
```

### Várt kimenet

```text
20
100
```

*(Itt az átlagos értéket az összterület felhasználásával kell kiszámítani a feladatleírás szerint.)*

---

## 3. Feladat – Bankszámla és másodlagos azonosítók (`append`)

Banki átutalás során ma már nem csak egy adott számlaszámra lehet utalni, hanem ún.
**másodlagos azonosítók** (e-mail cím, mobiltelefonszám, adószám, adóazonosító jel) alapján is.

Egy bankszámlaszámot és a hozzá társított másodlagos azonosítókat **egy irányban láncolt listában** tároljuk.  
A listaelem szerkezetét már előzetesen definiáltuk a következőképpen:

```cpp
struct account {
    std::string accountNo;
    std::string email;
    std::string mobile;
    std::string taxNo;
    std::string taxId;
    account* next;
};
```

### Feladat

Definiálja azt az

```cpp
account* append(account* anchor,
                std::string accountNo,
                std::string email,
                std::string mobile,
                std::string taxNo,
                std::string taxId);
```

függvényt, ami:

1. A lista **végéhez** hozzáfűzi a megadott azonosítókból álló listaelemet,
2. **Csak akkor**, ha **minden azonosító egyedi** (nincs még olyan listaelem, amelynél bármelyik mező megegyezik a beszúrni kívánttal),
3. Visszatér a lista **horgonyával** (első elemének címével).

### Példa használat

```cpp
account* a1 = nullptr;

a1 = insertFirst(a1, "33333333-33333333", "3@bank.hu", "+36 333-3333",
                 "33333333-3-33", "3333333333");
a1 = insertFirst(a1, "22222222-22222222", "2@bank.hu", "+36 222-2222",
                 "22222222-2-22", "2222222222");
a1 = insertFirst(a1, "11111111-11111111", "1@bank.hu", "+36 111-1111",
                 "11111111-1-11", "1111111111");

a1 = append(a1, "44444444-44444444", "4@bank.hu", "+36 444-4444",
            "44444444-4-44", "4444444444");

print(a1);
freeMem(a1);
```

### Várt kimenet

```text
11111111-11111111/1@bank.hu/+36 111-1111/11111111-1-11/1111111111
22222222-22222222/2@bank.hu/+36 222-2222/22222222-2-22/2222222222
33333333-33333333/3@bank.hu/+36 333-3333/33333333-3-33/3333333333
44444444-44444444/4@bank.hu/+36 444-4444/44444444-4-44/4444444444
```

---

## 4. Feladat – Szöveg feldarabolása láncolt listába (`splitter`)

Definiálja a

```cpp
ListItem* splitter(const std::string& text, char separator);
```

függvényt, ami a `separator` karakterek mentén több szóra bontja a `text` szöveget, és az így
előálló szavakat a `ListItem` típusú, előzetesen már definiált struktúrákból álló,
**egy irányban láncolt listában** helyezi el.

A visszatérési érték a lista **horgonya** legyen!

### Struktúra definíciója

```cpp
struct ListItem {
    std::string word;
    ListItem* next;
};
```

### Példa használat

```cpp
printAndDelete(
    splitter("This is the beginning of a beautiful friendship.", ' ')
);
```

(A `printAndDelete` egy segédfüggvény, amely kiírja a lista szavait, majd felszabadítja a dinamikusan foglalt memóriát.)
