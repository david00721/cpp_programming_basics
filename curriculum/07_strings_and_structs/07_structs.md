# 08 – `struct` (C++)

## 🎯 Célok

- Megérteni a `struct` szerepét: hogyan csoportosítunk több, összetartozó adatot.
- Egyszerű adattípusok (pl. pont, diák, termék) létrehozása `struct` segítségével.
- `struct`-ok használata függvényekben (érték szerinti, referencia szerinti átadás).
- Tömbök, dinamikus tömbök, pointerek `struct`-okkal.
- Egyszerű egyszeresen láncolt lista megértése és megvalósítása `struct`-okkal.

---

## 1. Mi az a `struct`?

A `struct` (structure) olyan **saját típus**, amely több mezőt (változót) fog össze egy név alatt.

```cpp
struct Point {
    int x;
    int y;
};

int main() {
    Point p;       // p egy Point típusú változó
    p.x = 10;
    p.y = 20;

    cout << p.x << " " << p.y << endl;  // 10 20
}
```

- A struct definíció nem foglal memóriát, csak típust hozunk létre.
- Memória akkor foglalódik, amikor változót hozunk létre ebből a típusból (Point p;).

### Inicializálás

```cpp
Point p1 = {10, 20};
Point p2{5, 7};
```

👉 **01 - Feladat közösen:** Hozz létre egy Rectangle structot, amelynek mezői: width (szélesség), height (magasság). Hozz létre egy példányt, adj neki értékeket, és írd ki a területét!

👉 **02 - Feladat önállóan:** Hozz létre egy Student structot, mezőkkel: name (string), age (int). Hozz létre két diákot, töltsd fel adatokkal, és írd ki őket a képernyőre!

## 2. Struct és függvények

Egy struct ugyanúgy átadható függvénynek, mint bármilyen más típus.

```cpp
struct Point {
    int x;
    int y;
};

void printPoint(Point p) {           // érték szerinti átadás (másolat)
    cout << "(" << p.x << ", " << p.y << ")\n";
}

void movePoint(Point &p, int dx, int dy) {  // referencia, módosítja az eredetit
    p.x += dx;
    p.y += dy;
}

int main() {
    Point p{0, 0};

    printPoint(p);          // (0, 0)
    movePoint(p, 5, 3);
    printPoint(p);          // (5, 3)
}
```

- Érték szerinti átadás: a struct-ból másolat készül.
- Referencia (&): a függvény az eredeti objektumot módosítja.
- `const Point& p` – ha nem akarjuk módosítani, de el akarjuk kerülni a másolást.


👉 **03 - Feladat közösen:** Hozz létre egy Rectangle structot (width, height), és írj függvényt, ami paraméterként kap egy Rectangle-et referencia szerint, és kiszélesíti +5-tel.

👉 **04 - Feladat önállóan:** Készíts Student structot (name, age, averageGrade), majd írj függvényt, ami kiír egy diákot szép formában, pl.: `Név: Anna, Kor: 20, Átlag: 4.5`

## 3. Tömbök struct-okkal

```cpp
struct Point {
    int x, y;
};

int main() {
    Point points[3];        // 3 elemű tömb

    points[0] = {0, 0};
    points[1] = {1, 2};
    points[2] = {5, 6};

    for (int i = 0; i < 3; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}
```

👉 **05 - Feladat közösen:** Készíts programot, amely egy 3 elemű Student tömböt hoz létre, beolvassa a diákok nevét és életkorát, majd kiírja őket.

👉 **06 - Feladat önállóan:**

## 4. Dinamikus struct és pointerek

Struct-ból is foglalhatunk dinamikus memóriát:

```cpp
struct Point {
    int x, y;
};

int main() {
    Point* p = new Point;   // egy Point dinamikusan

    p->x = 10;              // pointer esetén: -> operátor
    p->y = 20;

    cout << p->x << " " << p->y << endl;

    delete p;               // NEM szabad elfelejteni!
}
```

- `. `: ha nem pointer (`Point p; p.x`).
- `->` : ha pointer (`Point* p; p->x`).

Dinamikus tömb:
```cpp
int n;
cin >> n;

Student* arr = new Student[n];

for (int i = 0; i < n; i++) {
    cin >> arr[i].name >> arr[i].age;
}

delete[] arr;
```

👉 **07 - Feladat közösen:** Írj programot, amely beolvas egy n értéket, majd dinamikusan lefoglal egy Point tömböt (`new Point[n]`), beolvassa az x,y koordinátákat, és kiírja őket.

👉 **08 - Feladat önállóan:** Írj programot, amely dinamikusan foglal egy Student-ot (`Student* s = new Student;`), beolvassa az adatait, kiírja, majd felszabadítja a memóriát.

## 5. Egyszeresen láncolt lista – elmélet

A láncolt lista olyan adatszerkezet, ahol az elemek (csomópontok, angolul: node) nem egy tömbben vannak, hanem mindegyik elem a következő elem címét tárolja.

Egyszeresen láncolt listánál egy csomópont így néz ki:

```cpp
struct Node {
    int value;    // az adat
    Node* next;   // pointer a következő elemre (vagy nullptr)
};
```

Példa lista: `10 -> 5 -> 7 -> (nullptr)`

```cpp
int main()
{
    Node n1; // első elem
    Node n2; // második elem
    Node n3; // harmadik elem

    n1.value = 10; // érték beállítása
    n1.next = &n2; // n1 következője n2

    n2.value = 5;  // érték beállítása
    n2.next = &n3; // n2 következője n3

    n3.value = 7;      // érték beállítása
    n3.next = nullptr; // n3 a lista vége

    // Kiíratás
    Node* current = &n1;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
```

- A lista elejét egy Node* head pointer tárolja.
- Ha head == nullptr, a lista üres.
- Műveletek:
    - beszúrás az elejére
    - bejárás (kiírás)
    - keresés
    - törlés
    - beszúrás a végére (opcionálisan tail pointerrel)

## 6. Láncolt lista megvalósítása I. – beszúrás az elejére, bejárás

Csomópont és head:

```cpp
struct Node {
    int value;
    Node* next;
};
```

Elem beszúrása a lista elejére:

```cpp
void push_front(Node* &head, int x) {
    Node* newNode = new Node;  // új csomópont
    newNode->value = x;
    newNode->next = head;      // régi head lesz a következő
    head = newNode;            // head mutasson az új csomópontra
}
```

Lista bejárása:

```cpp
void print_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
```

Példa teljes program:

```cpp
int main() {
    Node* head = nullptr;    // üres lista

    push_front(head, 10);
    push_front(head, 5);
    push_front(head, 7);     // lista: 7 -> 5 -> 10

    print_list(head);
}
```

👉 **09 - Feladat közösen:** Valósíts meg egy egyszerű láncolt listát egész számokkal, ahol:
- push_front beszúr az elejére,
- print_list kiírja a lista elemeit.
Teszteld a main-ben 3–4 beszúrással!

👉 **10 - Feladat önállóan:** Egészítsd ki a programot size függvénnyel, amely megszámolja, hány elem van a láncolt listában.

## 7. Láncolt lista megvalósítása II. – keresés, törlés, beszúrás a végére

### 7.1. Keresés

```cpp
Node* find(Node* head, int x) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == x)
            return current;
        current = current->next;
    }
    return nullptr;  // nincs meg
}
```

### 7.2. Beszúrás a végére

```cpp
void push_back(Node* &head, int x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;   // üres lista
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}
```

### 7.3. Elem törlése érték alapján (első előfordulás)

```cpp
bool erase(Node* &head, int x) {
    if (head == nullptr) return false;

    // ha az első elem a törlendő
    if (head->value == x) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->value != x) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;  // nincs ilyen elem
    }

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return true;
}
```

### 7.4. Lista felszabadítása

```cpp
void clear_list(Node* &head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}
```

👉 **11 - Feladat közösen:** Egészítsd ki a láncolt listás programot push_back és clear_list függvényekkel. A main-ben:
- szúrj be pár elemet elejére és végére is,
- írd ki a listát,
- majd clear_list hívással szabadítsd fel.

👉 **12 - Feladat önállóan:** Add hozzá az erase függvényt, amely törli az első olyan elemet, amelynek értéke x. Teszteld:
- szúrj be több elemet,
- törölj néhányat (elsőt, középsőt, utolsót),
- írd ki mindig a lista aktuális állapotát.

## 8. Komplett példa – pozitív számok láncolt listája

**Feladat:** olvass be egész számokat, amíg 0-t nem kapsz. A pozitív számokat tedd láncolt listába (beszúrás a végére), majd írd ki őket, végül szabadítsd fel a listát.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void push_back(Node* &head, int x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void clear_list(Node* &head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = nullptr;

    int x;
    while (cin >> x && x != 0) {
        if (x > 0) {
            push_back(head, x);
        }
    }

    cout << "Pozitív számok: ";
    print_list(head);

    clear_list(head);
}
```

👉 **13 - Feladat közösen:** Módosítsd a fenti programot úgy, hogy csak páros pozitív számokat tároljon a listában!

👉 **14 - Feladat önállóan:** Egészítsd ki a programot find függvénnyel. A beolvasás után kérj be egy k értéket, és írd ki, hogy k benne van-e a listában.

## 9. Gyakorló feladatok

- Készíts Product structot name (string), price (int), quantity (int) mezőkkel. Tárolj egy tömbben 5 terméket, és írd ki a teljes raktárértéket (összesen mennyi pénzt ér a készlet).

- Valósíts meg egy Book structot (title, author, year). Tárolj tömbben könyveket, és írj függvényt, ami egy adott szerző összes könyvét kiírja.

- Írj függvényt, amely kap egy Node* head láncolt listát, és visszaadja a legnagyobb értéket benne.

- Írj függvényt, amely egy láncolt listát megfordít (in-place, új lista nélkül). Tipp: három pointer (prev, current, next).

- Írj programot, amely:
    - láncolt listába olvas be egész számokat,
    - törli az összes negatív számot,
    - majd kiírja a lista tartalmát.