#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Prototype - implement this function
void kever(string &s);

void teszt(const string &input)
{
    string s = input;
    cout << "Eredeti szoveg: " << s << "\n";

    kever(s);

    // csak ellenőrizzük, hogy a hossza nem változott
    if (s.size() == input.size())
        cout << "Keveres OK\n\n";
    else
        cout << "HIBA: mas hosszusag!\n\n";
}

int main()
{
    teszt("abcdef");
    teszt("hello");
    teszt("12345");

    return 0;
}