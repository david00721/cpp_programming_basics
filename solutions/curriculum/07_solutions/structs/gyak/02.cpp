// Valósíts meg egy Book structot (title, author, year). Tárolj tömbben könyveket, és írj függvényt, ami egy adott szerző összes könyvét kiírja.
#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

void printBooksByAuthor(const Book books[], int size, const std::string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            std::cout << "Title: " << books[i].title << ", Year: " << books[i].year << std::endl;
        }
    }
}

int main() {
    Book books[5] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"1984", "George Orwell", 1949},
        {"Animal Farm", "George Orwell", 1945},
        {"Pride and Prejudice", "Jane Austen", 1813}
    };

    std::string author;
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);

    printBooksByAuthor(books, 5, author);

    return 0;
}