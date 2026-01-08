# C++ rand() alapú random generálás

---

## Inicializálás (`srand`)

A `srand()` funkcióval egyszer inicializáljuk a véletlenszám-generátort a program elején:

```cpp
#include <cstdlib>
#include <ctime>

srand(time(NULL));  // egyszer a program indulásakor
```

---

## Random egész generálása

```cpp
int x = rand();  // 0 .. RAND_MAX
```

---

## Random tört generálása (0 .. 1 között)

```cpp
double y = (double)rand() / RAND_MAX;  // [0; 1]
```

---

## Random egész tartományban [a; b]

```cpp
int r = a + rand() % (b - a + 1);
```

**Példa (10..20 között):**
```cpp
int r = 10 + rand() % (20 - 10 + 1);
```

---

## Random tört tartományban [a; b)

```cpp
double r = a + (double)rand() / RAND_MAX * (b - a);
```

**Példa (5.0 .. 10.0 között):**
```cpp
double r = 5.0 + (double)rand() / RAND_MAX * (10.0 - 5.0);
```

---

## Megjegyzés

- `rand()` modulo (`%`) osztással **nem egyenletes** egyes tartományokban, de egyszerű példákhoz megfelel.
- A `srand(time(NULL))`-t **soha ne hívd többször**, csak a program elején.

---
