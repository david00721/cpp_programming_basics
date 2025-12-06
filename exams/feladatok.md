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

## 5. Feladat – stackedBarChart

**Feladat:**  
Definiálja azt a `void stackedBarChart(int** data, int rows, int cols)` függvényt, ami halmozott sávdiagramot rajzol a `rows` sorból és `cols` oszlopból álló `data` mátrix elemeit felhasználva! A sávdiagram annyi sorból álljon, amennyi `rows` értéke! A sorokat rendre az `X`, `>`, `+`, `=` és `-` jelekkel kell megrajzolni. Mindegyikből annyit kell egymás mellé írni, amennyi a mátrix aktuális sorában a soron következő cella értéke. Ha a mátrixnak 5-nél több oszlopa lenne, csak az első 5-öt kell megrajzolni.

Példa:
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

### Megoldási sablon
```cpp
void stackedBarChart(int** data, int rows, int cols);
```

---

## 6. Feladat – gp

**Feladat:**  
Definiálja a `double* gp(double a1, double q, int n)` függvényt, mely visszatér egy `n` elemű tömbbel, amelynek elemei az `a1` értékű első taggal rendelkező, `q` kvóciensű mértani sorozat egymást követő tagjai.

Példa:
```cpp
printAndClear(gp(3, 3, 5), 5);
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
Test    Result
rightAlign("file1.txt");
     A
    AA
   AAA
  AAAA
 AAAAA
AAAAAA

File tartalma: 
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
Test    Result
draw("DDDDDDDDDRRRRRRRRRUUUUUUUUULLLLLLLL");
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

**Példa**

```cpp
std::cout << std::setprecision(2) << getArea(4, 2) << std::endl;
// elvárt eredmény: 4
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

// elvárt kimenet:
//
// Samsung
// Xiaomi
// Apple
// Xiaomi
// Samsung
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

// elvárt kimenet:
//
// ****
//  *****
//    *******
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

// elvárt kimenet:
//
// alma 7
// barack 3
// citrom 1
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

// elvárt eredmény (pl. ilyen egyenletlen):
//
//   A
//   AA
//  AAA
//  AAAA
// AAAAA
// AAAAAA
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
// elvárt kimenet:
// 1 3 5 3 1
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

// elvárt kimenet:
//
// >This<
// >is<
// >the<
// >beginning<
// >of<
// >a<
// >beautiful<
// >friendship.<
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

A függvény fejlécét segítségképpen megadtuk előre.  
TIPP: használjon `unsigned int`-et!

**For example:**

```cpp
std::cout << ispalindrome("gorog") << '\n';
// elvárt eredmény: 1
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

// elvárt eredmény:
//
// 0
// 11.1803
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

// elvárt eredmény:
//
// 20
// 100
```

### Megoldási sablon (a struktúra + műveletek prototípusai)

```cpp
struct IngatlanLista;

IngatlanLista* beszurElejere(IngatlanLista* head, double terulet, int ertek);
double totalArea(const IngatlanLista* head);
double averageArea(const IngatlanLista* head);
```

---


