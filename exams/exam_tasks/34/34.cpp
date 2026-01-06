#include <fstream>
#include <iostream>
#include <string>

struct bike_shoes {
    std::string brandName;
    double lower;
    double upper;
    bool size_OK;
};

// Prototype - implement this function
int sizeSearch(std::string fbe, double my_size, std::string* brand);

int main()
{
    std::string filename = "input.txt";
    double my_size = 42.5;
    const int maxBrands = 100;
    std::string brandNames[maxBrands];

    int count = sizeSearch(filename, my_size, brandNames);
    std::cout << "Number of brands without the desired size: " << count << "\n";
    for (int i = 0; i < count; ++i) {
        std::cout << brandNames[i] << "\n";
    }

    return 0;
}