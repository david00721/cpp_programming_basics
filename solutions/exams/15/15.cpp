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
        cout << ">" << head->word << "<" << endl;
        ListItem* tmp = head->next;
        delete head;
        head = tmp;
    }
}

// Prototype - implement this function
ListItem* splitter(const string& text, char separator);

int main() {
    printAndDelete(splitter("This is the beginning of a beautiful friendship.", ' '));

    cout << endl;

    printAndDelete(splitter("One;Two;Three;Four", ';'));

    cout << endl;

    printAndDelete(splitter("Leading--and--trailing--separators--", '-'));

    return 0;
}
