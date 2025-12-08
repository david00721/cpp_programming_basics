# Fájlos feladatok

## 1. Feladat – rightAlign

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

## 2. Feladat – center (középre igazított kiírás)

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

## 3. Feladat – colorSearch (futócipő színek)

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

## 4. Feladat – fullNameSort (teljes név szerinti rendezés, fájlból-fájlba)

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

### Megoldási sablon

```cpp
std::string* fullNameSort(std::string fbe, std::string fki);
```

## 5. Feladat – duration (időkülönbség percekben, CSV-ből)

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

## 6. Feladat – isFart (állatok, amelyek biztosan „finganak”)

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