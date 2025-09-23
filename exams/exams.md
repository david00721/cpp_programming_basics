## 1. Feladat

Definiálja az `int** szorzat(int* oszlop, int no, int* sor, int ns)` függvényt, ami az `no` elemű oszlop oszlopvektor és az `ns` elemű sor sorvektor elemeiből készíthető valamennyi párt összeszorozza, és a szorzatokat tartalmazó, `no` sorból és `ns` oszlopból álló mátrixot adja eredményül!

```cpp
int sor[] = {4, 5};
int ns = sizeof(sor) / sizeof(sor[0]);
int** mtx = szorzat(oszlop, no, sor, ns);
nyomtat(oszlop, no, sor, ns, mtx);
felszabadit(mtx, no);
```

**Megoldás:**

|     | 4  | 5  |
|-----|----|----|
| **1** | 4  | 5  |
| **2** | 8  | 10 |
| **3** | 12 | 15 |

## 2. Feladat

Definiálja a `void kever(std::string& s)` függvényt, ami véletlenszerű sorrendbe állítja az `s` string karaktereit!

## 3. Feladat
Készítse el az int szamtani(int a0, int d, bool uj) függvényt! Ha az uj paraméter értéke true, akkor a függvény felkészül az an+1 = an + d képletű számtani sorozat elemeinek előállítására, és visszatérési értéke a0 lesz. Ha az uj paraméter értéke false, akkor a korábban meghatározott sorozat következő elemének értékét szolgáltatja.

```cpp
std::cout << szamtani(0, 1, true);
for(int i=0; i<9; i++) {
    std::cout << ' ' << szamtani(0, 1, false);
}
std::cout << std::endl;
```

## 4. Feladat

Definiálja azt a bool capsLocked(std::string s) függvényt, ami igaz értékkel tér vissza, ha a paraméterként neki átadott s karakterlánc
- tartalmaz legalább egy betűt és
- amennyiben az első karakter betű, akkor az kisbetű,
- az összes ezt követő karakter nem kisbetű.

Betűk alatt az angol ábécé betűit értjük, a magyar ékezetes betűkkel nem kell foglalkozni.

| Test input | Result |
|------------|--------|
| `capsLocked("pISTA")` | igen |
| `capsLocked("Pista")` | nem |

## 5. Feladat

Definiálja azt a void stackedBarChart(int** data, int rows, int cols) függvényt, ami halmozott sávdiagramot rajzol a rows sorból és cols oszlopból álló data mátrix elemeit felhasználva! A sávdiagram annyi sorból álljon, amennyi rows értéke! A sorokat rendre az X, >, +, = és - jelekkel kell megrajzolni. Mindegyikből annyit kell egymás mellé írni, amennyi a mátrix aktuális sorában a soron következő cella értéke. Ha a mátrixnak 5-nél több oszlopa lenne, csak az első 5-öt kell megrajzolni.

```cpp
int vec[6] = {
  1, 5,
  3, 3,
  5, 3
};
int** data = createMtx(vec, 3, 2);
stackedBarChart(data, 3, 2);
deleteMtx(data, 3);
```

## 6. Feladat

Definiálja a double* gp(double a1, double q, int n) függvényt, mely visszatér egy n elemű tömbbel, amelynek elemei az a1 értékű első taggal rendelkező, q kvóciensű mértani sorozat egymást követő tagjai.

```cpp
printAndClear(gp(3, 3, 5), 5);
// 3 9 27 81 243
```

## 7. Feladat

Készítse el azt a void rightAlign(const std::string& fileName) függvényt, mely a paraméterként kapott nevű fájl sorait jobbra igazítva jeleníti meg a képernyőn! Keresse meg a leghosszabb sort, és annak jobb széléhez igazítsa az összes többi sor tartalmát!

```cpp
rightAlign("file1.txt");

/*
Kimenet:
     A
    AA
   AAA
  AAAA
 AAAAA
AAAAAA

Fájl tartalma:
A
AA
AAA
AAAA
AAAAA
AAAAAA
*/
```

## 8. Feladat

Definiálja azt a void draw(const std::string& commands) függvényt, ami egy karakterláncot fogad! Ennek betűi parancsok arra vonatkozóan, hogy merre kell mozgatni egy tollat a képernyőn. A karakterlánc csak az U (fel), D (le), R (jobbra) és L (balra) betűket tartalmazza. Kezdetben a toll a képernyő bal felső sarkában áll. Feltételezheti, hogy a toll a képernyő bal felső sarkától csak jobbra és lefelé távolodik majd el, legfeljebb 10 karakterpozícióval. Minden olyan helyen, ahol a toll tartózkodik, egy csillag karakternek kell megjelennie!


```cpp
draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");
/*
**********
*        *
*        *
*        *
*        *
*        *
*        *
*        *
*        *
**********
*/
```

## 9. Feladat

Definiálja a `double getArea(int n, double l)` függvényt, ami egy `n` oldalú, `l` oldalhosszúságú **szabályos sokszög** területét adja meg.

---

### Ötlet a megoldáshoz
A sokszöget bontsuk `n` darab egyforma háromszögre a középpontba húzott szakaszokkal.
E háromszögek két oldala a köré írt kör sugara `R`, a harmadik oldala az oldalhossz `l`.

### Köré írt kör sugara

$$R=\frac{l}{2\sin\!\left(\frac{\pi}{n}\right)}$$


### Hérón-képlet (egy háromszög területe)

**Félkerület:**
$$s=\frac{a+b+c}{2}$$

**Terület:**
$$A=\sqrt{s(s-a)(s-b)(s-c)}$$

---

## Sokszög területe
Legyen a háromszög oldalai: $a=R,\; b=R,\; c=l$.  
Egy háromszög területe legyen $A$ (Hérón-képlettel számítva), ekkor a sokszög területe:

$$T = n \cdot A$$

> **Megjegyzés:** ekvivalens, zárt alakú képlet is használható:
$$T=\frac{n\,l^2}{4\tan\!\left(\frac{\pi}{n}\right)}$$

```cpp
std::cout << std::setprecision(2) << getArea(4, 2) << std::endl;
// 4
```

## 10. feladat

Definiálja azt a void decode(const prefixPair* codeWords, const std::string& message) függvényt, melynek célja egy prefix kóddal kódolt szöveg visszafejtése és szavainak szabvány kimenetre nyomtatása egymás alá!

A prefix kódok olyan kódszavakkal helyettesítik az eredeti üzenet szavait, melyekre teljesül a prefix tulajdonság, azaz egyik kódszó sem kezdődik egyetlen másik kódszóval sem. A kódszavakat a codeWords paraméter adja meg egy prefixPair típusú struktúrákból álló láncolt lista formájában. Ennek codeWord tagja egy kódszó (pl. "0"), text tagja pedig a kódolt szöveg (pl. "Samsung"). A next nevű tag a következő listaelemet címzi. A decode függvény második, message paramétere a kódolt üzenetet adja meg.

A listaelemek tehát a következő típussal adottak:

```cpp
struct prefixPair {
    std::string codeWord;
    std::string text;
    prefixPair* next;
};

prefixPair* codeWords = nullptr;
append(codeWords, "0", "Samsung");
append(codeWords, "10", "Xiaomi");
append(codeWords, "11", "Apple");
decode(codeWords, "01011100");
clear(codeWords);

/*
Samsung
Xiaomi
Apple
Xiaomi
Samsung
*/
```

