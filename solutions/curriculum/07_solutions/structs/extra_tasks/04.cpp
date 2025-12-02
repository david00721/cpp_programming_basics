#include <iostream>
#include <string>

// A feladatban megadott struktúra
struct ListItem {
    std::string word;
    ListItem* next;
};

// A FELADAT SZERINTI FÜGGVÉNY:
// A text-et feldarabolja separator karakter mentén, és
// a szavakat láncolt listában adja vissza (lista horgonya).
ListItem* splitter(const std::string& text, char separator) {
    ListItem* head = nullptr;  // lista eleje
    ListItem* tail = nullptr;  // lista vége (gyors beszúráshoz)
    std::string current;

    for(int i = 0; i < static_cast<int>(text.size()); ++i) {
        char c = text[i];
        if (c == separator) {
            // Ha eddig gyűlt valami, akkor kész a szó
            if (!current.empty()) {
                ListItem* node = new ListItem{current, nullptr};
                if (head == nullptr) {
                    head = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
                current.clear();
            }
            // Ha több separator egymás után van, akkor
            // csak átugorjuk, nem hozunk létre üres elemeket
        } else {
            current.push_back(c);
        }
    }

    // Ha a string nem separatorral végződik, az utolsó szót még el kell tenni
    if (!current.empty()) {
        ListItem* node = new ListItem{current, nullptr};
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
    }

    return head;  // a lista horgonya
}

// Segédfüggvény: kiírja a lista elemeit, majd felszabadítja a memóriát
void printAndDelete(ListItem* head) {
    while (head != nullptr) {
        std::cout << head->word << '\n';
        ListItem* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Teszt a feladat példájával
int main() {
    std::string text = "This is the beginning of a beautiful friendship.";
    char sep = ' ';

    ListItem* list = splitter(text, sep);
    printAndDelete(list);

    return 0;
}
