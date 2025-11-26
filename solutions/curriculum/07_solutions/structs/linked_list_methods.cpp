#include <iostream>

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

// Keresés
bool searchList(const Node* head, const int target)
{
    const Node* current = head;
    while (current != nullptr) {
        if (current->value == target) {
            return true;
        }
        current = current->next;
    }
    return false;
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

// Elem törlése érték alapján (első előfordulás)
void deleteValue(Node* &head, const int target)
{
    // Ha a lista üres
    if (head == nullptr) return;

    // Ha a törlendő elem a fej
    if (head->value == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;

    // Keresés a törlendő elem előtt
    // Addig megyünk, amíg a következő elem nem a célérték vagy el nem érjük a lista végét
    while (current->next != nullptr && current->next->value != target) {
        current = current->next;
    }

    // Ha megtaláltuk a törlendő elemet
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Lista felszabadítása
void freeList(Node* &head)
{
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* head = nullptr;

    insertAtEnd(head, 3);
    insertAtBeginning(head, 1);
    insertAtEnd(head, 5);
    printList(head);

    std::cout << "Keresés 3: " << (searchList(head, 3) ? "Megtalálva" : "Nem találva") << std::endl;
    std::cout << "Keresés 4: " << (searchList(head, 4) ? "Megtalálva" : "Nem találva") << std::endl;

    deleteValue(head, 3);
    printList(head);

    freeList(head);
    return 0;
}