#include <iostream>

using namespace std;

/*
Definiálja azt a void decode(const prefixPair* codeWords, const std::string& message) függvényt, 
melynek célja egy prefix kóddal kódolt szöveg visszafejtése és szavainak szabvány kimenetre nyomtatása egymás alá!

A prefix kódok olyan kódszavakkal helyettesítik az eredeti üzenet szavait, melyekre teljesül a prefix tulajdonság, 
azaz egyik kódszó sem kezdődik egyetlen másik kódszóval sem. 
A kódszavakat a codeWords paraméter adja meg egy prefixPair típusú struktúrákból álló láncolt lista formájában. 
Ennek codeWord tagja egy kódszó (pl. "0"), text tagja pedig a kódolt szöveg (pl. "Samsung"). 
A next nevű tag a következő listaelemet címzi. 
A decode függvény második, message paramétere a kódolt üzenetet adja meg.
*/

struct prefixPair {
    std::string codeWord;  // kódszó (pl. "0")
    std::string text;      // megfeleltetett szöveg (pl. "Samsung")
    prefixPair* next;      // láncolt lista következő eleme
};

void append(prefixPair*& head, const std::string& codeWord, const std::string& text)
{
    // új listaelem létrehozása
    prefixPair* newNode = new prefixPair{codeWord, text, nullptr};
    if (!head) {                          // ha üres a lista, az új elem lesz a fej
        head = newNode;
    } else {                              // különben végigmegyünk a listán
        prefixPair* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;          // hozzáfűzzük a végére
    }
}

void decode(const prefixPair* codeWords, const std::string& message)
{
    std::string currentCode;               // éppen feldolgozott kódrészlet
    size_t messageLength = message.length();
    for (size_t i = 0; i < messageLength; ++i) {
        currentCode += message[i];         // újabb karakter hozzáadása
        const prefixPair* current = codeWords;
        while (current) {                  // végigmegyünk a kódszavakon
            if (current->codeWord == currentCode) { // ha találtunk megfelelőt
                std::cout << current->text << std::endl; // kiírjuk a szót
                currentCode.clear();       // új szót kezdünk
                break;
            }
            current = current->next;
        }
    }
}

void clear(prefixPair*& head)
{
    // lista felszabadítása
    while (head) {
        prefixPair* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    prefixPair* codeWords = nullptr;                // üres lista

    append(codeWords, "0", "Samsung");              // 0 → Samsung
    append(codeWords, "10", "Xiaomi");              // 10 → Xiaomi
    append(codeWords, "11", "Apple");               // 11 → Apple

    decode(codeWords, "01011100");                  // kódolt üzenet visszafejtése

    clear(codeWords);                               // memória felszabadítása

    return 0;
}
