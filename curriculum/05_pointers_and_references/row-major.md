# Row-major tárolás (mátrixok indexelése pointerekkel)

A sorfolytonos (row-major) tárolás azt jelenti, hogy egy 2D mátrix elemei a memóriában egymás után úgy vannak eltárolva, hogy egy sor minden eleme egymás után következik, és csak utána jön a következő sor.

```
Példa mátrix
[ a b c ]
[ d e f ]
```

A memóriában így áll:
```
a b c d e f
```

Tehát először az első sor végéig megyünk, aztán folytatjuk a következő sorral.

## Indexelés képlettel

Ha a mátrix mérete rows × cols, és az (i, j) (i-edik sor, j-edik oszlop) elemet akarjuk elérni pointerrel:

```
*(base + i*cols + j)
```

- i * cols → ennyi elemet kell átugrani, hogy eljussunk az i-edik sor elejéhez
- +j → aztán előrelépni az oszlop irányában

## Mini példa

Legyen 3 sor, 4 oszlop:
```
[ 1  2  3  4 ]
[ 5  6  7  8 ]
[ 9 10 11 12 ]
```

A (1, 2) pozíció (második sor, harmadik oszlop, 0-tól számolva) indexe:

```
1*4 + 2 = 6
```

Memóriában a 6. index → 7
