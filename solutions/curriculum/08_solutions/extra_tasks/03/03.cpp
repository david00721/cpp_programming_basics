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
int colorSearch(string fbe, string* brand)
{
    ifstream file(fbe);
    if (!file) {
        cerr << "Hiba: Nem lehet megnyitni a fajlt: " << fbe << endl;
        return 0;
    }

    running_shoes shoe;
    int greenCount = 0;
    string lastBrand = "";

    while (file >> shoe.brand_name >> shoe.color1 >> shoe.color2 >> shoe.color3) {
        shoe.color_green = (shoe.color1 == "green" || shoe.color2 == "green" || shoe.color3 == "green");
        if (shoe.color_green) {
            greenCount++;
            lastBrand = shoe.brand_name;
        }
    }

    file.close();

    if (brand != nullptr) {
        *brand = lastBrand;
    }

    return greenCount;
}

int main() {
    string lastBrand;

    int greenCount = colorSearch("shoes.txt", &lastBrand);

    cout << "Green shoes count: " << greenCount << endl;
    cout << "Last brand: " << lastBrand << endl;

    return 0;
}
