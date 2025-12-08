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
int colorSearch(string fbe, string* brand);

int main() {
    string lastBrand;

    int greenCount = colorSearch("shoes.txt", &lastBrand);

    cout << "Green shoes count: " << greenCount << endl;
    cout << "Last brand: " << lastBrand << endl;

    return 0;
}
