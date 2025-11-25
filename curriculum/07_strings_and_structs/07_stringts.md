# 07 – Strings (C++)

## 🎯 Célok

- Megérteni a C-string (null-terminated char tömb) működését.
- Alapvető string műveletek implementálása `cstring` függvényekkel.
- Megismerni a `std::string` osztályt.
- Gyakorolni a különbségeket a C-string és `std::string` között.

---

## 1. C-string alapok

Egy karaktertömb, amelynek végén kötelező a `\0` lezáró karakter.

```cpp
char str1[] = "Hello";    // automatikusan: {'H','e','l','l','o','\0'}
char str2[6] = "Hello";   // pontos méret, hely a lezárónak
char str3[10] = "Hello";  // nagyobb méret (üres hely marad)
```

**Kiírás:**
```cpp
cout << str1;  // Hello
```

👉 **01 - Feladat közösen:** Írj programot, ami beolvas egy szót C-stringként, majd kiírja!  
👉 **02 - Feladat önállóan:** Írj programot, ami létrehoz egy C-stringet, és kiírja az első és utolsó karakterét!

> ⚠️ Ha nincs `\0`, akkor a kiírás szemét adatot adhat, mert nem tudja, hol ér véget.

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

👉 **03 - Feladat közösen:** Írj programot, ami két C-stringet összefűz `strcat` segítségével!  
👉 **04 - Feladat önállóan:** Írj programot, ami két C-stringet összehasonlít `strcmp`-pal, és kiírja, melyik van előbb az ABC-ben!

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

👉 **05 - Feladat közösen:** Írj programot, ami dinamikusan lefoglal egy C-stringet, majd beolvas egy szót és kiírja!  
👉 **06 - Feladat önállóan:** Írj programot, ami dinamikusan lefoglal egy C-stringet, majd visszafelé kiírja a tartalmát!

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

👉 **07 - Feladat közösen:** Írj programot, ami két `std::string`-et összefűz és kiírja!  
👉 **08 - Feladat önállóan:** Írj programot, ami beolvas egy `std::string`-et, és kiírja a hosszát!

---

**Iterálás**
```cpp
for (char c : s3)
    cout << c << " ";
```

👉 **09 - Feladat közösen:** Írj programot, ami végigiterál egy `std::string`-en, és kiírja a karaktereket szóközzel elválasztva!  
👉 **10 - Feladat önállóan:** Írj programot, ami megszámolja, hány magánhangzó van egy `std::string`-ben!

---

## 5. string → C-string konverzió

```cpp
string s = "Hello";
const char* cstr = s.c_str();  // csak olvasható
cout << cstr;
```

👉 **11 - Feladat közösen:** Írj programot, ami konvertál egy `std::string`-et C-stringgé, majd kiírja!  
👉 **12 - Feladat önállóan:** Írj programot, ami `std::string`-et alakít C-stringgé, majd megszámolja a karakterek számát `strlen` segítségével!

---

## 6. Példák

**Példa 1 – Fordított string**
```cpp
string s;
cin >> s;

for (int i = s.size()-1; i >= 0; i--)
    cout << s[i];
```

👉 **13 - Feladat közösen:** Írj programot, ami megfordít egy szót `std::string` használatával!  
👉 **14 - Feladat önállóan:** Írj programot, ami megfordít egy szót C-stringként!

---

**Példa 2 – Szó számlálás**
```cpp
string text = "this is a simple test";
int count = 0;

for (int i = 0; i < text.size(); i++)
    if (text[i] == ' ') count++;

cout << "Words: " << count + 1;
```

👉 **15 - Feladat közösen:** Írj programot, ami megszámolja, hány szó van egy `std::string` mondatban!  
👉 **16 - Feladat önállóan:** Írj programot, ami megszámolja, hány szó van egy mondatban C-string használatával!

---

## 7. Gyakorló feladatok

- Írj programot, ami beolvas egy szót `char[]`-ba, és kiírja a hosszát `strlen` segítségével.
- Készíts programot, ami két C-stringet összefűz `strcat` használatával.
- Írj függvényt, ami `std::string`-ből kiszűri az összes magánhangzót.
- Írj programot, ami beolvas egy mondatot `std::string`-ként, és megszámolja, hány szó van benne.
- Írj programot, ami megfordítja a felhasználó által beírt szót (C-string változatban és `std::string`-ben is).