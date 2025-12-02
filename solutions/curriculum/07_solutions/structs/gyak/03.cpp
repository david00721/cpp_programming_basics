// Írj függvényt, amely kap egy Node* head láncolt listát, és visszaadja a legnagyobb értéket benne.

#include <iostream>

struct Node {
    int data;
    Node* next;
};

int findMax(Node* head) {
    if (head == nullptr) {
        throw std::invalid_argument("The list is empty.");
    }

    int maxVal = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }

    return maxVal;
}

int main() {
    // Példa használat
    Node* head = new Node{3, nullptr};
    head->next = new Node{5, nullptr};
    head->next->next = new Node{2, nullptr};
    head->next->next->next = new Node{8, nullptr};

    int maxValue = findMax(head);
    std::cout << "A legnagyobb érték a láncolt listában: " << maxValue << std::endl;

    // Felszabadítás
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}