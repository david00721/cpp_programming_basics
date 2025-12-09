#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

    int n;
    file >> n; // az első sor: sorok száma
    file.ignore(); // sortörés eldobása, csak akkor jó, ha pontosan 1 karakter van a sor végén

    running_shoes shoe;
    int greenCount = 0;
    string lastBrand = "";

    // --- 1. megoldás: >> operátorral (aktív) ---
    while (file >> shoe.brand_name >> shoe.color1 >> shoe.color2 >> shoe.color3) {
        shoe.color_green = (shoe.color1 == "green" ||
                            shoe.color2 == "green" ||
                            shoe.color3 == "green");
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

int colorSearch2(string fbe, string* brand)
{
    ifstream file(fbe);
    if (!file) {
        cerr << "Hiba: Nem lehet megnyitni a fajlt: " << fbe << endl;
        return 0;
    }

    int n;
    file >> n; // az első sor: sorok száma
    file.ignore(); // sortörés eldobása, csak akkor jó, ha pontosan 1 karakter van a sor végén

    running_shoes shoe;
    int greenCount = 0;
    string lastBrand = "";

    // --- 2. megoldás: getline és string feldolgozás ---
    string line;
    for (int i = 0; i < n; i++) {
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> shoe.brand_name >> shoe.color1 >> shoe.color2 >> shoe.color3;
        shoe.color_green = (shoe.color1 == "green" ||
                            shoe.color2 == "green" ||
                            shoe.color3 == "green");
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

    int greenCount2 = colorSearch2("shoes.txt", &lastBrand);

    cout << "Green shoes count: " << greenCount2 << endl;
    cout << "Last brand: " << lastBrand << endl;

    return 0;
}
