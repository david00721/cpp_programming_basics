# Gyakorlati fájlbeolvasási példák (C++)

------------------------------------------------------------------------

## 1. Szóközzel tagolt adatok (pl. `10 20 30 hello`)

``` cpp
ifstream fin("input.txt");
int a, b, c;
string s;

fin >> a >> b >> c >> s;
```

------------------------------------------------------------------------

## 2. Soronkénti olvasás

``` cpp
ifstream fin("input.txt");
string line;

while (getline(fin, line)) {
    cout << line << endl;
}
```

------------------------------------------------------------------------

## 3. CSV -- vesszővel tagolt értékek

**Bemeneti fájl:**
```text
John,25,180
Anna,30,165
Bela,22,175
```

**CSV beolvasása:**
```cpp
ifstream fin("data.csv");
string line;

while (getline(fin, line)) {
    size_t p1 = line.find(',');
    size_t p2 = line.find(',', p1 + 1);

    string name = line.substr(0, p1);
    int age = stoi(line.substr(p1 + 1, p2 - p1 - 1));
    int height = stoi(line.substr(p2 + 1));

    cout << "Name: " << name
         << ", Age: " << age
         << ", Height: " << height << endl;
}
```

**Stringstreammel:**
```cpp
while (getline(fin, line)) {
    // vesszők lecserélése szóközre
    for (char& c : line) {
        if (c == ',') c = ' ';
    }

    stringstream ss(line);

    string name;
    int age;
    int height;

    ss >> name >> age >> height;

    cout << "Name: " << name
         << ", Age: " << age
         << ", Height: " << height << endl;
}
```

------------------------------------------------------------------------

## 4. Egyszerű struct betöltése "soron belüli kevert típusokból"

**Bemeneti fájl:**
```text
42 John 88.5
```

**Struct beolvasása:**

``` cpp
struct Person {
    int id;
    string name;
    double score;
};

ifstream fin("people.txt");
Person p;
fin >> p.id >> p.name >> p.score;
```

------------------------------------------------------------------------

## 5. Soronként több adat, struct tömb feltöltése

**Fájl:**
```text
1 Anna 3.14
2 Bela 2.71
3 Csaba 1.41
```

**Beolvasás:**
``` cpp
struct Person {
    int id;
    string name;
    double score;
};

int count = 0;
string line;

// 1. lépés: sorok számolása
while (getline(fin, line)) {
    count++;
}

// vissza a fájl elejére
fin.clear();
fin.seekg(0);

// 2. lépés: tömb foglalása
Person* arr = new Person[count];

// 3. lépés: adatok beolvasása >> operátorral
int i = 0;
while (fin >> arr[i].id >> arr[i].name >> arr[i].score) {
    i++;
}
```

------------------------------------------------------------------------

## 6. Bináris fájl írása

``` cpp
struct Data { int x; double y; };

Data d = {10, 3.14};

ofstream fout("data.bin", ios::binary);
fout.write(reinterpret_cast<const char*>(&d), sizeof(d));
```

------------------------------------------------------------------------

## 7. Bináris fájl olvasása

``` cpp
Data d;

ifstream fin("data.bin", ios::binary);
fin.read(reinterpret_cast<char*>(&d), sizeof(d));
```

------------------------------------------------------------------------

## 8. Egy sorból több szám különböző típusokkal (`getline + stringstream`)

**Bemenet:**

    12 3.14 7 test

``` cpp
string line;
getline(fin, line);

stringstream ss(line);

int a;
double b;
int c;
string s;

ss >> a >> b >> c >> s;
```

------------------------------------------------------------------------

## 9. Karakterenkénti beolvasás

``` cpp
char c;
while (fin.get(c)) {
    cout << c;
}
```
