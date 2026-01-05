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
int sizeSearch(std::string fbe, double my_size, std::string* brand)
{
    std::ifstream fin(fbe);
    if (!fin.is_open()) {
        std::cout << "Sikertelen file-nyitás!\n";
        return 0;
    }

    int n = 0;
    fin >> n;
    if (!fin || n <= 0) {
        return 0;
    }

    bike_shoes* arr = new bike_shoes[n];

    int okCount = 0;
    int notOkCount = 0;
    int readCount = 0;

    for (int i = 0; i < n; ++i) {
        fin >> arr[i].brandName >> arr[i].lower >> arr[i].upper;
        if (!fin) break;

        arr[i].size_OK = (my_size >= arr[i].lower && my_size <= arr[i].upper);

        if (arr[i].size_OK) {
            okCount++;
        } else {
            if (brand != 0) {
                brand[notOkCount] = arr[i].brandName;
            }
            notOkCount++;
        }
        readCount++;
    }

    int result = readCount - okCount;

    delete[] arr;
    return result;
}

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