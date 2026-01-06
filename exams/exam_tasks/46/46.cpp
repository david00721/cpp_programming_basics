#include <iostream>
#include <string>

struct curse {
    std::string movie;
    std::string word;
    double      time;
};

// Prototype - implement this function
std::string getFirstCurse(struct curse curses[], int n);

int main()
{
    curse curses[] = {
        {"Pulp Fiction", "motherf***er", 12.4},
        {"Reservoir Dogs", "f***", 3.2},
        {"Kill Bill", "bastard", 5.8},
        {"Django Unchained", "damn", 2.9}
    };

    int n = sizeof(curses) / sizeof(curses[0]);

    std::string movie = getFirstCurse(curses, n);
    std::cout << movie << std::endl;

    // Expected output: "Django Unchained"

    return 0;
}
