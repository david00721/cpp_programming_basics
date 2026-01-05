#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct running_shoes {
    string brand_name;
    string color1;
    string color2;
    string color3;
    bool color_green;
};

// Prototype - implement this function
int colorSearch(std::string fbe, std::string* brand)
{
    std::ifstream fin(fbe.c_str());
    if (!fin.is_open()) {
        std::cout << "Sikertelen file-nyitás!" << std::endl;
        return 0;
    }

    int n = 0;
    fin >> n;
    if (!fin || n <= 0) {
        fin.close();
        return 0;
    }

    running_shoes* arr = new running_shoes[n];

    int greenCount = 0;

    for (int i = 0; i < n; ++i) {
        fin >> arr[i].brand_name >> arr[i].color1 >> arr[i].color2 >> arr[i].color3;

        arr[i].color_green =
            (arr[i].color1 == "green" ||
             arr[i].color2 == "green" ||
             arr[i].color3 == "green");

        if (arr[i].color_green) {
            greenCount++;
        }
    }

    if (brand != 0) {
        *brand = arr[n - 1].brand_name;
    }

    delete[] arr;
    fin.close();

    return greenCount;
}

int main() {
    string lastBrand;

    int greenCount = colorSearch("shoes.txt", &lastBrand);

    cout << "Green shoes count: " << greenCount << endl;
    cout << "Last brand: " << lastBrand << endl;

    return 0;
}
