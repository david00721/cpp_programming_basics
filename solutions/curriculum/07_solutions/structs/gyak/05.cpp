/*
Írj programot, amely:
- láncolt listába olvas be egész számokat,
- törli az összes negatív számot,
- majd kiírja a lista tartalmát.
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void append(Node *&head, int value)
{
    Node *newNode = new Node{value, nullptr};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void removeNegatives(Node *&head)
{
    // Negatív elemek törlése a lista elejéről
    while (head != nullptr && head->data < 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Ha a lista üres lett, nincs mit tovább törölni
    Node *current = head;

    // Negatív elemek törlése a lista közepéből/végéről
    while (current && current->next)
    {
        if (current->next->data < 0)
        {
            // Negatív elem törölése
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            // Továbblépés a következő elemre
            current = current->next;
        }
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int number;
    cout << "Enter integers (end with -999):" << endl;
    while (true)
    {
        cin >> number;
        if (number == -999)
            break;
        append(head, number);
    }
    removeNegatives(head);
    cout << "List after removing negative numbers:" << endl;
    printList(head);
    return 0;
}