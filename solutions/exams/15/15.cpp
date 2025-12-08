#include <iostream>
#include <string>

using namespace std;

struct ListItem {
    string word;
    ListItem* next;
};

// Segédfüggvény: lista kiírása és felszabadítása
void printAndDelete(ListItem* head) {
    while (head) {
        cout << head->word << endl;
        ListItem* tmp = head->next;
        delete head;
        head = tmp;
    }
}

// Prototype - implement this function
ListItem* splitter(const string& text, char separator) {
    ListItem* head = nullptr;
    ListItem* tail = nullptr;

    string current;

    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == separator) {
            // Új listaelem létrehozása
            ListItem* node = new ListItem{current, nullptr};

            if (!head) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;

            current.clear(); // reset a következő részhez
        } else {
            current += text[i];
        }
    }

    // Utolsó rész hozzáadása (akkor is, ha üres!)
    ListItem* node = new ListItem{current, nullptr};
    if (!head) {
        head = node;
    } else {
        tail->next = node;
    }

    return head;
}

int main() {
    printAndDelete(splitter("This is the beginning of a beautiful friendship.", ' '));

    cout << endl;

    printAndDelete(splitter("One;Two;Three;Four", ';'));

    cout << endl;

    printAndDelete(splitter("Leading--and--trailing--separators--", '-'));

    return 0;
}
