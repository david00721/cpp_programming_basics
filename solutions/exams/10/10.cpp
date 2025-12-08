#include <iostream>
#include <string>

using namespace std;

struct prefixPair {
    string codeWord;
    string text;
    prefixPair* next;
};

// Segédfüggvény: új elem hozzáfűzése a láncolt listához
void append(prefixPair*& head, const string& codeWord, const string& text) {
    prefixPair* elem = new prefixPair;
    elem->codeWord = codeWord;
    elem->text = text;
    elem->next = nullptr;

    if (head == nullptr) {
        head = elem;
    } else {
        prefixPair* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = elem;
    }
}

// Segédfüggvény: láncolt lista felszabadítása
void clear(prefixPair*& head) {
    while (head != nullptr) {
        prefixPair* tmp = head->next;
        delete head;
        head = tmp;
    }
}

// Prototype - implement this function
void decode(const prefixPair *codeWords, const std::string &message)
{
    std::string currentCode;

    for (int i = 0; i < message.size(); ++i)
    {
        char c = message[i];
        currentCode.push_back(c);

        const prefixPair *currentNode = codeWords;
        while (currentNode != nullptr)
        {
            if (currentNode->codeWord == currentCode)
            {
                
                std::cout << currentNode->text << '\n';
                currentCode.clear(); 
                break;               
            }
            currentNode = currentNode->next;
        }
    }
}

int main() {
    prefixPair* codeWords = nullptr;

    append(codeWords, "0",  "Samsung");
    append(codeWords, "10", "Xiaomi");
    append(codeWords, "11", "Apple");

    cout << "decode(\"01011100\") eredmenye:" << endl;
    decode(codeWords, "01011100");

    clear(codeWords);

    return 0;
}