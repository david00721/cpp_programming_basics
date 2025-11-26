#include <iostream>
using namespace std;

// 👉 **13 - Feladat közösen:** Módosítsd a fenti programot úgy, hogy csak páros pozitív számokat tároljon a listában!

// 👉 **14 - Feladat önállóan:** Egészítsd ki a programot find függvénnyel. A beolvasás után kérj be egy k értéket, és írd ki, hogy k benne van-e a listában.

struct Node {
    int value;
    Node* next;
};

void push_back(Node* &head, int x) {
    Node* newNode = new Node;
    newNode->value = x;
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

void print_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void clear_list(Node* &head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

bool find(Node* head, int k) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == k) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    int x;
    while (cin >> x && x != 0) {
        if (x > 0 && x % 2 == 0) {
            push_back(head, x);
        }
    }

    cout << "Pozitív páros számok: ";
    print_list(head);

    int k;
    cout << "Keresett érték: ";
    cin >> k;
    if (find(head, k)) {
        cout << k << " benne van a listában." << endl;
    } else {
        cout << k << " nincs benne a listában." << endl;
    }

    clear_list(head);

    return 0;
}