# Extra feladatok a dinamikus memoriához

## 1. feladat – Mértani sorozat

Definiálja a double* gp(double a1, double q, int n) függvényt, mely visszatér egy n elemű tömbbel, amelynek elemei az a1 értékű első taggal rendelkező, q kvóciensű mértani sorozat egymást követő tagjai.

## 2. feladat - Szélső elemek körbetolása mátrixon

Készítsen double **shift(double **mtx, int w, int h) függvényt, ahol mtx egy kétdimenziós tömb, w az első, h a második dimenzió hossza. A függvény visszatérési értéke legyen mtx tömbbel megegyező méretű tömb.
A kimeneti tömb az mtx értékeit tartalmazza, azzal a különbséggel, hogy a tömb szélein (első/utolsó sor, első/utolsó oszlop) található elemeket az óramutató járásával megegyező irányba eggyel arrébb mozgatja.

## 3. feladat - Betűstatisztika
Hozzon létre int* stat(string s) függvényt, ahol s egy angol szöveget tartalmaz. A függvény statisztikát készít, hogy az angol ábécé betűi hányszor fordulnak elő. A visszatérési érték egy tömb, amelyben:

    - 0. elem → 'a' db száma
    - 1. elem → 'b' db száma
    - ...
    - 25. elem → 'z' db száma


## 4. feladat - Csigavonalban feltöltött mátrix

Definiálja azt az int** snail(int size) függvényt, amely létrehoz egy size x size méretű dinamikus mátrixot, majd a bal felső saroktól elindulva csigavonalban 1-től kezdődően növekvő számokat ír bele, amíg az összes mező ki nem töltődik!
A visszatérési érték a kitöltött mátrix (vektorokat címző mutatótömb).

## 5. feladat - Mátrix → vektor JPEG-hez hasonló bejárással
Definiálja azt az int* mtx2vec(int** mtx, int n) függvényt, ami egy n x n négyzetes mátrix elemeit egy adott „cikk-cakk / átlós” sorrendben végigjárja (JPEG-szerű bejárás), és egy dinamikusan létrehozott, azonos elemszámú vektorba írja azokat.
Ez utóbbi címe a visszatérési érték.