#include <iostream>

using namespace std;

int main()
{
    // 01 - Írj programot, ami kiírja a neved és az életkorod!
    cout << "Nev: Kocsis David, eletkor: 25" << endl;

    // 02 - Írj programot, ami két sort ír ki: az elsőben a kedvenc focicsapatod, a másodikban a kedvenc filmedet!
    cout << "Kedvenc focicsapat: FC Bayern Munchen" << endl;
    cout << "Kedvenc film: Interstellar" << endl;

    // 03 - Írj programot, amelyben tárolod a saját neved, életkorod és azt, hogy tanuló vagy-e, majd írd ki őket!
    string nev = "Kocsis David";
    int eletkor = 25;
    bool tanulo = false;

    cout << "Nev: " << nev << endl;
    cout << "Eletkor: " << eletkor << endl;
    cout << "Tanulo: " << tanulo << endl;

    // 04 - Írj programot, amelyben eltárolod egy könyv címét, szerzőjét és oldalszámát, majd jelenítsd meg!
    string konyvCim = "The Great Gatsby";
    string konyvSzerzo = "F. Scott Fitzgerald";
    int konyvOldalszam = 180;

    cout << "Konyv cim: " << konyvCim << endl;
    cout << "Konyv szerzo: " << konyvSzerzo << endl;
    cout << "Konyv oldalszam: " << konyvOldalszam << endl;

    // 05 - Írj programot, ami eltárolja egy kör sugarát, majd kiírja a kör kerületét a konstans `PI` felhasználásával!
    const double PI = 3.14159;
    double sugar = 5.0;
    double kerulet = 2 * PI * sugar;
    cout << "Kor kerulete: " << kerulet << endl;

    // 06 - Írj programot, ami kiszámítja egy négyzet területét, és a számításnál konstansként használd az oldalhosszt!
    const double oldalHossz = 4.0;
    double terulet = oldalHossz * oldalHossz;
    cout << "Negyzet terulete: " << terulet << endl;

    // 07 - Írj programot, amelyben `auto`-val létrehozol három különböző típusú változót, majd kiírod őket!
    auto szoveg = "Hello, C++!";
    auto szam = 42;
    auto tizedes = 3.14;
    cout << "Szoveg: " << szoveg << endl;
    cout << "Szam: " << szam << endl;
    cout << "Tizedes: " << tizedes << endl;

    // 08 - Írj programot, amely két `auto` típusú változót összead, és kiírja az eredményt!
    auto osszeg = szam + tizedes;
    cout << "Osszeg: " << osszeg << endl;

    // 09 - Írj programot, ami bekér két egész számot, majd lebegőpontos osztással kiszámítja a hányadosukat!
    int a, b;
    cout << "Kerek ket egesz szamot: ";
    cin >> a >> b;
    double hanyados = static_cast<double>(a) / b;
    cout << "Hanyados: " << hanyados << endl;

    // 10 - Írj programot, ami Celsius fokot Fahrenheitre vált át, lebegőpontos számítással!
    double celsius;
    cout << "Kerek egy Celsius fokot: ";
    cin >> celsius;
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    cout << "Fahrenheit: " << fahrenheit << endl;

    // 11 - Írj programot, ami bekéri a neved és az életkorod, majd kiírja egy mondatban!
    string felhasznaloNev;
    int felhasznaloEletkor;
    cout << "Kerek a neved es eletkorod: ";
    cin >> felhasznaloNev >> felhasznaloEletkor;
    cout << "Nev: " << felhasznaloNev << ", Eletkor: " << felhasznaloEletkor << endl;

    // 12 - Írj programot, ami bekér egy számot, majd kiírja a négyzetét!
    int szam;
    cout << "Kerek egy egesz szamot: ";
    cin >> szam;
    cout << "A szam negyzete: " << szam * szam << endl;

    // 13 - Írj programot, ami bekér két számot, és kiírja a különbséget, szorzatot és hányadost!
    int x, y;
    cout << "Kerek ket egesz szamot: ";
    cin >> x >> y;
    cout << "Kulonbseg: " << x - y << endl;
    cout << "Szorzat: " << x * y << endl;
    cout << "Hanyados: " << static_cast<double>(x) / y << endl;

    // 14 - Írj programot, ami bekér egy számot, és kiírja a szám maradékát, ha elosztod 3-mal!
    int szam3;
    cout << "Kerek egy egesz szamot: ";
    cin >> szam3;
    cout << "Maradek 3-mal osztva: " << szam3 % 3 << endl;

    // 15 - Fordítsd le és futtasd az egyik eddigi programodat parancssorból!  
    // (Ez egy komment, nincs kód ehhez a feladathoz)

    // 16 - Fordíts le és futtass egy másik programot IDE-ben!
    // (Ez egy komment, nincs kód ehhez a feladathoz)

    // Gyak 01 - Írj programot, ami bekér egy számot, és kiírja a kétszeresét!
    int szam4;
    cout << "Kerek egy egesz szamot: ";
    cin >> szam4;
    cout << "A szam ketszerese: " << szam4 * 2 << endl;

    // Gyak 02 - Írj programot, ami kiszámolja egy téglalap kerületét és területét!
    double hossz, szelesseg;
    cout << "Kerek a teglalap hossz es szelesseg: ";
    cin >> hossz >> szelesseg;
    cout << "Kerulet: " << 2 * (hossz + szelesseg) << endl;
    cout << "Terulet: " << hossz * szelesseg << endl;

    // Gyak 03 - Kérj be három számot, és írd ki az átlagukat!
    double num1, num2, num3;
    cout << "Kerek harom szamot: ";
    cin >> num1 >> num2 >> num3;
    cout << "Atlag: " << (num1 + num2 + num3) / 3.0 << endl;

    // Gyak 04 - Írj programot, ami bekér két egész számot, és kiírja az osztás eredményét és a maradékot!
    int numA, numB;
    cout << "Kerek ket egesz szamot: ";
    cin >> numA >> numB;
    cout << "Osztas eredmenye: " << numA / numB << endl;
    cout << "Maradek: " << numA % numB << endl;

    // Gyak 05 - Írj programot, ami bekér egy karaktert, és kiírja az ASCII kódját!
    char karakter;
    cout << "Kerek egy karaktert: ";
    cin >> karakter;
    cout << "ASCII kod: " << static_cast<int>(karakter) << endl;

    return 0;
}