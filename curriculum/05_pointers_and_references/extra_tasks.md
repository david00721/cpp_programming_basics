# Extra feladatok a pointerekhez

## 1. feladat – Leghosszabb közös rész két karaktertömbben

Készíts egy függvényt, amely megkap két karaktertömböt és azok méretét, majd kiírja a leghosszabb közös folytonos részt (substring-et) a képernyőre.

### Prototípus

```cpp
void print_longest_common_substring(const char* a, int na, const char* b, int nb);
```

### Példa

```
Bemenet tömbök:
a = {'a','b','x','y','a','b','c'}, na = 7
b = {'z','z','a','b','c','q','q'}, nb = 7

Kimenet:
abc
```

## 2. feladat - Külső szorzat mátrix készítése (dinamikus memória nélkül)

Írj függvényt, amely két egész számokat tartalmazó vektort kap:
- egy oszlopvektort (no hosszú),
- egy sorvektort (ns hosszú),

és kiszámítja az összes lehetséges szorzatot úgy, hogy
a kétszeres ciklussal létrejövő no × ns mátrixba elhelyezi azokat.

### Prototípus

```cpp
void kulso_szorzas(
    const int* oszlop, int no,
    const int* sor, int ns,
    int* matrix
);
```

### Példa
```cpp
int oszlop[] = {1, 2, 3};
int sor[] = {4, 5};

int matrix[3][2];  // hívó biztosítja

kulso_szorzas(oszlop, 3, sor, 2, &matrix[0][0]);

// matrix lesz:
// 1*4=4   1*5=5
// 2*4=8   2*5=10
// 3*4=12  3*5=15
```

## 3. feladat - Legnagyobb elemsumájú sor kiválasztása 2D mátrixban

Írj egy függvényt, amely egy rows × cols egész szám mátrixot kap (sorfolytonosan tárolva), és megkeresi azt a sort, amelynek az elemei összege a legnagyobb.

A függvény:
- a legnagyobb összegű sor indexét adja vissza,
- döntetlen esetén a legkisebb sorszámú sort választja,
- pointeraritmetikát használ.

### Prototípus

```cpp
int row_with_max_sum(const int* matrix, int rows, int cols);
```

### Példa
```
Mátrix:
 1   2   3    // sum = 6
-1   5   0    // sum = 4
 9  -3   2    // sum = 8   <-- maximum
```

Visszatérés: 2

## 4. feladat - Nyeregpont (saddle point) keresése 2D mátrixban

Adott egy rows × cols egész mátrix (sorfolytonosan tárolva). Keress egy nyeregpontot, azaz olyan elemet, amely a saját sorában a legkisebb, és a saját oszlopában a legnagyobb.
Ha több van, a legkisebb sorindexű, azon belül a legkisebb oszlopindexű nyer. Ha nincs ilyen elem, jelezd false-szal.

### Prototípus
```cpp
bool find_saddle_point(
    const int* matrix, int rows, int cols,
    int* out_row, int* out_col
);
```

### Példa

```
3   5   7
2   4   9   <-- elem(1,0)=2 a sorában minimum, az oszlopában maximum → nyeregpont
6   1   0
```
Eredmény: out_row = 1, out_col = 0.