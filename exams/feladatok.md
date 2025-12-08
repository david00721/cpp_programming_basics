# C++ Feladatgyűjtemény 

---

## 1. Feladat – szorzat

**Feladat:**  
Definiálja az `int** szorzat(int* oszlop, int no, int* sor, int ns)` függvényt, ami az no elemű oszlop oszlopvektor és az ns elemű sor sorvektor elemeiből készíthető valamennyi párt összeszorozza, és a szorzatokat tartalmazó, no sorból és ns oszlopból álló mátrixot adja eredményül!

```cpp
Main()
int sor[] = {4, 5};
int ns = sizeof(sor)/sizeof(sor[0]);
int** mtx = szorzat(oszlop, no, sor, ns);
nyomtat(oszlop, no, sor, ns, mtx);
felszabadit(mtx, no);
```

Megoldás (elvárt mátrix): 
```text
        4   5
     --------
   1|   4   5
   2|   8  10
   3|  12  15
```

### Megoldási sablon
```cpp
int** szorzat(int* oszlop, int no, int* sor, int ns);
```

---

## 2. Feladat – kever

**Feladat:**  
Definiálja a `void kever(std::string& s)` függvényt, ami véletlenszerű sorrendbe állítja az `s` string karaktereit!

Példa:
```cpp
teszt("abcdef");
Eredeti szoveg: abcdef
Keverés OK
```

### Megoldási sablon
```cpp
void kever(std::string& s);
```

---

## 3. Feladat – számtani

**Feladat:**  
Készítse el az `int szamtani(int a0, int d, bool uj)` függvényt! Ha az `uj` paraméter értéke `true`, akkor a függvény felkészül az `an+1 = an + d` képletű számtani sorozat elemeinek előállítására, és visszatérési értéke `a0` lesz. Ha az `uj` paraméter értéke `false`, akkor a korábban meghatározott sorozat következő elemének értékét szolgáltatja.

Példahasználat:
```cpp
std::cout << szamtani(0, 1, true);
for(int i=0; i<9; i++) {
    std::cout << ' ' << szamtani(0, 1, false);
}
std::cout << std::endl;
```

Kimenet:
```text
0 1 2 3 4 5 6 7 8 9
```

### Megoldási sablon
```cpp
int szamtani(int a0, int d, bool uj);
```

---

## 4. Feladat – capsLocked

**Feladat:**  
Definiálja azt a `bool capsLocked(std::string s)` függvényt, ami igaz értékkel tér vissza, ha a paraméterként neki átadott `s` karakterlánc

- tartalmaz legalább egy betűt és  
- amennyiben az első karakter betű, akkor az kisbetű,  
- az összes ezt követő karakter nem kisbetű.  

Betűk alatt az angol ábécé betűit értjük, a magyar ékezetes betűkkel nem kell foglalkozni.

Példák:
```cpp
std::cout << (capsLocked("pISTA")?"igen":"nem") << std::endl; // igen
std::cout << (capsLocked("Pista")?"igen":"nem") << std::endl; // nem
```

### Megoldási sablon
```cpp
bool capsLocked(std::string s);
```

---

## 6. Feladat – gp

**Feladat:**  
Definiálja a `double* gp(double a1, double q, int n)` függvényt, mely visszatér egy `n` elemű tömbbel, amelynek elemei az `a1` értékű első taggal rendelkező, `q` kvóciensű mértani sorozat egymást követő tagjai.

Példa:
```cpp
printAndClear(gp(3, 3, 5), 5);
```

Kimenet:
```text
3 9 27 81 243
```

### Megoldási sablon
```cpp
double* gp(double a1, double q, int n);
```

---

## 7. Feladat – rightAlign

**Feladat:**  
Készítse el azt a `void rightAlign(const std::string& fileName)` függvényt, mely a paraméterként kapott nevű fájl sorait jobbra igazítva jeleníti meg a képernyőn! Keresse meg a leghosszabb sort, és annak jobb széléhez igazítsa az összes többi sor tartalmát!

Példa:
```cpp
rightAlign("file1.txt");
```
File tartalma: 
```text
A
AA
AAA
AAAA
AAAAA
AAAAAA
```

Kimenet:
```text
     A
    AA
   AAA
  AAAA
 AAAAA
AAAAAA
```

### Megoldási sablon
```cpp
void rightAlign(const std::string& fileName);
```

---

## 8. Feladat – draw

**Feladat:**  
Definiálja azt a `void draw(const std::string& commands)` függvényt, ami egy karakterláncot fogad! Ennek betűi parancsok arra vonatkozóan, hogy merre kell mozgatni egy tollat a képernyőn. A karakterlánc csak az `U` (fel), `D` (le), `R` (jobbra) és `L` (balra) betűket tartalmazza. Kezdetben a toll a képernyő bal felső sarkában áll. Feltételezheti, hogy a toll a képernyő bal felső sarkától csak jobbra és lefelé távolodik majd el, legfeljebb 10 karakterpozícióval. Minden olyan helyen, ahol a toll tartózkodik, egy csillag karakternek kell megjelennie!

Példa:
```cpp
draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");
```

Kimenet:
```text
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
```

### Megoldási sablon
```cpp
void draw(const std::string& commands);
```

---


## 9. Feladat – getArea

**Feladat**  

Definiálja a `double getArea(int n, double l)` függvényt, ami egy n oldalú, l oldalhosszúságú szabályos sokszög területét szolgáltatja!

Egy lehetséges ötlet a megoldáshoz: ha a sokszög minden csúcsából húz egy szakaszt a sokszög középpontjához, akkor annyi egyforma háromszögre bontja a sokszöget, amennyi csúcsa van a sokszögnek. A háromszögek két oldalának hossza a sokszög köré írt kör sugarával egyezik meg, a harmadik oldal hossza a sokszög oldalainak hossza. A sugarat meghatározhatja a következőképpen, ahol `l` a sokszög oldalainak hossza, `n` pedig az oldalak száma.

Ha ismert egy háromszög három oldalának hossza, akkor területe meghatározható a Hérón-képlettel, ahol `s` a félkerület, `a`, `b` és `c` a háromszög oldalhosszai.

*Hérón-képlet: T = s ( s − a ) ( s − b ) ( s − c )*

**Példa**

```cpp
std::cout << std::setprecision(2) << getArea(4, 2) << std::endl;
```

Elvárt eredmény:
```text
4
```

### Megoldási sablon

```cpp
double getArea(int n, double l);
```

---

## 10. Feladat – decode (prefix kód visszafejtése)

**Feladat**  

Definiálja azt a `void decode(const prefixPair* codeWords, const std::string& message)` függvényt, melynek célja egy prefix kóddal kódolt szöveg visszafejtése és szavainak szabvány kimenetre nyomtatása egymás alá! 

A prefix kódok olyan kódszavakkal helyettesítik az eredeti üzenet szavait, melyekre teljesül a prefix tulajdonság, azaz egyik kódszó sem kezdődik egyetlen másik kódszóval sem. A kódszavakat a `codeWords` paraméter adja meg egy `prefixPair` típusú struktúrákból álló láncolt lista formájában. Ennek `codeWord` tagja egy kódszó (pl. `"0"`), `text` tagja pedig a kódolt szöveg (pl. `"Samsung"`). A `next` nevű tag a következő listaelemet címzi. A `decode` függvény második, `message` paramétere a kódolt üzenetet adja meg.

A listaelemek típusa:

```cpp
struct prefixPair {
    std::string codeWord;
    std::string text;
    prefixPair* next;
};
```

**Példa**

```cpp
prefixPair* codeWords = nullptr;
append(codeWords, "0", "Samsung");
append(codeWords, "10", "Xiaomi");
append(codeWords, "11", "Apple");
decode(codeWords, "01011100");
clear(codeWords);
```

Elvárt kimenet:
```text
Samsung
Xiaomi
Apple
Xiaomi
Samsung
```

### Megoldási sablon

```cpp
void decode(const prefixPair* codeWords, const std::string& message);
```

---

## 11. Feladat – printGantt

**Feladat**  

Definiálja a `void printGantt(int mtx[][2], int n)` függvényt, ami egyszerűsített (csak a feladatok időbeli ütemezését megjelenítő) Gantt-diagramot nyomtat a szabványos kimenetre! Az `n` sorból és `2` oszlopból álló `mtx` mátrix minden sora megadja, hogy a diagram sávjai a képernyő milyen indexű oszlopában kezdődnek és fejeződnek be (tehát ezek zárt intervallumok).

**Példa**

```cpp
int mtx[][2] = {
    {0, 3},
    {1, 5},
    {3, 9}
};
int n = sizeof(mtx)/sizeof(mtx[0]);
printGantt(mtx, n);
```

Elvárt kimenet:
```text
****
 *****
   *******
```

### Megoldási sablon

```cpp
void printGantt(int mtx[][2], int n);
```

---

## 12. Feladat – total (összesítés név szerint)

**Feladat**  

Készítse el azt a `void total(const Product* p, int n)` függvényt, ami a `Product` típusú elemekből álló, `n` elemű struktúratömb elemeit dolgozza fel! A struktúra már előzetesen definiált a következőképpen:

```cpp
struct Product {
    std::string name;
    int pcs;
};
```

A struktúra egy termék nevét (`name`) és darabszámát (`pcs`) tartalmazza. A struktúratömb olyan struktúrákból áll, melyek közül akár több is tartalmazhatja ugyanannak a terméknek a nevét, akár eltérő darabszámokkal. A függvény feladata összegezni az egyes termékekből rendelkezésre álló mennyiségeket, és olyan sorrendben megjeleníteni az eredményt a szabvány kimeneten, amilyen sorrendben a termékek először felbukkantak a tömbben.

**Példa**

```cpp
Product p[] = {
    {"alma", 3},
    {"barack", 2},
    {"alma", 4},
    {"citrom", 1},
    {"barack", 1}
};
int n = sizeof(p)/sizeof(*p);
total(p, n);
```

Elvárt kimenet:
```text
alma 7
barack 3
citrom 1
```

### Megoldási sablon

```cpp
void total(const Product* p, int n);
```

---

## 13. Feladat – center (középre igazított kiírás)

**Feladat**  

Definiálja a `void center(const std::string& fileName)` függvényt, ami megkeresi a `fileName` nevű szövegfájl leghosszabb sorát, majd ilyen széles oszlopban középre igazítva kinyomtatja valamennyi sor tartalmát. Ha a középre igazítás során nem lehet pontosan ugyanannyi szóközt hagyni a sor előtt és mögött, akkor **előtte legyen eggyel kevesebb**!

**Példa**

```cpp
center("file1.txt");
```

Elvárt eredmény (pl. ilyen egyenletlen):
```text
  A
  AA
 AAA
 AAAA
AAAAA
AAAAAA
```

### Megoldási sablon

```cpp
void center(const std::string& fileName);
```

---

## 14. Feladat – arithmeticProgression (kétirányban láncolt számtani lista)

**Feladat**  

Definiálja a `Number* arithmeticProgression(double a1, double d, int n)` függvényt, ami `n` listaelemből álló, két irányban láncolt listát hoz létre az `a1` kezdő taggal rendelkező, `d` differenciájú számtani sorozat első `n` tagjának tárolására! (A teszt során a tagokat oda-vissza kiírjuk, hogy ellenőrizzük a láncolás helyességét.)

A `Number` struktúra már definiált a következőképpen, ezzel nem kell külön foglalkoznia:

```cpp
struct Number {
    double value;
    Number* next;
    Number* prev;
};
```

**Példa**

```cpp
printForwardReverseFree(arithmeticProgression(1, 2, 3));
```

Elvárt kimenet:
```text
1 3 5 3 1
```

### Megoldási sablon

```cpp
Number* arithmeticProgression(double a1, double d, int n);
```

---

## 15. Feladat – splitter (szöveg feldarabolása listába)

**Feladat**  

Definiálja a `ListItem* splitter(const std::string& text, char separator)` függvényt, ami a `separator` karakterek mentén több szóra bontja a `text` szöveget, és az így előálló szavakat a `ListItem` típusú, előzetesen már definiált struktúrákból álló, egy irányban láncolt listában helyezi el. A visszatérési érték a lista horgonya legyen! 

A listaelem szerkezete a következő:

```cpp
struct ListItem {
    std::string word;
    ListItem* next;
};
```

**Példa**

```cpp
printAndDelete(splitter("This is the beginning of a beautiful friendship.", ' '));
```

Elvárt kimenet:
```text
This
is
the
beginning
of
a
beautiful
friendship.
```

### Megoldási sablon

```cpp
ListItem* splitter(const std::string& text, char separator);
```


---

## 16. Feladat – feltoltNagybetu, cserel

**Feladat:**  

Írjon egy C/C++ programot, amely 2 db felhasználói függvényt használ, amelyeket meg is kell írnia.

Az egyik az `int feltoltNagybetu(char szovegTb[])`, amely feltölt egy karakter típusú tömböt (1. paraméter)
alfanumerikus karakterekkel / szavakkal az ENTER billentyű leütéséig, vagy maximum 50 db karakterig.
Ha a felhasználó kisbetűt adna meg, azt alakítsa át nagybetűre.
A tömb hosszát szimbolikus állandóval állítsa be.
Szöveges bekérési információk és hibaüzenetek nem kellenek!!!
A függvény visszatérési értéke a feltöltött tömb hossza legyen.

A másik függvény a `void cserel(char szovegTb[], int hossz)`, pedig a feltöltött tömb (1. paraméter)
elemeit cserélje le a következőképpen.

A tömb szavainak a közepét (mediánját) helyettesítse számokkal, 1-től indulva növekvő iránnyal úgy,
hogy a lépésköz 1 legyen.
A páratlan karakterű szavakban csak 1 db, míg a páros karakterűekben 2 db karaktert kell lecserélni!
Pl.:  
- Paratlant ⇒ `PARA1LANT`  
- Parost ⇒ `PA22ST`  

A programot nem kell felkészíteni a 9-nél több szót tartalmazó szövegekre!
Ezek után, a fentiek szerint módosított tömb tartalmát írja is ki.
A `cserel` függvény 2. paramétere a `feltoltNagybetu` függvény visszatérési értéke.

**For example:**

Input:
```text
Alma Korte Szilva Paratlant
```

Result:
```text
A11A KO2TE SZ33VA PARA4LANT
```

Input:
```text
#Alma @Korte "Szilva &Paratlant
```

Result (változatlanul csak a szavakra hat):
```text
A11A KO2TE SZ33VA PARA4LANT
```

### Megoldási sablonok

```cpp
int feltoltNagybetu(char szovegTb[]);
void cserel(char szovegTb[], int hossz);
```

---

## 17. Feladat – lastFirstName

**Feladat:**  

Írjon egy `string* lastFirstName()` függvényt, amelynek a visszatérési értéke egy dinamikus tömb, amelyben az alábbi átalakításokon átesett szerzők nevei találhatóak.

Az átalakítandó szerzők vezetéknevét és keresztneveit (több is lehet) egy-egy adat-sor tartalmazza,
amiket a billentyűzetről kap a függvény.
A nevek a katalogizálás szabályait követik, azaz a vezetéknév után van egy vessző,
egy szóköz, majd következnek a keresztnevek szintén 1-1 szóközzel elválasztva.

A legelső adatsorban csak egy pozitív egész szám található, amely az írók számát adja meg,
amíg a további sorok egy-egy szerzőt azonosítanak a következőképpen:

```text
vezetéknév,  1._keresztnév  2._keresztnév  …  n._keresztnév
```

Pl.:
```text
Adams, Douglas Noel
...
Zahn, Timothy
```

Az adat-sorok szerzőit tárolja el egy dinamikus tömbbe (visszatérési érték)!
Ezek után alakítsa át ezen tömb tartalmát úgy, hogy a szerzők nevei a következő mintát kövessék:

```text
1._keresztnév  2._keresztnév  …  n._keresztnév  vezetéknév
```

Azaz a vezetéknév kerüljön „hátra” és a teljes név a keresztnevekkel kezdődjön 1-1 szóközzel elválasztva.

**For example:**

```cpp
string* szerzok = lastFirstName();
if(szerzok) {
    for(int i = 0; i < 8; i++) {
        cout << szerzok[i] << endl;
    }
    delete [] szerzok;
    szerzok = 0;
}
```

Input:
```text
8
Adams, Douglas Noel
Asimov, Isaac
Heinlein, Robert Anson
Clarke, Arthur Charles
Bradbury, Ray Douglas
King, Stephen Edwin
Tolkien, John Ronald Reuel
Zahn, Timothy
```

Result:
```text
Douglas Noel Adams
Isaac Asimov
Robert Anson Heinlein
Arthur Charles Clarke
Ray Douglas Bradbury
Stephen Edwin King
John Ronald Reuel Tolkien
Timothy Zahn
```

### Megoldási sablon

```cpp
std::string* lastFirstName();
```

---

## 18. Feladat – raceResult

**Feladat:**  

Van egy 3 állomásos sportverseny-sorozat, amelyben a versenyzők minden megmérettetés
után részpontokat kapnak. Így a sorozat végén a sportolók mindegyike 3 db részpontszámmal rendelkezik.

Írjon egy `string raceResult(int *bR)` függvényt, amelynek a visszatérési értéke
a legnagyobb részpontszámot kapó versenyző azonosítója (licence) legyen.
(A feladat könnyítése érdekében tételezzük fel, hogy csak 1 db legnagyobb részpontszám van!)

A célba érkezett versenyzők számát, azonosítójukat (licence) és a részpontokat
egy-egy adatsor tartalmazza, amiket a billentyűzetről kap a függvény.
A legelső adatsorban csak egy pozitív egész szám található, amely a célba érkezettek száma.
A további, minden egyes adat-sor egy-egy sportolót azonosít a következők szerint:

```text
licence 1._részpont 2._részpont 3._részpont
```

Az adatokat szóközök választják el egymástól! Pl.:
```text
df-572ki 1234 1456 1750
…
do-565yy 1500 1550 2000
```

Az adat-sor elemeit tárolja el egy struktúra-tömbbe, amihez használja a megadott
`struct athletes` típust!
A struktúra-tömböt a dinamikus memóriába hozza létre!
A versenyzők legjobb részpontjait az `int bestScore` illetve, hogy ezt melyik versenyen érték el,
azt az `int bestRace` tagváltozókba mentsék el.
A 2. paraméterben a függvény pedig adja vissza annak az állomásnak a számát, ahol a legjobb
részpontszámot érte el az a versenyző, akinek a licence a visszatérési értékben szerepel.

**For example:**

```cpp
int b_r = 0;
string b_s = raceResult(&b_r);
std::cout << b_s << "\n" << b_r << std::endl;
```

Input:
```text
10
kj-123pu 1100 1001 1102
zt-321hj 1100 1101 1102
tf-341tg 1100 1101 1102
do-565yy 1100 1101 1102
kt-942uu 1100 1000 1102
df-572ki 1100 1101 1002
gh-961ta 1100 5000 1102
nz-789zu 1002 1101 9000
le-888lc 1100 1001 1102
sj-735cx 1100 1101 1102
```

Result:
```text
nz-789zu
3
```

### Megoldási sablon

```cpp
std::string raceResult(int* bR);
```

---

## 19. Feladat – ispalindrome

**Feladat:**  

Készítsen C++ függvényt, amely ellenőrzi egy szövegről, hogy palindróma-e!
Vagyis: a szöveg fordítottja megegyezik-e az eredeti szöveggel!

TIPP: használjon `unsigned int`-et!

**For example:**

```cpp
std::cout << ispalindrome("gorog") << '\n';
```

Elvárt eredmény:
```text
1
```
### Megoldási sablon

```cpp
bool ispalindrome(const std::string& str);
```

---

## 20. Feladat – calcEuclid

**Feladat:**  

Adott 3D koordinátáknak a tömbje. Feladat, hogy minden egyes koordinátához kiszámolja az origótól vett távolságot.

A távolságok egy tömbben egymás után következzenek. A tömb mérete előre ismert.

A feladathoz írjon egy C++ függvényt! Segítségképpen megadtuk a függvény fejlécét. Használja a leimplementált `Coord` struktúrát!

TIPP: emlékeztetőleg az Euklideszi távolság (az origó pont (0,0,0) esetén).  
TIPP2: visszatérésként egy dinamikus tömböt kell lefoglalni.

**For example:**

```cpp
struct Coord coords[2];
coords[0].x = 0.0;
coords[0].y = 0.0;
coords[0].z = 0.0;

coords[1].x = 10.0;
coords[1].y = 5.0;
coords[1].z = 0.0;

double* res = calcEuclid(coords, 2);
for (int i = 0; i < 2; i++) {
    std::cout << res[i] << '\n';
}
delete[] res;
```

Elvárt eredmény:
```text
0
11.1803
```

### Megoldási sablon

```cpp
double* calcEuclid(const Coord* coords, int n);
```

---

## 21. Feladat – IngatlanLista (láncolt lista műveletek)

**Feladat:**  

Ingatlanok értékeit gyűjtjük össze egy láncolt listába.

Egy láncolt lista elemben a következő elemeket tároljuk:

- Terület (négyzetméterben)
- Érték (Ft-ban)

Feladat a láncolt lista struktúra elkészítése (`IngatlanLista`),  
`beszurElejere` művelet elkészítése,  
az ingatlanok által lefedett terület összegzése (`totalArea`)  
és az átlagos ingatlanérték meghatározása (`averageArea`) (az összterület felhasználásával).  
Az átlagnál figyeljen a 0-ás osztóra!

Segítségképpen megadtuk a függvények fejléceit.

**For example:**

```cpp
IngatlanLista* list = nullptr;
list = beszurElejere(nullptr, 10.0, 1000);
list = beszurElejere(list, 5.0, 500);
list = beszurElejere(list, 5.0, 500);
std::cout << totalArea(list) << '\n';
std::cout << averageArea(list) << '\n';
```

Elvárt eredmény:
```text
20
100
```

### Megoldási sablon (a struktúra + műveletek prototípusai)

```cpp
struct IngatlanLista;

IngatlanLista* beszurElejere(IngatlanLista* head, double terulet, int ertek);
double totalArea(const IngatlanLista* head);
double averageArea(const IngatlanLista* head);
```

---


## 22. Feladat – point + compare

**Feladat**  

Hozzon létre `point` névvel egy struktúrát, mely egy síkbeli pontot jelképez.  
Legyen két `double` típusú tagja: `x` és `y`. Valósítson meg

```cpp
double compare(struct point *a, struct point *b, int l)
```

függvényt, ahol `a` és `b` egy-egy `l` elemű tömb.  
A függvény határozza meg az `a` és `b` tömbben szereplő pontsor hasonlóságát, ahol a hasonlóságot az ugyanaz indexen szereplő pontok távolságának **átlaga** adja meg.  
Feltételezheti, hogy `a` és `b` legalább 1 elemű és a két tömb elemszáma megegyezik.

**Példa:**
```cpp
point a[3] = {
    {0.0, 0.0},
    {1.0, 1.0},
    {2.0, 2.0}
};

point b[3] = {
    {0.0, 1.0},
    {1.0, 2.0},
    {2.0, 3.0}
};

double avgDist = compare(a, b, 3);
cout << avgDist << endl;
```

Kimenet:
```text
1
```

### Megoldási sablon

```cpp
struct point {
    double x;
    double y;
};

double compare(struct point* a, struct point* b, int l);
```

---

## 23. Feladat – conv (2D konvolúció egy pont körül)

**Feladat**  

Valósítson meg

```cpp
double conv(double **kernel, double **img, int k_w, int k_h, int x, int y)
```

függvényt, ahol `kernel` és `img` egy-egy két dimenziós tömb,  
`k_w` a kernel első dimenziójának a mérete, `k_h` a kernel második dimenziójának a mérete,  
`x` egy index az `img` tömb első dimenziójához és `y` egy index az `img` tömb második dimenziójához.  

A `conv` függvény számítson **szorzatösszeget** a `kernel` tömb és az `img` tömb egy szelete között.  
Az `img` tömbnek vegyük azt a szeletét, amelynek közepe az `(x, y)` pozíción van és mérete megegyezik a kernel méretével.  

Feltételezheti, hogy az `img` mérete és az `(x, y)` pozíció olyanok, hogy a szorzatösszeg mindig számítható.  
Azaz `img` mérete legalább akkora, mint a kernel mérete és `(x, y)` nem lesz olyan pozíció, hogy a kivágandó szelet „lelógna” az `img` tömbről.  
Továbbá a kernel mérete (`k_w` és `k_h`) mindkét dimenzió mentén **páratlan**, azaz egyértelműen meghatározható `img` azon szelete, melynek `(x, y)` a középpontja.

**Példa:**
```cpp
double kern_arr[3][3] = {
    {1, 0, -1},
    {1, 0, -1},
    {1, 0, -1}
};

double img_arr[5][5] = {
    {1, 1, 2, 2, 3},
    {1, 1, 2, 2, 3},
    {4, 4, 5, 5, 6},
    {4, 4, 5, 5, 6},
    {7, 7, 8, 8, 9}
};

// Tegyük fel, hogy kernelt és img-t megfelelően double**-ré alakítottuk.
// A konvolúció középpontja: (2, 2) → az img közepe

double result = conv(kernel, img, 3, 3, 2, 2);
cout << result << endl;
```

A kiválasztott szelet az img-ben (középen):
```text
1 2 2
4 5 5
4 5 5
```

Szorzatösszeg:
```text
1*1 + 2*0 + 2*(-1) + 4*1 + 5*0 + 5*(-1) + 4*1 + 5*0 + 5*(-1) = (1 + 0 - 2) + (4 + 0 - 5) + (4 + 0 - 5) = -1 + -1 + -1 = -3
```

Kimenet:
```text
-3
```

### Megoldási sablon

```cpp
double conv(double** kernel, double** img, int k_w, int k_h, int x, int y);
```

---

## 24. Feladat – shift (peremelem-eltolás mátrixon)

**Feladat**  

Készítsen

```cpp
double** shift(double **mtx, int w, int h)
```

függvényt, ahol `mtx` egy kétdimenziós tömb, `w` az `mtx` első dimenziójának hossza,  
és `h` az `mtx` második dimenziójának hossza. A függvény visszatérési értéke legyen `mtx` tömbbel megegyező méretű tömb.  

A kimeneti tömb az `mtx` értékeit tartalmazza, azzal a különbséggel, hogy a tömb **szélein** (első sor, utolsó sor, első oszlop, utolsó oszlop) található elemeket az óramutató járásával megegyező irányba eggyel arrébb mozgatja.  
Feltételezheti, hogy `w` és `h` értéke egyaránt legalább 2.

**Példa:**
```text
1   2   3
4   5   6
7   8   9
10  11  12
```

Kimenet:
```text
4   1   2
7   5   3
10  8   6
11 12   9
```

### Megoldási sablon

```cpp
double** shift(double** mtx, int w, int h);
```

---

## 25. Feladat – silu (Sigmoid Linear Unit)

**Feladat**  

Valósítson meg **SiLU (Sigmoid Linear Unit)** függvényt a következők szerint.  

Legyen

```cpp
double* silu(double *data, int data_size)
```

ahol `data` egy `data_size` méretű tömb.  
A tömb minden eleme esetén alkalmazza a SiLU függvényt, és visszatérési értékként egy `data_size` méretű tömböt adjon, amely a SiLU függvény által adott értékeket tartalmazza a `data` tömb szerinti sorrendben.

A SiLU definíciója:

```text
silu(x) = x * sigmoid(x)
```

ahol a logisztikus szigmoid függvény:

```text
sigmoid(x) = 1 / (1 + e^{-x})
```

Létezik egy `E` nevű szimbolikus állandó, amelynek értékét használja fel az Euler-féle szám alkalmazásához.

**Példa:**
```cpp
data = [-2.0, -1.0, 0.0, 1.0, 2.0]
data_size = 5
```

Kimenet:
```text
[-0.238406, -0.268941, 0, 0.731059, 1.761594]
```

### Megoldási sablon

```cpp
double* silu(double* data, int data_size);
```

---

## 26. Feladat – stat (betűgyakoriság angol ábécére)

**Feladat**  

Hozzon létre

```cpp
int* stat(std::string s)
```

függvényt, ahol `s` egy angol nyelvű szöveget tartalmazó string.  
A függvény készítsen statisztikát arról, hogy az angol ábécé egyes betűi hányszor fordulnak elő a bemeneti `s` szövegben.  

Az ábécé **kis- és nagybetűi között ne tegyen különbséget**, és az ábécén kívüli karaktereket vegye figyelmen kívül.  
A visszatérési érték egy olyan tömb legyen, melynek az első eleme megadja, hogy az `'a'` betűből hány darab található a szövegben, a második eleme megadja, hogy `'b'` betűből hány darab volt, és így tovább, egészen a `'z'` betűig bezárólag.

**Példa:**
```cpp
string text = "Hello World!";
int* freq = stat(text);

for (int i = 0; i < 26; i++) {
    cout << char('a' + i) << ": " << freq[i] << endl;
}

delete[] freq;   // felszabadítás!
```

```text
a: 0
b: 0
c: 0
d: 1
e: 1
f: 0
g: 0
h: 1
i: 0
j: 0
k: 0
l: 3
m: 0
n: 0
o: 2
p: 0
q: 0
r: 1
s: 0
t: 0
u: 0
v: 0
w: 1
x: 0
y: 0
z: 0
```

### Megoldási sablon

```cpp
int* stat(std::string s);
```

---

## 27. Feladat – uploading, writesOut

**Feladat**  

Írjon egy programot, amely 2 db felhasználói függvényt használ.

Az egyik a

```cpp
double uploading(double up_bl[])
```

amely 6 db negatív lebegőpontos számot kér be úgy, hogy azokat egy tömbbe tárolja le (1. paraméter).  
A tömb hosszát szimbolikus állandóval állítsa be.  
A tárolás csak akkor jöjjön létre, ha a szám `-10`-nél **nagyobb**!  
Ha az adott érték nem teljesíti a rá vonatkozó feltételeket, akkor helyette új számot kell bekérni.  
A bekérési folyamatnak addig kell folytatódnia, amíg a tömb teljes feltöltése meg nem történik.  
Bekérési információk és hibaüzenetek kiírása **nem kell**!

A feltételek teljesülése esetén az `uploading` nevű függvény határozza meg a tömbbe letárolt értékek
harmadik hatványainak a különbségét.  
(Azaz, az 1. szám hatványából vonja ki a 2. szám hatványát, majd ebből a 3. szám hatványát és így tovább.)  
Ezek után ezzel a számmal térjen vissza (visszatérési érték).  
A különbség tizedespontosságának a meghatározását bízza a fordítóra.

A másik függvény a

```cpp
void writesOut(double diff)
```

pedig írja ki, hogy az `uploading` nevű függvény visszatérési értékének (amit az 1. paraméterben vesz át) **egész része hány számjegyű**.  
A kiírás a példában látott tagolással és szövegezéssel történjen.

**Például:**
```text
-1 -2 -3 -4 -5 -6
```

Kimenet:
```text
(-1)^3 - (-2)^3 - (-3)^3 - (-4)^3 - (-5)^3 - (-6)^3
= (-1) - (-8) - (-27) - (-64) - (-125) - (-216)
= -1 + 8 + 27 + 64 + 125 + 216
= 439
```

### Megoldási sablonok

```cpp
double uploading(double up_bl[]);
void writesOut(double diff);
```

---

## 28. Feladat – charLoad, change (kisbetűk nagybetűsítése + számlálás)

**Feladat**  

Írjon egy programot, amely 2 db felhasználói függvényt használ.

Az egyik az

```cpp
int charLoad(char c_bk[])
```

amely feltölt egy karakter tömböt (1. paraméter) ékezet nélküli betűkkel az ENTER billentyű leütéséig, vagy maximum 256 db karakterig.  
Bekérési információk és hibaüzenetek kiírása nem kell! A tömb hosszát szimbolikus állandóval állítsa be.  
A függvény visszatérési értéke a feltöltött tömb hossza legyen.

A másik függvény a

```cpp
void change(char up_bl[], int lg)
```

pedig a feltöltött tömb (1. paraméter) kisbetűit cserélje le a nagybetűs alakjára.  
Ezek után a fentiek szerint módosított tömb tartalmát írja is ki.  
Továbbá a következő sorban jelenítse meg, hogy az **eredeti** tömbben hány db nagybetű volt, a példában látott tagolással és szövegezéssel.  
A `change` nevű függvény 2. paramétere a `charLoad` függvény visszatérési értéke.

**Példa:**
```text
AbCdEfGh
```

Kimenet:
```text
ABCDEFGH
Original uppercase count: 4
```

### Megoldási sablonok

```cpp
int charLoad(char c_bk[]);
void change(char up_bl[], int lg);
```

---

## 29. Feladat – colorSearch (futócipő színek)

**Feladat**  

Egy adat-file első sorában csak egy pozitív egész szám található, amely a további sorok számát jelenti, amelyek egy-egy futócipő márkát azonosítanak a következők szerint:

```text
Márkanév  1._szín  2._szín  3._szín
```

Az adatokat szóközök választják el egymástól! Pl.:
```text
Adidas  blue  yellow  gray
…
Nike    red   green   white
```

Írjon egy

```cpp
int colorSearch(std::string fbe, std::string *brand)
```

függvényt, amelynek a visszatérési értéke azt mutatja meg, hogy **összesen hány márkának van `green` színű cipője** az 1. paraméterben megadott adatállományban.

Ezen állomány létezését ellenőrizni kell! Ha az adat-file nem létezik, akkor a

```text
Sikertelen file-nyitás!
```

karaktersorozat is jelenjen meg a monitoron! A hibaüzenet formátumát a példa is mutatja! (Ekkor a márkák száma természetesen nulla!)

Az adat-file elemeit tárolja el egy struktúratömbbe, amihez használja a megadott `struct running_shoes` típust!  
A struktúratömböt a dinamikus memóriába hozza létre!  
Ha az adott márkának létezik `green` színű cipője, akkor a `bool color_green` változóba az igaz, ha nem létezik, akkor a hamis érték kerüljön.  
Ezek **összegzése legyen a visszatérési érték**!

A 2. paraméterben a függvény pedig adja vissza annak a márkának a nevét, amelyik az adatállomány **utolsó sorában** található.

**Példa:**
```text
5
Adidas blue yellow gray
Nike red green white
Puma black white gray
Asics green yellow blue
Reebok red blue green
```

Kimenet:
```text
Green shoes brands: 3
Last brand in file: Reebok
```

### Megoldási sablon

```cpp
int colorSearch(std::string fbe, std::string* brand);
```

---

## 30. Feladat – fullNameSort (teljes név szerinti rendezés, fájlból-fájlba)

**Feladat**  

Írjon egy

```cpp
std::string* fullNameSort(std::string fbe, std::string fki)
```

függvényt, amely kiírja az alábbi rendezésen átesett szerzők neveit egy kimeneti-file-ba (2. paraméter).  
Továbbá a visszatérési értéke az a dinamikus tömb legyen, amely tartalmazza a rendezéseket.

A szerzők vezetéknevét és keresztneveit (több is lehet) egy adat-file (1. paraméter) tartalmazza úgy,
hogy a nevek a katalogizálás szabályait követik. Azaz a vezetéknév után van egy vessző,
egy szóköz, majd következnek a keresztnevek szintén 1-1 szóközzel elválasztva.

Tehát így:
```text
vezetéknév,  1._keresztnév  2._keresztnév  …  n._keresztnév
```

Pl.:
```text
Adams, Douglas Noel
…
Zahn, Timothy
```

Az adat-file elérhetőségét ellenőrizni kell, ha nem nyitható meg, akkor a képernyőn
a

```text
Sikertelen file-nyitás!
```

karaktersorozat legyen olvasható!  
Ha pedig a kimeneti-file-t nem lehet létrehozni, akkor a

```text
Háttértár hiba!
```

karaktersorozat íródjon ki a monitorra!

Továbbá ezen állomány első sorában csak egy pozitív egész szám található, amely az írók számát adja meg, amíg a további sorok egy-egy szerzőt azonosítanak a fent leírtak alapján.  
Az adat-file szerző-sorait tárolja el egy dinamikus tömbbe (visszatérési érték)!

Ezek után alakítsa át ezen tömb tartalmát úgy, hogy a szerzők a **teljes nevükre nézve ABC sorrendbe** legyenek rendezve.

**Példa:**
```text
8
Adams, Douglas Noel
Asimov, Isaac
Heinlein, Robert Anson
Clarke, Arthur Charles
Bradbury, Ray Douglas
King, Stephen Edwin
Tolkien, John Ronald Reuel
Zahn, Timothy
```

Kimenet:
```text
Arthur Charles Clarke
Douglas Noel Adams
Isaac Asimov
John Ronald Reuel Tolkien
Ray Douglas Bradbury
Robert Anson Heinlein
Stephen Edwin King
Timothy Zahn
```

### Megoldási sablon

```cpp
std::string* fullNameSort(std::string fbe, std::string fki);
```

---

## 31. Feladat – sinTetel (szinusztétel háromszögekre, fájlból)

**Feladat**  

Írjon egy

```cpp
double** sinTetel(std::string fbe)
```

függvényt, amelynek a visszatérési értéke egy **5 × 3-as dinamikus mátrix**, amely 5 db általános háromszög 2 db szögét és 1 db oldalát tartalmazza, a lenti meghatározások alapján.

A háromszögek 3. oldalának és a további 2 szögének a kiszámításához szükséges adatokat egy adat-file tartalmazza, amelynek a létezését ellenőrizni kell! A hibaüzenet formátumát a példa is mutatja. Ennek az állománynak az azonosítója lesz a `sinTetel` nevű függvény paramétere.

Az adat-file egy-egy sora egy általános háromszög három adatát tartalmazza, ezek:

```text
az_1._oldal_(b)  a_2._oldal_(a)  a_2._oldallal_szembeni_szög_fokban_(alfa)
```

Az adatokat szóköz választja el egymástól! Pl.:

```text
40 80 30
...
40 70 45
```

Az adat-file soronkénti elemeit szintén egy **5 × 3-as dinamikus mátrixba** tárolja el, és ezen adatokból számítsa ki a 3. oldalt (`c`) és a maradék kettő szöget (`beta`, `gamma`) az alábbi képletek segítségével:

```text
beta  = asin(b / a * sin(alfa * M_PI / 180)) / M_PI * 180
gamma = 180 - alfa - beta
c     = sin(gamma * M_PI / 180) / sin(alfa * M_PI / 180) * a
```

A szögeket (`beta`, `gamma`) és a 3. oldalt **ebben a sorrendben** kell tárolni a visszatérési értékként kezelt `double` mátrixban:  
sor: `(beta, gamma, c)`.

A dinamikus mátrixok méreteit szimbolikus állandókkal állítsa be.  
A szögek és a 3. oldal tizedespontosságának a meghatározását bízza a fordítóra.

Ha az adat-file nem létezik, akkor a monitoron a

```text
Sikertelen file-nyitás!
```

karaktersorozat jelenjen meg!

**For example:**

```cpp
double** szkb = sinTetel("Bfk_alfa.txt");
if(szkb) {
    for(int i = 0; i < 5; i++) {
        std::cout << szkb[i][0] << " " << szkb[i][1] << " " << szkb[i][2] << std::endl;
    }
    for(int i = 0; i < 5; i++) {
        delete [] szkb[i];
    }
    delete [] szkb;
    szkb = 0;
}
```

Lehetséges kimenet (példaként):

```text
14.4775 135.522 56.0503
41.6156 53.3844 32.2288
60 60 40
23.8323 111.168 52.7517
53.1301 36.8699 24
```

Hibás fájlnév esetén:

```cpp
double** szkb = sinTetel("NoBfk_alfa.txt");
if(szkb) {
    for(int i = 0; i < 5; i++) {
        std::cout << szkb[i][0] << " " << szkb[i][1] << " " << szkb[i][2] << std::endl;
    }
    for(int i = 0; i < 5; i++) {
        delete [] szkb[i];
    }
    delete [] szkb;
    szkb = 0;
}
```

Kimenet:
```text
Sikertelen file-nyitás!
```

### Megoldási sablon

```cpp
double** sinTetel(std::string fbe);
```

---

## 32. Feladat – infuse, outwrite (gyökk szorzata + páros/páratlan egészrész)

**Feladat**  

Írjon egy programot, amely 2 db felhasználói függvényt használ.

Az egyik a

```cpp
double infuse(double in_bk[])
```

amely **5 db pozitív lebegőpontos számot kér be** úgy, hogy azokat egy tömbbe tárolja le (1. paraméter).  
A tömb hosszát szimbolikus állandóval állítsa be.  
A tárolás csak akkor jöjjön létre, ha a szám **256-nál kisebb**!  
Ha az adott érték nem teljesíti a rá vonatkozó feltételeket, akkor helyette új számot kell bekérni.  
A bekérési folyamatnak addig kell folytatódnia, amíg a tömb teljes feltöltése meg nem történik.  
Bekérési információk és hibaüzenetek kiírása nem kell!

A feltételek teljesülése esetén az `infuse` nevű függvény határozza meg a tömbbe letárolt értékek **harmadik gyökeinek a szorzatát**.  
(Azaz, az 1. szám harmadik gyökét szorozza meg a 2. szám harmadik gyökével, majd ezt a 3. szám harmadik gyökével és így tovább.)  
Ezek után ezzel a számmal térjen vissza (visszatérési érték).  
A tizedespontosság meghatározását bízza a fordítóra.

A másik függvény a

```cpp
void outwrite(double root)
```

pedig írja ki, hogy az `infuse` nevű függvény visszatérési értékének (amit az 1. paraméterben vesz át) **egész része páros vagy páratlan**.  
A kiírás a példában látott tagolással és szövegezéssel történjen.

**Példa:**
```text
8
27
64
125
216
```

Kimenet:
```
Szorzatuk: 2 × 3 × 4 × 5 × 6 = 720
Infuse: 720
Outwrite: The integer part is even.
```

### Megoldási sablonok

```cpp
double infuse(double in_bk[]);
void outwrite(double root);
```

---

## 34. Feladat – sizeSearch (bringás cipőméretek)

**Feladat**  

Egy adat-file első sorában csak egy pozitív egész szám található, amely a további sorok számát jelenti, amelyek egy-egy bringás cipő márkát azonosítanak a következők szerint:

```text
Márkanév  alsó_mérethatár  felső_mérethatár
```

Az adatokat szóközök választják el egymástól! Pl.:

```text
Sidi     40.5   45.5
...
Shimano  35.75  40.25
```

Írjon egy

```cpp
int sizeSearch(std::string fbe, double my_size, std::string* brand)
```

függvényt, amelynek a visszatérési értéke azt mutatja meg, hogy **összesen hány márkából nem tudnánk cipőt választani**, az 1. paraméterben megadott adatállomány alapján.  
A számunkra szükséges méretet a 2. paraméter tartalmazza.

Ezen állomány létezését ellenőrizni kell! Ha az adat-file nem létezik, akkor a

```text
Sikertelen file-nyitás!
```

karaktersorozat is jelenjen meg a monitoron! (Ekkor a márkák száma természetesen nulla.)

Az adat-file elemeit tárolja el egy struktúra-tömbbe, amihez használja a megadott `struct bike_shoes` típust!  
A struktúra-tömböt a dinamikus memóriába hozza létre!  
Ha az adott márkának létezik számunkra megfelelő méretű cipője, akkor a `bool size_OK` változóba az igaz, ha nem létezik, akkor a hamis érték kerüljön.  
Ezek összegzésének a **komplementere** (ellentettje) legyen a visszatérési érték!  
(Komplementer halmaz = kiegészítő halmaz a teljes halmazra nézve.)

### Megoldási sablon

```cpp
int sizeSearch(std::string fbe, double my_size, std::string* brand);
```

---

## 35. Feladat – lastLetterSort (rendezés a teljes név utolsó karaktere szerint, fordítva)

**Feladat**  

Írjon egy

```cpp
std::string* lastLetterSort(std::string fbe, std::string fki)
```

függvényt, amely kiírja az alábbi rendezésen átesett szerzők neveit egy kimeneti-file-ba (2. paraméter).  
Továbbá a visszatérési értéke az a dinamikus tömb legyen, amely tartalmazza a rendezéseket.

A szerzők vezetéknevét és keresztneveit (több is lehet) egy adat-file (1. paraméter) tartalmazza úgy, hogy a nevek a katalogizálás szabályait követik.  
Azaz a vezetéknév után van egy vessző, egy szóköz, majd következnek a keresztnevek szintén 1-1 szóközzel elválasztva.

Tehát így:

```text
vezetéknév,  1._keresztnév  2._keresztnév  …  n._keresztnév
```

Pl.:

```text
Adams, Douglas Noel
...
Zahn, Timothy
```

Az adat-file elérhetőségét ellenőrizni kell, ha nem nyitható meg, akkor a képernyőn a

```text
Sikertelen file-nyitás!
```

karaktersorozat legyen olvasható!  
Ha pedig a kimeneti-file-t nem lehet létrehozni, akkor a

```text
Háttértár hiba!
```

karaktersorozat íródjon ki a monitorra!

Továbbá ezen állomány első sorában csak egy pozitív egész szám található, amely az írók számát adja meg, amíg a további sorok egy-egy szerzőt azonosítanak a fent leírtak alapján.  
Az adat-file szerző-sorait tárolja el egy dinamikus tömbbe (visszatérési érték)!

Ezek után alakítsa át ezen tömb tartalmát úgy, hogy a szerzők a **teljes nevük utolsó karakterére nézve fordított ABC sorrendbe** legyenek rendezve **úgy, hogy a szerzők teljes nevei is visszafelé legyenek letárolva**.

### Megoldási sablon

```cpp
std::string* lastLetterSort(std::string fbe, std::string fki);
```

---

## 36. Feladat – cosTetel (koszinusz-tétel háromszögekre, fájlból)

**Feladat**  

Írjon egy

```cpp
double** cosTetel(std::string fbe)
```

függvényt, amelynek a visszatérési értéke egy **5 × 3-as dinamikus mátrix**, amely 5 db általános háromszög 1 db oldalát és 2 db szögét tartalmazza, a lenti meghatározások alapján.

A háromszögek 3. oldalának és a további 2 szögének a kiszámításához szükséges adatokat egy adat-file tartalmazza, amelynek a létezését ellenőrizni kell! A hibaüzenet formátumát a példa is mutatja!  
Ennek az állománynak az azonosítója lesz a `cosTetel` nevű függvény paramétere.

Az adat-file egy-egy sora egy általános háromszög három adatát tartalmazza, ezek:

```text
az_1._oldal_(b)  a_2._oldal_(a)  ezen_oldalak_közötti_szög_fokban_(gamma)
```

Az adatokat szóköz választja el egymástól! Pl.:

```text
40 80 30
...
40 70 45
```

Az adat-file soronkénti elemeit szintén egy **5 × 3-as dinamikus mátrixba** tárolja el, és ezen adatokból számítsa ki a 3. oldalt (`c`) és a maradék kettő szöget (`beta`, `alfa`) az alábbi képletek segítségével:

```text
c    = sqrt(a*a + b*b - 2 * a * b * cos(gamma * M_PI / 180))
beta = asin(b / c * sin(gamma * M_PI / 180)) / M_PI * 180
alfa = 180 - gamma - beta
```

A 3. oldalt (`c`) és a szögeket (`beta`, `alfa`) **ebben a sorrendben** kell tárolni a visszatérési értékként kezelt `double` mátrixban.  
A dinamikus mátrixok méreteit szimbolikus állandókkal állítsa be.  
A 3. oldal és a szögek tizedespontosságának a meghatározását bízza a fordítóra.

Ha az adat-file nem létezik, akkor a monitoron a

```text
Sikertelen file-nyitás!
```

karaktersorozat jelenjen meg!

### Megoldási sablon

```cpp
double** cosTetel(std::string fbe);
```

---

## 37. Feladat – decode (egyszerű futáshossz-kód visszafejtése)

**Feladat**  

Definiálja azt a

```cpp
void decode(std::string s)
```

függvényt, ami kikódolva a szabvány kimenetre írja az `s` karakterlánc tartalmát!  
A kikódolás abból áll, hogy a karakterláncban szereplő **számjegy karaktereket követő** egy-egy karaktert pontosan a számjeggyel meghatározott alkalommal ismételve nyomtatja a kimenetre.  
Amelyik jel előtt **nem áll számjegy karakter**, azt változtatás nélkül, egyszer kell nyomtatni.

### Megoldási sablon

```cpp
void decode(std::string s);
```

---

## 38. Feladat – duration (időkülönbség percekben, CSV-ből)

**Feladat**  

Definiálja azt a

```cpp
void duration(std::string fileName)
```

függvényt, ami megnyitja a `fileName` nevű CSV fájlt, melynek első sora fejléc, nem hordoz felhasználható információt, ezért át kell ugrani.  

A második sortól kezdődően minden sor két cellából áll, melyeket vessző (`,`) karakter választ el egymástól.  
A cellák `ÓÓ:PP` formátumban megadott időpontok egy napon belül. Feltételezheti, hogy az első korábbi, mint a második.  

Számolja ki **minden sorra** a két időpont közötti különbséget percekben mérve, és külön sorokban nyomtassa ki a szabvány kimenetre!

(Példa-fájl: `ido1.csv` – itt csak tájékoztatásul volt megadva a feladatban.)

### Megoldási sablon

```cpp
void duration(std::string fileName);
```

---

## 39. Feladat – manhattan (Manhattan-távolság mátrixban)

**Feladat**  

Definiálja azt a

```cpp
void manhattan(int mtx[][COLS], int rows)
```

függvényt, ami a paraméterként kapott `mtx` mátrix minden cellájába beírja annak bal felső cellájától mért **Manhattan-távolságát**, azaz azt, hogy hány jobbra és/vagy lefelé lépéssel lehet az adott cellába eljutni a bal felső saroktól.  
A mátrix `rows` sorból és `COLS` oszlopból áll (ahol `COLS` egy szimbolikus állandó).

### Megoldási sablon

```cpp
void manhattan(int mtx[][COLS], int rows);
```

---

## 40. Feladat – snail (csigavonalas mátrixkitöltés)

**Feladat**  

Definiálja azt az

```cpp
int** snail(int size)
```

függvényt, amely létrehoz egy `size × size` méretű dinamikus mátrixot, majd a bal felső sarkától elindulva az óramutató járásával megegyező irányban, csigavonalban haladva 1-től kezdődően rendre egyesével növekvő számokat ír mindaddig, amíg az összes mezőt ki nem töltötte!  
A visszatérési érték a kitöltött mátrix (vektorokat címző mutatótömb).

### Megoldási sablon

```cpp
int** snail(int size);
```

---

## 41. Feladat – surface (kúp felszíne)

**Feladat**  

Definiálja azt a

```cpp
double surface(double r, double h)
```

függvényt, ami visszaadja az `r` sugarú, `h` magasságú **egyenes, kör alapú kúp felszínét**!  
Használja a matematikai függvénykönyvtárat `pi` értékének meghatározásához!

(Példa a feladatszövegben: `surface(1., 1.)` → `7.58448`.)

### Megoldási sablon

```cpp
double surface(double r, double h);
```

---

## 42. Feladat – parity (bitek paritása)

**Feladat**  

Definiálja azt az

```cpp
int parity(int data)
```

függvényt, melynek visszatérési értéke `0`, ha a `data`-ban szereplő `1`-es értékű bitek száma **páros**, és `1`, ha **páratlan**!

### Megoldási sablon

```cpp
int parity(int data);
```

---

## 43. Feladat – mtx2vec (JPEG-szerű átlós bejárás vektorrá)

**Feladat**  

A JPEG tömörítésnek van egy olyan lépése, amikor egy négyzetes mátrixban lévő számokat adott sorrendben járják végig, és írják egymás után.  
A bejárás olyan, mintha egy tollal húzott egyetlen vonallal kellene összekötni a bal felső sarokból indulva valamennyi számot úgy, hogy mindig **átlós irányokban** próbáljunk haladni (a feladatban adott minta szerint).

Definiálja azt az

```cpp
int* mtx2vec(int** mtx, int n)
```

függvényt, ami a fenti mintának megfelelő sorrendben végigjárja az `n` sorból és oszlopból álló `mtx` négyzetes mátrix elemeit, és egy dinamikusan létrehozott, azonos elemszámú vektorba írja azokat.  
Ez utóbbi címe a visszatérési érték. Az `mtx` technikailag `int*` mutatók tömbje.

### Megoldási sablon

```cpp
int* mtx2vec(int** mtx, int n);
```

---

## 44. Feladat – palindrome (sztring palindróm ellenőrzése)

**Feladat**  

Hozzon létre

```cpp
bool palindrome(std::string str)
```

függvényt, ahol `str` egy bemeneti, csak az angol ábécé kisbetűit tartalmazó szöveg, amelyről el kell dönteni, hogy palindróm vagy sem.  
Döntse el egy szövegről, hogy palindróm vagy sem! Akkor nevezzünk egy szöveget palindrómnak, ha visszafelé olvasva, karakterről karakterre ugyanazt a szöveget kapjuk.

### Megoldási sablon

```cpp
bool palindrome(std::string str);
```

---


## 45. Feladat – printChord (gitárakkord tabulatúrás megjelenítése)

**Feladat**  

Készítsen

```cpp
void printChord(struct chord c)
```

függvényt, amely képes gitár akkordot tabulatúra lejegyzésben megjeleníteni.

Legyen `struct chord` egy olyan struktúra, amely egy akkord esetén tartalmazza:

- Az egyes húrok hangolását (alaphangját), ami egy-egy karakter: `char tune[6]`
- Minden húr esetén, hogy hányadik érintőn (bund-on) kell lefogni.  
  A legelső érintő sorszáma 1, a legutolsó legyen 24.  
  Ha üresen (lefogás nélkül) kell megszólaltatni a húrt, akkor értéke 0.  
  Ha nem kell megszólaltatni a húrt, akkor értéke -1: `int fret[6]`
- Valamint, hogy az adott húrt melyik ujjal kell lefogni a megadott érintőn.  
  Ennek értéke minimum 1 és maximum 4 (mutatóujj, középső ujj, gyűrűsujj és kisujj sorrendben), kivéve, ha az adott húrt nem kell megszólaltatni vagy üresen kell megszólaltatni. Ebben a két esetben értéke -1: `int finger[6]`

A `printChord` függvény a következő minta szerint rajzolja a kimenetre a bemenetként kapott akkordot. Minden egyes sor egy húrnak a leírása. Az 1. sor a `tune[0]` hangolású, `fret[0]` bundon, `finger[0]` ujjal lefogott hangot mutatja, és így tovább. Ebben az esetben csak 6 húros gitárokra kell felkészülni.

- Minden sorban az első karakter legyen az adott húr hangolása, amit egy szóköz követ.  
- Utána, ha az adott húrt üresen kell megszólaltatni, akkor egy `"O"` karakter következik.  
- Ha nem kell megszólaltatni, akkor `"X"` karakter következik.  
- Ha lefogással kell megszólaltatni, akkor még egy szóköz következik.

Ez után következik a lefogások vizualizálása. Két `"|"` karakter közötti területet tekintünk két érintő közötti területnek.  
Ha a kitöltés három `"-"` karakter, akkor az adott érintőnél nem kell lefogni a húrt. Ahol a húrt le kell fogni, ott két `"-"` karakter között az ujj sorszámát tüntetjük fel.

A megjelenítés során csak annyi érintőközt jelenítünk meg, amennyire szükség van, és az utolsó sorban jelezzük, hogy a legelső hányadik érintőt jelenti.  
A szükséges érintőközök számát úgy kaphatjuk meg, ha a `fret` tömb pozitív értékeinek maximuma és minimumának a különbségéhez 1-et hozzáadunk.

```
struct chord c = {{'e', 'b', 'g', 'd', 'a', 'e'}, {-1, 7, 5, 4, 5, -1}, {-1, 4, 3, 1, 2, -1}};
printChord(c);
e X|---|---|---|---|
b  |---|---|---|-4-|
g  |---|-3-|---|---|
d  |-1-|---|---|---|
a  |---|-2-|---|---|
e X|---|---|---|---|
     4
struct chord c = {{'e', 'b', 'g', 'd', 'a', 'e'}, {0, 1, 2, 2, 0, -1}, {-1, 1, 3, 2, -1, -1}};
printChord(c);
e O|---|---|
b  |-1-|---|
g  |---|-3-|
d  |---|-2-|
a O|---|---|
e X|---|---|
```

### Megoldási sablon

```cpp
struct chord {
    char tune[6];
    int  fret[6];
    int  finger[6];
};

void printChord(struct chord c);
```

---

## 46. Feladat – getFirstCurse (legkorábbi káromkodás Tarantino-filmben)

**Feladat**  

Készítsen

```cpp
std::string getFirstCurse(struct curse curses[], int n)
```

függvényt. A `curses` tömb minden eleme 1-1 káromkodást tartalmaz Quentin Tarantino valamely filmjéből.  

Egy káromkodáshoz (`struct curse`) tartozik:

- a film címe, amiben elhangzott,
- a káromkodás szövege,
- valamint annak ideje a filmben.

Az `n` változó megadja, hogy a bemeneti `curses` tömb hány bejegyzést tartalmaz.  
A függvény keresse meg, hogy melyik káromkodás hangzott el **leghamarabb**.  
Visszatérési értéke legyen a leghamarabbi káromkodáshoz tartozó film címe.

Készítse el a káromkodások tárolására alkalmas struktúrát is. Egy `movie` nevű, `std::string` típusú változó tárolja a film címét, amiben elhangzik a káromkodás. A káromkodás szintén `std::string` típusú és a `word` nevet viseli. Végül egy dupla pontosságú lebegőpontos változóban, mely a `time` nevet hordja, tárolja el a káromkodás elhangzásának idejét.

### Megoldási sablon

```cpp
struct curse {
    std::string movie;
    std::string word;
    double      time;
};

std::string getFirstCurse(struct curse curses[], int n);
```

---

## 47. Feladat – enclosingCircle (poligont befoglaló kör)

**Feladat**  

Adottak a `point`, `polygon` és `circle` struktúrák.  
Egy `point` meghatároz egy síkbeli pontot az `x` és `y` tagjával.  
Egy `polygon` leír egy síkbeli poligont, ahol `pts` tömb a poligonhoz tartozó egymás utáni pontokat jelöli, a `numOfPoints` tagja pedig a poligonhoz tartozó pontok számát tárolja.  
Egy `circle` megad egy kört a síkon annak középpontjával (`center` adattag) és sugarával (`radius` adattag).

Készítsen

```cpp
struct circle enclosingCircle(struct polygon p)
```

függvényt, amely meghatároz a paraméterül kapott `p` poligonhoz egy befoglaló kört a következő szerint:

- A keresett kör **középpontját** a poligon pontjainak átlaga adja.
- A kör **sugarát** a kör középpontjának és a poligon azon pontjának a távolsága adja, mely pontja a legtávolabb esik a kör középpontjától.

(A `point`, `polygon`, `circle` struktúrák definíciója előre adott a feladat szerint.)

### Megoldási sablon

```cpp
struct point {
    double x;
    double y;
};

struct polygon {
    point* pts;
    int    numOfPoints;
};

struct circle {
    point center;
    double radius;
};

circle enclosingCircle(polygon p);
```

---

## 48. Feladat – isFart (állatok, amelyek biztosan „finganak”)

**Feladat**  

Készítsen

```cpp
void isFart(std::string dataset)
```

függvényt, ahol `dataset` egy CSV formátumú fájl neve, melynek első oszlopa egy állat nevét, második oszlopa pedig annak a tényét tartalmazza, hogy az adott állat, megfigyelések alapján, szokott-e a végbélnyílásán keresztül bélgázt ereszteni. Ennek értéke a következők valamelyike lehet: `No`, `Maybe`, `Yes`, `Hell Yes`. A fájlban a két tulajdonság **pontosvesszővel** van elválasztva egymástól.

A függvény írja a kimenetre azon állatok nevét, melyek biztosan szoktak bélgázt ereszteni, azaz ennek értéke vagy `"Yes"`, vagy `"Hell Yes"`. A kiírás során az állatok nevét **egy sorba**, egymástól pontosvesszővel elválasztva jelenítse meg.

Példarészlet egy lehetséges bemeneti csv fájlból:

```text
Baboons;Yes
Bristle worms;No
Giraffe;Hell Yes
Spiders;Maybe
```

### Megoldási sablon

```cpp
void isFart(std::string dataset);
```

---

## 49. Feladat – getNotes (akkord hangjainak meghatározása)

**Feladat**  

Készítsen

```cpp
std::string getNotes(std::string chord)
```

függvényt, ami egy paraméterül kapott akkord nevéről eldönti, hogy milyen hangokból épül fel, és ezeket egy `std::string`-be fűzve, szóközzel elválasztva visszaadja.

A zenei hangok sorban a következők lehetnek:

```text
"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#" vagy "B"
```

A hangok sorban egymást követik, olyan módon, hogy a `"B"` hang után ismét `"C"` következik, majd `"C#"`, és így tovább.

A függvénynek két fajta akkordot kell felismernie: **dúr akkord** és **domináns szeptimakkord**.

- A dúr akkord neve csak az alaphangjából áll, ami tetszőleges hang lehet a felsoroltak közül.  
  Például: `"A"`, `"C#"` stb.
- A domináns szeptimakkord esetén az alaphangot adjuk meg, majd egy `7`-es szám következik.  
  Például `"A7"`, `"C#7"` stb.

Ha dúr akkordnév érkezik bemenetként, akkor sorban a következő hangokat tartalmazza a kimenet:  
**alaphang, az alaphang után következő 4. hang és az alaphang után következő 7. hang.**

Ha domináns szeptimakkordról van szó, akkor a kimeneti sorrend:  
**alaphang, az alaphang után következő 4. hang, az alaphang után következő 7. hang és az alaphang után következő 10. hang.**

### Megoldási sablon

```cpp
std::string getNotes(std::string chord);
```

---

## 50. Feladat – printGantt (Gantt-diagram s/e intervallumokból)

**Feladat**  

Készítsen

```cpp
void printGantt(int s[], int e[], int n)
```

függvényt, amely Gantt-diagram megjelenítésére alkalmas. A diagram `n` darab tevékenységet tartalmaz, ahol az egyes tevékenységek kezdő, legelső időszakát az `s` tömb, a befejező, legutolsó időszakát az `e` tömb tartalmazza. Most az nincs meghatározva, hogy az időszakok milyen mértékegységet jelentenek (pl. nap, hét, hónap), a megjelenítés tekintetében nincs jelentősége.

Az egyes tevékenységeket egymás alatt jelenítse meg a következők szerint:

- Minden sor az `"x. feladat"` szöveggel kezdődik, ahol `x` az adott feladat sorszáma. A listában a legelső sorszáma 1, a következőé 2, és így tovább.
- Maximum 99 feladatra kell felkészülni, és a sorszámot minden esetben **két karakter hosszan** jelenítse meg, ahol a kitöltő karakter a szóköz legyen.
- A feladat nevét és a hozzá tartozó időtartomány megjelenítését egy `" | "` karaktersorozat választja el.
- Ez után `"█"` karakterek segítségével vizualizálja a tevékenységhez tartozó időtartományt, ahol egy időegység egy karakternek felel meg.

### Megoldási sablon

```cpp
void printGantt(int s[], int e[], int n);
```

---

## 51. Feladat – printForm (űrlap/táblázat előkészítése)

**Feladat**  

Készítsen

```cpp
void printForm(std::string header[], int rows, int cols)
```

függvényt, amely nyomtatásra készít elő egy táblázatot.

A függvénynek egy táblázatot kell a kimenetre rajzolnia. A táblázat fejlécének feliratait a `header` tömb tartalmazza, melynek elemszáma `cols`, és egyben ennyi oszlopa legyen a táblázatnak.

A fejléc után `rows` darab sornak kell következnie, melyek egyenként `cols` darab üres cellát tartalmaznak. A táblázat szegélyét `"|"` és `"-"` karakterekből rajzolja a kimenetre, a minta szerinti elgondolás alapján.

A táblázat cellái ugyanolyan méretűek, ahol a szélesség a következő szerint kerüljön meghatározásra:

- Vegye a leghosszabb fejlécszöveget, és annak hosszát 2-vel növelve kapja meg a cellák szélességét.

Az egyes fejlécszövegeket **középre igazítva** jelenítse meg.  
Ha az adott fejlécszöveg karakterszáma miatt nem lehetséges pontosan középre igazítani, akkor a szöveg előtt legyen **eggyel több szóköz**.

A fejléc szövege csak az angol ábécé karaktereit és szóközt tartalmazhat, és a táblázatnak mindig van legalább 1 fejléce.

### Megoldási sablon

```cpp
void printForm(std::string header[], int rows, int cols);
```

---

## 52. Feladat – drawRect (téglalapok rajzolása szürkeárnyalatos „képre”)

**Feladat**  

Készítsen

```cpp
void drawRect(int **m, int w, int h, struct rect rects[], int num_of_rects)
```

függvényt, amelynek segítségével szürkeárnyalatos képeket lehet rajzolni.

A bemeneti `m` kétdimenziós tömb jelentsen egy `w` széles (első koordináta) és `h` magas (második koordináta) képet. Erre a képre szeretnénk `num_of_rects` darab téglalapot rajzolni, melyek paraméterei a `rects` tömbben találhatók.

Egy `struct rect` tárolja el egy téglalap bal felső sarkának pozícióját (`x`, `y`), a szélességét (`w`), és a magasságát (`h`).

A téglalapokat rajzolja az `m` képre olyan módon, hogy:

- ahova a téglalap **szélei** kerülnek, ott az értéke **1** legyen,
- ahol a **közbülső** értékei szerepelnek (a téglalap belseje), ott **0** érték jelenjen meg.

Ha két tetszőleges téglalap átfedésben van, akkor az legyen előrébb, amelynek a `rects` tömbben elfoglalt pozíciójának az indexe **kisebb**. Az `m` kép bal felső sarka jelentse a 0. sor és 0. oszlopban található értéket.

### Megoldási sablon

```cpp
struct rect {
    int x;
    int y;
    int w;
    int h;
};

void drawRect(int** m, int w, int h, rect rects[], int num_of_rects);
```

---

## 53. Feladat – getBank (GIRO-kód alapján bank neve)

**Feladat**  

A magyar bankszámlaszámok első három számjegye a számlavezető pénzintézetet kódolja (ún. GIRO-kód). Definiálja azt a

```cpp
std::string getBank(std::string accno, std::string filename)
```

függvényt, ami megállapítja, hogy az `accno` folyószámlát melyik pénzintézetnél vezetik! A `filename` nevű állomány egy CSV fájl, melynek két oszlopa van: az első a bank három számjegyű kódját tárolja, a második a bank nevét. E kettőt **pontosvessző** választja el.

A visszatérési érték a számlavezető bank neve legyen, ha talál ilyet a fájlban. Ha nem, térjen vissza `"Unknown bank"` üzenettel! A megadott adatokról feltételezheti, hogy formailag helyesek lesznek.

### Megoldási sablon

```cpp
std::string getBank(std::string accno, std::string filename);
```

---

## 54. Feladat – append (bankszámla + másodlagos azonosítók listához fűzése)

**Feladat**  

Banki átutalás során ma már nem csak egy adott számlaszámra lehet utalni, hanem ún. másodlagos azonosítók (e-mail cím, mobiltelefonszám, adószám, adóazonosító jel) alapján is.

Egy bankszámlaszámot és a hozzá társított másodlagos azonosítókat egy **irányban láncolt listában** tároljuk, a listaelem szerkezetét pedig már előzetesen definiáltuk a következőképpen:

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

Definiálja azt az

```cpp
account* append(account* anchor, std::string accountNo, std::string email,
                std::string mobile, std::string taxNo, std::string taxId)
```

függvényt, ami a lista **végéhez** hozzáfűzi a megadott azonosítókból álló listaelemet, **ha minden azonosító egyedi**, majd visszatér a lista horgonyával (első elemének címével).

### Megoldási sablon

```cpp
account* append(account* anchor,
                std::string accountNo,
                std::string email,
                std::string mobile,
                std::string taxNo,
                std::string taxId);
```

---

## 55. Feladat – account (magyar bankszámlaszám ellenőrzése)

**Feladat**  

A magyar bankszámlaszámok két vagy három, egyenként nyolc számjegyből álló blokkokból tevődnek össze, melyeket kötőjelek választanak el egymástól. A számlaszámokat beépített ellenőrző számjegyek védik a véletlen elgépelések okozta hibáktól.

- Az első blokk első hét számjegyének hibáit fedi fel a blokk utolsó számjegye, ami ennek a blokknak az ellenőrző számjegye.
- Ha csak két blokk van, akkor a második blokk utolsó számjegye is ellenőrző számjegy, ami a második blokk első hét számjegyének hibáit segít felfedni.
- Ha azonban három blokkból áll a számlaszám, akkor a második blokk összes számjegyéből, és a harmadik blokk első hét számjegyéből álló részét védi a legutolsó helyértéken álló ellenőrző számjegy.

Az ellenőrző számjegyeket úgy képezik, hogy az első blokk elemeit balról jobbra haladva megszorozzák `9, 7, 3, 1, 9, 7, 3` számokkal és a szorzatokat összeadják. Az ellenőrző számjegyet a 10-zel maradék nélkül osztható összegre történő felkerekítés értéke adja.  
Alapvetően ugyanilyen módon számolják a második ellenőrző összeget is, de ha három blokkból áll a számlaszám, akkor a `9, 7, 3, 1` szorzókat egymás után többször is alkalmazzák a szükséges számjegyekre.

Feladat: definiálja azt a

```cpp
bool account(std::string accno)
```

függvényt, ami akkor és csak akkor ad vissza igaz értéket, ha az átadott számlaszám **formailag is megfelelő**, és az **ellenőrző számjegyek is megfelelő értékűek**.

### Megoldási sablon

```cpp
bool account(std::string accno);
```

---

## 56. Feladat – isValid (Huffman-kódtábla prefix tulajdonságának ellenőrzése)

**Feladat**  

A Huffman kódolás egy hatékony tömörítő eljárás, mely változó hosszúságú prefix kódokkal helyettesíti az adatforrás karaktereit. A prefix kód azt jelenti, hogy egyetlen karakterhez rendelt kód sem kezdődik valamely másik karakter kódjával, és nem is egyezik meg azokkal (különben a tömörített adat nem lenne visszafejthető).

Definiálja azt a

```cpp
bool isValid(huffman* table, int n)
```

függvényt, amelynek `table` paramétere egy `huffman` típusú struktúrákból álló, `n` elemű tömb. A struktúra már definiált a következőképpen:

```cpp
struct huffman {
    char        letter;
    std::string code;
};
```

A függvény visszatérési értéke akkor és csak akkor igaz, ha a struktúratömb minden kódjára teljesül a **prefix tulajdonság** (azaz egyik kód sem előtagja egy másiknak).

### Megoldási sablon

```cpp
struct huffman {
    char        letter;
    std::string code;
};

bool isValid(huffman* table, int n);
```

---

## 57. Feladat – parosTorol (páros értékű listaelemek törlése)

**Feladat**  

Már definiáltuk a

```cpp
struct adat {
    int   szam;
    adat* kov;
};
```

struktúrát egyszeresen láncolt lista létrehozásához.

Készítse el azt az

```cpp
adat* parosTorol(adat* horgony)
```

függvényt, ami kitörli a listából azokat az elemeket, melyek `szam` tagja páros számot tárol. A visszatérési érték a módosított lista horgonya legyen!

### Megoldási sablon

```cpp
struct adat {
    int   szam;
    adat* kov;
};

adat* parosTorol(adat* horgony);
```

---

## 58. Feladat – screaming (SCREAMING_SNAKE_CASE előállítása)

**Feladat**  

A szoftverek számos helyen alkalmazzák az ún. **screaming snake case** névkonvenciót. Ez abból áll, hogy a több szóból összetett azonosítók szavait csupa nagybetűvel írják, egymástól `_` karakterrel elválasztva.

Definiálja azt a

```cpp
std::string screaming(std::string* szavak, int n)
```

függvényt, ami az `n` elemű `szavak` tömb elemeit (szavait) felhasználva előállít egy screaming snake case azonosítót, amit visszaad.  
Például a `{"I", "love", "C++", "programming"}` bemenetre: `I_LOVE_C++_PROGRAMMING`.

### Megoldási sablon

```cpp
std::string screaming(std::string* szavak, int n);
```

---

## 59. Feladat – color2gs (szín átalakítása szürkeskálára súlyokkal)

**Feladat**  

Adott két struktúra:

```cpp
struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct weight {
    double r;
    double g;
    double b;
};
```

Valósítsa meg azt az

```cpp
unsigned char color2gs(const color& c, const weight& w)
```

függvényt, ami átalakítja a `c` paraméterben érkező, RGB összetevőivel adott színt egyetlen szürkeskálás értékké, figyelembe véve a `w` paraméterben adott súlyokat.

Például a BT-709 szabvány szerinti súlyokkal (`w = {0.21, 0.72, 0.07}`) a szürkeskálás fényerősség érték kiszámítása:

```text
gs = 0.21*r + 0.72*g + 0.07*b
```

### Megoldási sablon

```cpp
struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct weight {
    double r;
    double g;
    double b;
};

unsigned char color2gs(const color& c, const weight& w);
```

---

## 60. Feladat – mbox (szövegdoboz csillagkeretben)

**Feladat**  

Definiálja azt a

```cpp
void mbox(const std::string& message)
```

függvényt, ami a paraméterként adott `message` szöveget csillagokból rajzolt szövegdoboz belsejében, **balra igazítottan** jeleníti meg! Amennyiben az üzenet soremelés (`'
'`) karaktert tartalmaz, a nyomtatást a következő sorban kell folytatni, a dobozon belül.

### Megoldási sablon

```cpp
void mbox(const std::string& message);
```

---

## 61. Feladat – vek2mtx (vektor → mátrix dinamikusan)

**Feladat**  

Definiálja azt az

```cpp
int** vek2mtx(int* vek, int s, int o)
```

függvényt, ami a neki átadott, `s*o` elemszámú `vek` tömb elemeiből előállít és visszaad egy mátrixot, melynek futásidőben, dinamikusan foglal tárhelyet. A mátrix sorainak száma `s`, oszlopainak száma `o` legyen! A visszatérési érték a sorokra mutató mutatótömb címe.

### Megoldási sablon

```cpp
int** vek2mtx(int* vek, int s, int o);
```

---

## 62. Feladat – friendly_numbers (barátságos számpár)

**Feladat**  

Valósítson meg

```cpp
bool friendly_numbers(int a, int b)
```

függvényt. A függvény feladata annak eldöntése, hogy `a` és `b` **barátságos számpárt** alkotnak vagy sem, és ennek megfelelő logikai értékkel térjen vissza.

Két szám akkor tekinthető barátságosnak, ha mindkettő esetén fennáll, hogy önmagánál kisebb osztóinak összege megegyezik a másik számmal.  
Például 220 és 284 barátságos számpár.

### Megoldási sablon

```cpp
bool friendly_numbers(int a, int b);
```

---

## 63. Feladat – diagram (oszlopdiagram X karakterekkel)

**Feladat**  

Készítsen

```cpp
void diagram(int* data, int n)
```

függvényt, ahol `data` egy `n` elemű tömb, melynek elemszáma legalább 1 és minden értéke legalább 0.

A függvény a `data` tartalmát egy **oszlopdiagram** formájában rajzolja a kimenetre a következők szerint:

- Az oszlopok `'X'` karakterekből épüljenek fel.
- Minden oszlop két karakter széles.
- Az adott oszlop magassága egyezzen meg a `data` megfelelő elemének értékével.
- Minden oszlop előtt legyen **két szóköznyi** üres terület (az első előtt is).

### Megoldási sablon

```cpp
void diagram(int* data, int n);
```

---

## 64. Feladat – check (személyi azonosító ellenőrző számjegye)

**Feladat**  

Készítsen

```cpp
bool check(std::string id)
```

függvényt, amely alkalmas személyi azonosító számsorozat **ellenőrző számjegyének** ellenőrzésére.

A bemeneti `id` egy `std::string`, amely a személyi azonosítót tartalmazza. A személyi azonosító 11 darab egyjegyű szám, ahol az utolsó érték egy ellenőrző számjegy, ami a többi 10 számjegyből számítható. A függvény visszatérési értéke egy logikai érték legyen, ami jelzi, hogy az `id` utolsó számjegye helyes vagy sem az előírt szabály szerint.

(Feltételezheti, hogy `id` mindig 11 jegyű és csak számokat tartalmaz.)

### Megoldási sablon

```cpp
bool check(std::string id);
```

---

## 65. Feladat – get_time (másodpercek → nap, óra, perc, másodperc)

**Feladat**  

Valósítson meg

```cpp
struct time {
    int days;
    int hours;
    int minutes;
    int seconds;
};
```

struktúrát, ami nap, óra, perc és másodperc formában kifejezett idő tárolására alkalmas. Minden értéket egész számként tárolunk, az egyes tagok neve a fenti legyen.

Hozzon létre

```cpp
time get_time(int s)
```

függvényt, ahol `s` egy másodpercben kifejezett idő érték. Ezt alakítsa át nap, óra, perc, másodperc formátumba, és egy ennek megfelelő `time` struktúrával térjen vissza.

### Megoldási sablon

```cpp
struct time {
    int days;
    int hours;
    int minutes;
    int seconds;
};

time get_time(int s);
```

---

## 66. Feladat – luxor (Luxor szelvény tippjeinek ellenőrzése)

**Feladat**  

Valósítson meg

```cpp
bool luxor(int* ticket, int n)
```

függvényt, ahol `ticket` egy `n` elemű tömb. A függvény határozza meg, hogy `ticket` egy helyes **Luxor szelvény** tippjeit tartalmazza vagy sem, és ennek megfelelő logikai értékkel térjen vissza.

A Luxor játékban az `[1, 75]` intervallumból kell összesen 20 számot megjelölni, úgy, hogy a számok 5 egyenlő, nem átfedő intervallumra vannak osztva, és **minden intervallumból 4-4 számra** kell tippelni.

### Megoldási sablon

```cpp
bool luxor(int* ticket, int n);
```

---

## 67. Feladat – beansCheck (EAN-8 vonalkód ellenőrzése)

**Feladat**  

A legtöbb európai termékre, melyekre hely hiányában csak egy rövid vonalkódot tudnak elhelyezni, az **EAN-8** szabványnak megfelelő vonalkód kerül. Ez 8 számjegyből áll, melyek közül az utolsó egy ellenőrző számjegy.

Az ellenőrző számjegyet úgy számítják ki, hogy az első 7 számjegy közül minden **páros indexűt** 3-mal szoroznak be, minden **páratlan indexűt** pedig 1-gyel, majd veszik ezeknek a szorzatoknak az összegét. Ennek az összegnek az utolsó számjegyét kivonják 10-ből, ez lesz az ellenőrző számjegy. Ha ez pont 10-re adódna, helyette 0-t használnak.

Definiálja azt a

```cpp
bool beansCheck(const std::string& barcode)
```

függvényt, ami akkor és csak akkor tér vissza logikai igaz értékkel, ha a paraméterként adott vonalkód minden szempontból helyes, azaz

- pontosan 8 számjegy karakterből áll, és
- az ellenőrző számjegy értéke megfelelő.

### Megoldási sablon

```cpp
bool beansCheck(const std::string& barcode);
```

---

## 68. Feladat – justify (sorkizárt szöveg egy sorban)

**Feladat**  

Definiálja azt a

```cpp
void justify(const std::string words[], int n, int width)
```

függvényt, mely az `n` elemű `words` tömbben szereplő szavakat `width` szélességben nyomtatja ki **egymás mellé, sorkizárt igazítással**!

Ez konkrétan azt jelenti, hogy:

- a szavak közé úgy kell elhelyezni a szóközöket, hogy a szavak az elválasztó jelekkel együtt pontosan `width` szélességet adjanak ki,
- az egymást követő szópárokat elválasztó jelek számának amennyire lehet, azonosnak kell lennie, de tört számú szóközt nem lehet megjeleníteni,
- ha szükséges, az első néhány szó között legyen eggyel több szóköz, mint a későbbi szavak között.

Nem kell felkészülnie olyan határhelyzetek kezelésére, mint pl.

- kettőnél kevesebb szó,
- olyan alacsony `width` érték, amelynél lehetetlen a szavakat akár csak egyetlen elválasztó jellel is megjeleníteni.

### Megoldási sablon

```cpp
void justify(const std::string words[], int n, int width);
```

---

## 69. Feladat – wordCount (szavak száma szövegben)

**Feladat**  

Definiálja azt az

```cpp
int wordCount(const std::string text)
```

függvényt, ami megszámolja a `text` szövegben lévő szavakat, és visszatérési értékében szolgáltatja az eredményt!

Vegye figyelembe, hogy a szavakat szóközök, tabulátor (`'\t'`) és új sor (`'\n'`) karakterek is elválaszthatják egymástól, valamint egymás mellett akár több ilyen elválasztó jel is állhat.

### Megoldási sablon

```cpp
int wordCount(const std::string text);
```

---

