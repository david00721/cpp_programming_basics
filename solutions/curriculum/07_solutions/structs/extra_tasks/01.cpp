#include <iostream>
#include <string>

// A feladatban megadott struktúra
struct prefixPair
{
    std::string codeWord; // pl. "0", "10", "11"
    std::string text;     // pl. "Samsung", "Xiaomi", "Apple"
    prefixPair *next;
};

// Segédfüggvény: elem hozzáfűzése a láncolt lista végéhez
void append(prefixPair *&head, const std::string &codeWord, const std::string &text)
{
    prefixPair *newNode = new prefixPair{codeWord, text, nullptr};

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    prefixPair *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Segédfüggvény: lista felszabadítása
void clear(prefixPair *&head)
{
    while (head != nullptr)
    {
        prefixPair *tmp = head;
        head = head->next;
        delete tmp;
    }
}

// A feladat szerinti függvény:
// message: pl. "01011100"
// codeWords: a (kódszó -> szöveg) párokat tartalmazó láncolt lista
void decode(const prefixPair *codeWords, const std::string &message)
{
    std::string currentCode; // az éppen épített kódszó

    for (int i = 0; i < message.size(); ++i)
    {
        char c = message[i];
        currentCode.push_back(c); // új bit hozzáfűzése
        // Megnézzük, hogy a current megfelel-e valamelyik kódszónak
        const prefixPair *currentNode = codeWords;
        while (currentNode != nullptr)
        {
            if (currentNode->codeWord == currentCode)
            {
                // Találat: kiírjuk a hozzátartozó szöveget
                std::cout << currentNode->text << '\n';
                currentCode.clear(); // új szót kezdünk
                break;               // kilépünk a belső ciklusból, megyünk tovább a következő bitre
            }
            currentNode = currentNode->next;
        }
        // Ha nem találtunk egyezést, gyűjtjük tovább a biteket a current-ben,
        // amíg valamelyik kódszó ki nem jön belőle.
    }

    // Ha a message korrekt prefixkódolt üzenet, a végére a current üres lesz.
    // Ha nem, itt maradhatna benne "maradék", de a feladat ilyennel nem számol.
}

// Teszt a feladatban megadott példával
int main()
{
    prefixPair *codeWords = nullptr;

    append(codeWords, "0", "Samsung");
    append(codeWords, "10", "Xiaomi");
    append(codeWords, "11", "Apple");

    decode(codeWords, "01011100");

    clear(codeWords);
    return 0;
}