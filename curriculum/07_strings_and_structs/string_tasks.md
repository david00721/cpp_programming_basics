# String feladatok

Az alábbiakban több, **stringekkel kapcsolatos C++ feladat** van szépen formázva, Markdown dokumentumba rendezve.

---

## 1. Feladat – `struct curse` és `getFirstCurse`

Készítsen `string getFirstCurse(struct curse curses[], int n)` függvényt!  

A `curses` tömb minden eleme 1-1 káromkodást tartalmaz Quentin Tarantino valamely filmjéből.  
Egy káromkodáshoz (`struct curse`) tartozik:
- a film címe, amiben elhangzott,
- a káromkodás szövege,
- valamint annak ideje a filmben.

Az `n` változó megadja, hogy a bemeneti `curses` tömb hány bejegyzést tartalmaz.

A függvény feladata:
- Keresse meg, hogy **melyik káromkodás hangzott el leghamarabb** (legkisebb idő).
- Visszatérési értéke legyen a leghamarabbi káromkodáshoz tartozó **film címe**.

Készítse el a káromkodások tárolására alkalmas struktúrát is, a következő mezőkkel:
- `string movie` – a film címe, amiben elhangzik a káromkodás,
- `string word` – maga a káromkodás szövege,
- `double time` – a káromkodás elhangzásának ideje a filmben.

---

## 2. Feladat – `getNotes` akkordfelbontás

Készítsen `string getNotes(string chord)` függvényt, ami a paraméterül kapott akkord nevéről eldönti, hogy **milyen hangokból épül fel**, és ezeket egy stringbe fűzve, szóközzel elválasztva visszaadja!

A zenei hangok sorban a következők lehetnek:

`"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#"` vagy `"B"`.

A hangok egymást követik, olyan módon, hogy a `"B"` hang után ismét `"C"` következik, majd `"C#"`, és így tovább (körkörös sorozat).

A függvénynek **két fajta akkordot** kell felismernie:

1. **Dúr akkord**
   - Neve csak az alaphangból áll, ami tetszőleges hang lehet a felsoroltak közül.  
     Például: `"A"`, `"C#"` stb.
   - Kimenetben szereplő hangok sorrendje:
     - alaphang,
     - az alaphang után következő **4. hang**,
     - az alaphang után következő **7. hang**.

2. **Domináns szeptimakkord**
   - Megadjuk az alaphangot, majd egy `7`-es szám következik.  
     Például: `"A7"`, `"C#7"` stb.
   - Kimenetben szereplő hangok sorrendje:
     - alaphang,
     - az alaphang után következő **4. hang**,
     - az alaphang után következő **7. hang**,
     - az alaphang után következő **10. hang**.

A visszatérési érték egy `string`, amely a hangok nevét tartalmazza **szóközzel elválasztva**.

---

## 3. Feladat – Screaming snake case: `screaming`

A szoftverek számos helyen alkalmazzák (a C++ pl. a szimbolikus állandóknál) az ún. **screaming snake case** névkonvenciót.  

Ez abból áll, hogy a több szóból összetett azonosítók szavait:
- csupa **nagybetűvel** írják,
- egymástól **`_` (aláhúzás)** karakterrel elválasztva.

Definiálja azt a `string screaming(string* szavak, int n)` függvényt, ami az `n` elemű `szavak` string tömb elemeit (szavait) felhasználva **előállít egy screaming snake case azonosítót**, amit visszaad!

### Példa

```cpp
string s[] = {"I", "love", "C++", "programming"};
int n = sizeof(s) / sizeof(s[0]);

cout << screaming(s, n) << endl;
```

Lehetséges kimenet:
```text
I_LOVE_C++_PROGRAMMING
```

---

## 4. Feladat – Csillagos szövegdoboz: `mbox`

Definiálja azt a `void mbox(const string& message)` függvényt, ami a paraméterként adott `message` szöveget **csillagokból rajzolt szövegdoboz** belsejében, balra igazítottan jeleníti meg!

- Amennyiben az üzenet soremelés (`'\n'`) karaktert tartalmaz, a nyomtatást a következő sorban kell folytatni!
- A keret csillagokból (`'*'`) álljon.
- A doboz szélessége igazodjon a leghosszabb sor hosszához.

### Példa

```cpp
mbox("ab\ncde\nf");
```

Lehetséges kimenet (egy lehetséges megoldás):

```text
*****
*ab  *
*cde *
*f   *
*****
```

---

## 5. Feladat – Szavak számolása: `wordCount`

Definiálja azt az `int wordCount(const string text)` függvényt, ami **megszámolja a `text` szövegben lévő szavakat**, és visszatérési értékében szolgáltatja az eredményt!

Szabályok:
- A szavakat elválaszthatják egymástól:
  - szóközök (`' '`),
  - tabulátor (`'\t'`),
  - új sor karakterek (`'\n'`).
- Egymás mellett akár **több ilyen elválasztó jel is állhat**, ezeket nem szabad több szónak számolni.
- A szó az elválasztó karaktereken kívüli, összefüggő karakterek sorozata.

---
