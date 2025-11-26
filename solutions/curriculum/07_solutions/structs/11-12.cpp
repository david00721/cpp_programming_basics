#include <iostream>

// 👉 **11 - Feladat közösen:** Egészítsd ki a láncolt listás programot push_back és clear_list függvényekkel. A main-ben:
// - szúrj be pár elemet elejére és végére is,
// - írd ki a listát,
// - majd clear_list hívással szabadítsd fel.

struct Node {
    int value;
    Node* next;
};

// Beszúrás a lista elejére
void insertAtBeginning(Node* &head, const int newValue)
{
    Node *newNode = new Node();
    newNode->value = newValue;
    newNode->next = head;
    head = newNode;
}

// Bejárás és kiírás
void printList(const Node* head)
{
    const Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Felszabadítás
void clearList(Node* &head)
{
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// Beszúrás a végére
void insertAtEnd(Node* &head, const int newValue)
{
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// 👉 **12 - Feladat önállóan:** Add hozzá az erase függvényt, amely törli az első olyan elemet, amelynek értéke x. Teszteld:
// - szúrj be több elemet,
// - törölj néhányat (elsőt, középsőt, utolsót),
// - írd ki mindig a lista aktuális állapotát.

void deleteValue(Node* &head, const int target)
{
    if (head == nullptr) return;

    if (head->value == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->value != target) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

int main()
{
    Node* head = nullptr;

    insertAtEnd(head, 3);
    insertAtBeginning(head, 1);
    insertAtEnd(head, 5);
    insertAtBeginning(head, 0);
    insertAtEnd(head, 6);
    printList(head);

    deleteValue(head, 0); // törli az elejét
    printList(head);

    deleteValue(head, 5); // törli a középsőt
    printList(head);

    deleteValue(head, 6); // törli a végét
    printList(head);

    clearList(head);
    return 0;
}