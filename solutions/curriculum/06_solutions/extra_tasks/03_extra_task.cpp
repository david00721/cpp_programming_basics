/*
3. feladat - Betűstatisztika
Hozzon létre int* stat(string s) függvényt, ahol s egy angol szöveget tartalmaz. A függvény statisztikát készít, hogy az angol ábécé betűi hányszor fordulnak elő. A visszatérési érték egy tömb, amelyben:

    - 0. elem → 'a' db száma
    - 1. elem → 'b' db száma
    - ...
    - 25. elem → 'z' db száma
*/

#include <iostream>
#include <string>

int* stat(std::string s) {
    int* counts = new int[26];
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }
    
    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        }
    }
    
    return counts;
}

int main() {
    std::string text = "Hello World! This is a simple test string to count letter frequencies.";
    int* letterCounts = stat(text);
    
    for (int i = 0; i < 26; i++) {
        char letter = 'a' + i;
        std::cout << letter << ": " << letterCounts[i] << std::endl;
    }
    
    delete[] letterCounts;
    return 0;
}
     