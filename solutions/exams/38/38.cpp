#include <fstream>
#include <iostream>
#include <string>

// Prototype - implement this function
void duration(std::string fileName)
{
    std::ifstream fin(fileName.c_str());
    if (!fin.is_open())
    {
        std::cout << "Sikertelen file-nyitás!" << std::endl;
        return;
    }

    std::string line;

    // fejléc átugrás
    if (!std::getline(fin, line))
    {
        fin.close();
        return;
    }

    while (std::getline(fin, line))
    {
        // két cella, vesszővel
        int commaPos = -1;
        for (int i = 0; i < (int)line.length(); ++i)
        {
            if (line[i] == ',')
            {
                commaPos = i;
                break;
            }
        }
        if (commaPos < 0)
            continue;

        std::string t1 = line.substr(0, commaPos);
        std::string t2 = line.substr(commaPos + 1);

        if (t1.length() < 5 || t2.length() < 5)
            continue;

        // átalakítás percekké és különbség számítása
        // képlet: ÓÓ*60 + PP
        int m1 = (t1[0] - '0') * 10 + (t1[1] - '0') * 60 + (t1[3] - '0') * 10 + (t1[4] - '0');
        int m2 = (t2[0] - '0') * 10 + (t2[1] - '0') * 60 + (t2[3] - '0') * 10 + (t2[4] - '0');

        std::cout << (m2 - m1) << std::endl;
    }

    fin.close();
}

int main()
{
    duration("ido1.csv");

    /*
    Expected output:
    50
    35
    30
    59
    */

    return 0;
}
