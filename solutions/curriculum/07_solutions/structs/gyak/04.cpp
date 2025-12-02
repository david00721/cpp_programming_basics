// Írj függvényt, amely egy láncolt listát megfordít (in-place, új lista nélkül). Tipp: három pointer (prev, current, next).

#include <iostream>
struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Következő csomópont mentése
        current->next = prev; // Aktuális csomópont mutatása az előzőre
        prev = current;       // Előző frissítése az aktuálisra
        current = next;       // Aktuális frissítése a következőre
    }

    return prev; // Az új fej a fordított listában
}

int main() {
    // Példa használat
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    std::cout << "Eredeti lista: ";
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << " ";
    }
    std::cout << std::endl;

    head = reverseList(head);

    std::cout << "\nMegfordított lista: ";
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->data << " ";
    }
    std::cout << std::endl;

    // Felszabadítás
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}