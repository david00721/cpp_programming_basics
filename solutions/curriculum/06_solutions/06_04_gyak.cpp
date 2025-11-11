#include <iostream>

// Foglalj dinamikusan egy karaktertömböt, kérj be egy szót, majd alakítsd át nagybetűssé.
int main() {
    int size;
    std::cout << "Add meg a szó hosszát: ";
    std::cin >> size;

    char* word = new char[size + 1]; // +1 a null terminátorhoz
    std::cout << "Add meg a szót: ";
    std::cin >> word;

    // Nagybetűssé alakítás
    for (int i = 0; i < size; i++) {
        word[i] = toupper(word[i]);
    }

    std::cout << "A nagybetűs szó: " << word << std::endl;

    delete[] word;
    return 0;
}
