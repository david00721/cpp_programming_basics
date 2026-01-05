#include <fstream>
#include <iostream>
#include <string>

// Prototype - implement this function
void isFart(std::string dataset)
{
    std::ifstream fin(dataset);
    if (!fin.is_open()) {
        std::cout << "Sikertelen file-nyitás!" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(fin, line)) {
        int sep = -1;
        for (int i = 0; i < (int)line.length(); ++i) {
            if (line[i] == ';') {
                sep = i;
                break;
            }
        }
        if (sep < 0) continue;

        std::string animal = line.substr(0, sep);
        std::string value  = line.substr(sep + 1);

        if (value == "Yes" || value == "Hell Yes") {
            std::cout << animal << " ";
        }
    }

    std::cout << std::endl;
    fin.close();
}

int main()
{
    isFart("animals.csv");

    // Expected output:
    // Baboons Giraffe Dog
    return 0;
}
