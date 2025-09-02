# 07 – Strings (C++)

## 🎯 Célok

- Megérteni a C-string (null-terminated char tömb) működését.
- Alapvető string műveletek implementálása `cstring` függvényekkel.
- Megismerni a `std::string` osztályt.
- Gyakorolni a különbségeket a C-string és `std::string` között.

---

## 1. C-string alapok

Egy karaktertömb, amelynek végén kötelező a `'\0'` lezáró karakter.

```cpp
char str1[] = "Hello";    // automatikusan: {'H','e','l','l','o','\0'}
char str2[6] = "Hello";   // pontos méret, hely a lezárónak
char str3[10] = "Hello";  // nagyobb méret (üres hely marad)
```

**Kiírás:**
```cpp
cout << str1;  // Hello
```

> ⚠️ Ha nincs `'\0'`, akkor a kiírás szemét adhat, mert nem tudja, hol ér véget.

---

## 2. C-string műveletek (`<cstring>`)

```cpp
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char a[20] = "Hello";
    char b[20] = "World";

    cout << strlen(a) << endl;        // 5
    cout << strcmp(a, b) << endl;     // negatív (mert H < W)
    strcat(a, b);                     // a = "HelloWorld"
    cout << a << endl;

    strcpy(b, "C++");                 // b = "C++"
    cout << b << endl;
}
```

- `strlen(s)` → hossz
- `strcmp(s1, s2)` → lexikografikus összehasonlítás (0: egyenlő)
- `strcpy(dest, src)` → másolás
- `strcat(dest, src)` → összefűzés

---

## 3. Dinamikus C-string

```cpp
int n;
cin >> n;

char *str = new char[n+1];
cin >> str;

cout << "You typed: " << str << endl;

delete[] str;
```

---

## 4. `std::string` (modern C++)

Sokkal biztonságosabb és kényelmesebb.

**Létrehozás**
```cpp
string s1 = "Hello";
string s2("World");
string s3 = s1 + " " + s2;  // "Hello World"
```

**Alap műveletek**
```cpp
cout << s3.size();          // hossz
cout << s3[0];              // karakter indexeléssel
s3.append("!!!");           // "Hello World!!!"
cout << s3;

if (s1 == "Hello") cout << "Equal!";
```

**Iterálás**
```cpp
for (char c : s3)
    cout << c << " ";
```

---

## 5. string → C-string konverzió

```cpp
string s = "Hello";
const char* cstr = s.c_str();  // csak olvasható
cout << cstr;
```

---

## 6. Példák

**Példa 1 – Fordított string**
```cpp
string s;
cin >> s;

for (int i = s.size()-1; i >= 0; i--)
    cout << s[i];
```

**Példa 2 – Szó számlálás**
```cpp
string text = "this is a simple test";
int count = 0;

for (int i = 0; i < text.size(); i++)
    if (text[i] == ' ') count++;

cout << "Words: " << count + 1;
```

---

## 7. Gyakorló feladatok

- Írj programot, ami beolvas egy szót `char[]`-ba, és kiírja a hosszát `strlen` segítségével.
- Készíts programot, ami két C-stringet összefűz `strcat` használatával.
- Írj függvényt, ami `std::string`-ből kiszűri az összes magánhangzót.
- Írj programot, ami beolvas egy mondatot `std::string`-ként, és megszámolja, hány szó van benne.
- Írj programot, ami megfordítja a felhasználó által beírt szót (C-string változatban és `std::string`-ben is).